#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;

const int mod = 1000000007;

int pow( int a, int b ) {
  if( b == 0 ) return 1;
  if( b&1 ) return (llint(a)*pow(a,b-1))%mod;
  llint t = pow( a, b/2 );
  return (t*t)%mod;
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  
  llint ans = 1;
  for( int i = 1; i < 2*n; ++i )
    ans = ( llint(ans)*i )%mod;
  for( int i = 1; i <= n; ++i ) {
    llint inv = pow( i, mod-2 );
    ans = ( ans*inv )%mod;
    if( i < n ) ans = ( ans*inv )%mod;
  }

  ans = ( 2*ans - n + mod )%mod;
  printf( "%d\n", ans );
  return 0;
}