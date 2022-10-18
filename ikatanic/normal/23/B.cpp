#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main( void ) {
  int t;
  scanf( "%d", &t );
  for( ; t; --t ) {
    int n;
    scanf( "%d", &n );
    printf( "%d\n", max( 0, n-2 ) );
  }
  return 0;
}