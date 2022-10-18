#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int get( int x, int base ) {
  int sum = 0;
  while( x > 0 ) {
    sum += x%base;
    x /= base;
  }
  return sum;
}

inline int gcd( int a, int b ) { return !b ? a : gcd( b, a%b ); }

int main( void ) {
  int n, A, B;
  scanf( "%d", &n );
  A = 0, B = n-2;
  for( int i = 2; i < n; ++i )
    A += get( n, i );
  int g = gcd( A, B );
  A /= g, B /= g;
  printf( "%d/%d\n", A, B );
  return 0;
}