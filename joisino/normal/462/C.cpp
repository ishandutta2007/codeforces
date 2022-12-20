#include "stdio.h"
#include "algorithm"

using namespace std;

typedef long long int ll;

int n;
int a[300010];

ll ans = 0;

int main(){

  scanf( "%d" , &n );
  
  for( int i = 0; i < n; i++ ){
    scanf( "%d" , &a[i] );
  }

  sort( a , a+n );

  for( int i = 0; i < n; i++ ){
    ans += (ll)a[i] * (ll)(i+2);
  }

  ans -= a[n-1];

  printf( "%I64d\n" , ans );

  return 0;
}