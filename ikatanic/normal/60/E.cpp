#include <cstdio>
#include <cstring>

using namespace std;

typedef long long llint;

int mod;
const int K = 4;

struct matrix {
  int a[K][K];
  matrix() { memset( a, 0, sizeof( a ) ); };
  friend matrix operator * ( const matrix &a, const matrix &b ) {
    matrix r;
    for( int i = 0; i < K; ++i )
      for( int j = 0; j < K; ++j ) {
	llint p = 0;
	for( int k = 0; k < K; ++k )
	  p += llint( a.a[k][j] )*b.a[i][k];
	r.a[i][j] = p%mod;
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

int main(
 void ) {
  int n, w, l, d1, d2;
  llint x, y, s = 0;
  scanf( "%d %I64d %I64d %d", &n, &x, &y, &mod );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d", &w );
    if( i == 0 ) l = w;
    if( i == n-2 ) d1 = w;
    if( i == n-1 ) d2 = w;
    s += w;
  }

  if( n == 1 ) { printf( "%d\n", l%mod ); return 0; }

  matrix a, b;
  b.a[0][0] = 3%mod;
  b.a[0][1] = b.a[1][1] = b.a[2][3] = b.a[3][2] = b.a[3][3] = 1;
  
  int d = (-l-d2)%mod;
  if( d < 0 ) d += mod;
  
  a.a[0][0] = s%mod, a.a[1][0] = d, a.a[2][0] = d1%mod, a.a[3][0] = d2%mod;
  
  if( x > 0 ) a = a * pow( b, x );
  d = (-l-a.a[3][0])%mod;
  if( d < 0 ) d += mod;
  
  a.a[1][0] = d;
  if( y > 0 ) a = a * pow( b, y );

  printf( "%d\n", a.a[0][0]%mod );
  return 0;
}