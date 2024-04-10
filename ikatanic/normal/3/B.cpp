#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

const int MaxN = 1000002;

int t[ MaxN ];
int a[ MaxN ];
int p1[ MaxN ], p2[ MaxN ];
int s1[ MaxN ], s2[ MaxN ];

int cmp( const int &x, const int &y ) { return a[x] != a[y] ? a[x] > a[y] : x < y; }

int main( void ) {
  int n, v, c1 = 0, c2 = 0;
  scanf( "%d %d", &n, &v );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d %d", t+i, a+i );
    if( t[i] == 2 ) p1[ c1++ ] = i;
    if( t[i] == 1 ) p2[ c2++ ] = i;
  }

  if( c1 > 0 ) sort( p1, p1+c1, cmp );
  if( c2 > 0 ) sort( p2, p2+c2, cmp );

  for( int i = 1; i <= c1; ++i )
    s1[i] = s1[i-1] + a[ p1[i-1] ];
  for( int i = 1; i <= c2; ++i )
    s2[i] = s2[i-1] + a[ p2[i-1] ];

  int ans = -1, q = 0, f = 0;
  for( int i = 0; i <= c1 && i*2 <= v; ++i ) {
    int d = min( v-i*2, c2 );
    int s = s1[i] + s2[d];
    if( s > ans ) ans = s, q = i, f = d;
  }

  printf( "%d\n", ans );
  
  int ok = 0;
  for( int i = 0; i < q; ++i ) {
    if( ok ) putchar( ' ' );
    printf( "%d", p1[i]+1 );
    ok = 1;
  }

  for( int i = 0; i < f; ++i ) {
    if( ok ) putchar( ' ' );
    printf( "%d", p2[i]+1 );
    ok = 1;
  }
  putchar( '\n' );
  return 0;
}