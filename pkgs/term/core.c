#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <unistd.h>

static int
lua_isatty(lua_State *L)
{
    FILE **fp = (FILE **) luaL_checkudata(L, -1, LUA_FILEHANDLE);

    lua_pushboolean(L, isatty(fileno(*fp)));
    return 1;
}

int
luaopen_term_core(lua_State *L)
{
    lua_newtable(L);
    lua_pushcfunction(L, lua_isatty);
    lua_setfield(L, -2, "isatty");

    return 1;
}
