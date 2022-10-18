#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100005;

int a[MAXN];
map< int, int > M;
set< int, greater< int > > S;

void add( int x, int k ) {
  int t = ( M[x] += k );
  if( t == 1 ) S.insert( x ); else
    if( t-k == 1 ) S.erase( x );
}

int main( void ) {
  int n, k;
  scanf( "%d %d", &n, &k );
  for( int i = 0; i < n; ++i )
    scanf( "%d", a+i );

  for( int i = 0; i < k-1; ++i ) add( a[i], 1 );
  for( int i = 0; i+k <= n; ++i ) {
    add( a[i+k-1], 1 );
    if( S.size() ) printf( "%d\n", *S.begin() ); else
      puts( "Nothing" );
    add( a[i], -1 );
  }

  return 0;
}