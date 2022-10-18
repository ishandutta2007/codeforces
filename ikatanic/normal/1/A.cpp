#include <cstdio>

using namespace std;

int main( void ) {
  int n, m, a;
  scanf( "%d %d %d", &n, &m, &a );
  long long x = ( n+a-1 )/a, y = ( m+a-1 )/a;
  long long r = x*y;
  printf( "%I64lld\n", r );
  return 0;
}