#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair< int, int > par;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

char s[222];
char a[222][222];
int d[222][222];
queue< int > Q;

int main( void ) {
  scanf( "%s", s );
  int n = strlen( s );

  int ok = 1, x = 105, y = 105;
  a[x][y] = 1;
  for( int i = 0; i < n; ++i ) {
    if( s[i] == 'L' ) --x;
    if( s[i] == 'R' ) ++x;
    if( s[i] == 'U' ) ++y;
    if( s[i] == 'D' ) --y;
    a[x][y] = 1;
  }

  memset( d, 63, sizeof( d ) );
  Q.push( 105 ), Q.push( 105 );
  d[105][105] = 0;

  while( !Q.empty() ) {
    int x = Q.front(); Q.pop();
    int y = Q.front(); Q.pop();

    for( int i = 0; i < 4; ++i ) {
      int X = x+dx[i], Y = y+dy[i];
      if( d[x][y]+1 >= d[X][Y] || a[X][Y] == 0 ) continue;
      d[X][Y] = d[x][y]+1;
      Q.push( X ), Q.push( Y );
    }
  }

  if( d[x][y] == n ) puts( "OK" ); else
    puts( "BUG" );
  return 0;
}