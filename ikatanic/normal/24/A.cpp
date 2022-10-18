#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int g[105];
int e[105][2];
int c[105][2];

int dfs( int x, int y ) {
  if( x == 0 ) return 0;
  if( e[x][0] == y ) return c[x][1] + dfs( e[x][1], x );
  return c[x][0] + dfs( e[x][0], x );
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i ) {
    int a, b, w;
    scanf( "%d %d %d", &a, &b, &w );
    --a, --b;
    e[a][ g[a] ] = b;
    c[a][ g[a] ] = 0;
    e[b][ g[b] ] = a;
    c[b][ g[b] ] = w;
    g[a]++, g[b]++;
  }

  int ans = min( dfs( e[0][0], 0 ) + c[0][0], dfs( e[0][1], 0 ) + c[0][1] );
  printf( "%d\n", ans );
  return 0;
}