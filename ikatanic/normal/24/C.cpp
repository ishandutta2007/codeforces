#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long llint;

int a[100005], b[100005];

int main( void ) {
  llint m;

  int n;
  scanf( "%d %I64lld", &n, &m );
  
  int x, y;
  scanf( "%d %d", &x, &y );

  for( int i = 0; i < n; ++i )
    scanf( "%d %d", a+i, b+i );
    
  m %= (n+n);
  for( int i = 0; i < m; ++i )
    x = 2*a[i%n] - x, y = 2*b[i%n] - y;

  printf( "%d %d\n", x, y );
  return 0;
}