#include <cstdio>
#include <algorithm>

using namespace std;

int prime( int x ) {
  for( int i = 2; i*i <= x; ++i )
    if( x%i == 0 ) return 0;
  return 1;
}

int main( void ) {
  int n, k;
  scanf( "%d %d", &n, &k );
  
  int last = -1, ans = 0;
  for( int i = 2; i <= n; ++i )
    if( prime( i ) ) {
      if( last != -1 && i+last+1 <= n && prime( i+last+1 ) ) ans++;
      last = i;
    }

  if( ans >= k ) puts( "YES" ); else
    puts( "NO" );
  return 0;
}