#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int l[10][10];
int dist[10][10];
queue< int > Q;
vector< string > v;

int main( void ) {
  char a[10], b[10];
  scanf( "%s", a );
  scanf( "%s", b );

  int y1 = a[0]-'a', x1 = a[1]-'1';
  int y2 = b[0]-'a', x2 = b[1]-'1';

  memset( dist, 63, sizeof( dist ) );
  dist[x1][y1] = 0;

  Q.push( x1 ); Q.push( y1 );
  while( !Q.empty() ) {
    int x = Q.front(); Q.pop();
    int y = Q.front(); Q.pop();

    for( int i = 0; i < 8; ++i ) {
      int X = x+dx[i], Y = y+dy[i];
      if( X < 0 || Y < 0 || X >= 8 || Y >= 8 ) continue;
      if( dist[x][y]+1 >= dist[X][Y] ) continue;

      dist[X][Y] = dist[x][y]+1, l[X][Y] = i;
      Q.push( X ); Q.push( Y );
    }
  }

  printf( "%d\n", dist[x2][y2] );
  while( x2 != x1 || y2 != y1 ) {
    string s = "";
    int fx = dx[ l[x2][y2] ], fy = dy[ l[x2][y2] ];
    if( fy == -1 ) s = s + "L";
    if( fy == +1 ) s = s + "R";
    if( fx == -1 ) s = s + "D";
    if( fx == +1 ) s = s + "U";

    x2 -= fx, y2 -= fy;
    v.push_back( s );
  }

  for( int i = v.size()-1; i >= 0; --i )
    puts( v[i].c_str() );
  return 0;
}