#include "stdio.h"
#include "vector"
#include "algorithm"
#include "utility"

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

int a[100010];
int n;

ll v;

ll ans = 0;

int main(){

  scanf( "%d" , &n );

  for( int i = 0; i < n; i++ ){
    scanf( "%d" , &a[i] );
  }

  sort( a , a+n );

  for( int i = n-2; i >= 0; i-- ){
    if( a[i] == a[i+1] || a[i] == a[i+1]-1 ){
      if( v == 0 ) v = a[i];
      else {
	ans += v*a[i];
	v = 0;
      }
      a[i] = -1;
    }
  }
  
  printf( "%I64d\n" , ans );
  
  return 0;
}