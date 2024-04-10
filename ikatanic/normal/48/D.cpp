#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector< int > E[MAXN];
int ans[MAXN];

int main( void ) {
  int n, x;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d", &x );
    E[--x].push_back( i );
  }

  int c = 0;
  for( int i = MAXN-1; i >= 0; --i ) {
    if( E[i].size() < c ) { puts( "-1" ); return 0; }
    for( int j = 0; j < E[i].size(); ++j )
      ans[ E[i][j] ] = j;
    c = E[i].size();
  }

  printf( "%d\n", c );
  for( int i = 0; i < n; ++i )
    printf( "%d ", ans[i]+1 );
  return 0;
}