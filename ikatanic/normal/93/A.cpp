#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int solve( int n, int m, int a, int b ) {
  int A = a%m, B = b%m, ra = a/m, rb = b/m;

  if( A == 0 && ( B == m-1 || b == n-1 ) ) return 1;

  if( rb-ra == 0 ) return 1;
  if( rb-ra == 1 ) return 2;
  if( B+1 == A ) return 2;
  if( A == 0 || B == m-1 || b == n-1 ) return 2;
  return 3;
}

int main( void ) {
  int n, m, a, b;
  scanf( "%d %d %d %d", &n, &m, &a, &b ); --a, --b;
  int ans = solve( n, m, a, b );
  printf( "%d\n", ans );
  return 0;
}