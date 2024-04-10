#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxD = 100;
const int BASE = 100000000;

struct bignum {
  int a[ MaxD ], n;
  bignum() { n = 0; };
  bignum( int x ) {
    n = 0;
    while( x > 0 ) a[n++] = x%BASE, x /= BASE;
  };

  friend bignum operator + ( const bignum &a, const bignum &b ) {
    bignum r;
    r.n = max( a.n, b.n );
    int tmp = 0;
    for( int i = 0; i < r.n; ++i ) {
      r.a[i] = tmp;
      if( i < a.n ) r.a[i] += a.a[i];
      if( i < b.n ) r.a[i] += b.a[i];
      if( r.a[i] >= BASE ) tmp = 1, r.a[i] -= BASE; else
	tmp = 0;
    }
    if( tmp ) r.a[r.n++] = 1;
    return r;
  }
  
  void print() {
    if( n == 0 ) { n = 1; a[0] = 0; }
    printf( "%d", a[n-1] );
    for( int i = n-2; i >= 0; --i )
      printf( "%08d", a[i] );
    putchar( '\n' );
  }
};

char s[5005][10];
int x[5005];
int bio[5005];
int g[5005];

bool ima[2002];
int m = 0, cookie;

void solve( int a, int b ) {
  cookie++;
  int p = -1, l, r;
  for( int i = a; i < b; ++i )
    if( s[i][0] == 'w' ) bio[ x[i] ] = cookie, g[ x[i] ] = i; else
      if( bio[ x[i] ] == cookie && x[i] > p ) p = x[i], l = g[ x[i] ], r = i;
  if( p == -1 ) return;
  
  ima[p] = 1;
  if( p > m ) m = p;

  solve( a, l );
  solve( r+1, b );
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i )
    scanf( "%s %d", s[i], x+i );

  solve( 0, n );

  bignum ans = 0, pw = 1;
  for( int i = 0; i <= m; ++i ) {
    if( ima[i] ) ans = ans + pw;
    pw = pw + pw;
  }

  ans.print();
  return 0;
}