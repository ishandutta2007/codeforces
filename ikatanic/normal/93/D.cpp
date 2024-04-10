#include <cstdio>
#include <cstring>

using namespace std;

typedef long long llint;

const int mod = 1000000007;
const int K = 32;

struct matrix {
  int a[K][K];
  matrix() { memset( a, 0, sizeof( a ) ); };
  friend matrix operator * ( const matrix &a, const matrix &b ) {
    matrix r;
    for( int i = 0; i < K; ++i )
      for( int j = 0; j < K; ++j ) {
	llint p = 0;
	for( int k = 0; k < K; ++k )
	  p = ( p + llint( a.a[k][j] )*b.a[i][k] )%mod;
	r.a[i][j] = p;
      }
    return r;
  }
};

matrix pow( matrix a, llint b ) {
  if( b == 1 ) return a;
  if( b&1 ) return a*pow( a, b-1 );
  a = pow( a, b/2 );
  return a*a;
}

int inv;

int calc( int n ) {
  if( n <= 0 ) return 0;
  if( n == 1 ) return 8;

  matrix a, b;
  for( int i = 0; i < 4; ++i )
    for( int j = 0; j < 4; ++j ) {
      if( i == j || i == (j^1) ) continue;
      a.a[i*4+j][0] = 1;
      a.a[i*4+j+16][0] = 1;

      b.a[i*4+j+16][i*4+j+16] = 1;
      for( int k = 0; k < 4; ++k ) {
	if( j == k || j == (k^1) ) continue;
	if( i == 3 && j == 0 && k == 2 ) continue;
	if( i == 2 && j == 0 && k == 3 ) continue;
	b.a[j*4+k][i*4+j] = 1;
	b.a[j*4+k+16][i*4+j] = 1;
      }
    }

  if( n > 2 ) {
    b = pow( b, n-2 );
    a = a*b;
  }

  int ans = 8;
  for( int i = 16; i < K; ++i ) {
    ans += a.a[i][0];
    if( ans >= mod ) ans -= mod;
  }
  
  return ans;
}
  
int get( int l, int r ) {
  if( l > r ) return 0;
  if( l <= 1 ) return get( l+1, r );

  int a1 = ( calc(r) - calc(l-1) )%mod;
  int a2 = ( calc((r+1)/2) - calc(((l+2)/2)-1) )%mod;
  if( a2 < 0 ) a2 += mod;
  if( a1 < 0 ) a1 += mod;
  a1 = ( a1 + a2 )%mod;
  a1 = ( a1*llint(inv) )%mod;
  return a1;
}

int main( void ) {
  inv = 1;
  int c = mod-2, x = 2;
  for( int i = 0; i < 30; ++i ) {
    if( c&(1<<i) ) inv = ( llint(inv)*x )%mod;
    x = ( llint(x)*x )%mod;
  }

  int l, r;
  scanf( "%d %d", &l, &r );
  int ans = get( l, r );
  if( l == 1 ) ans = ( ans+4 )%mod;

  printf( "%d\n", ans );
  return 0;
}