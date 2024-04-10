#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;
 
int c[10];
int f[10];

int main( void ) {
  int n;
  scanf( "%d", &n );
  for( int i = 1; i <= n; ++i )
    c[i%9]++;
  
  llint ans = 0;
  for( int i = 1; i <= n; ++i ) {
    for( int j = 0; j < 9; ++j )
      f[j] = c[j];

    for( int j = 1; i*j <= n; ++j )
      ans += c[ (i*j)%9 ]-1, f[j%9]--;

    for( int j = 0; j < 9; ++j )
      ans += llint( c[ ( i*j )%9 ] )*f[j];
  }

  printf( "%I64lld\n", ans );
  return 0;
}