#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

int d[200010];
ll s;

int main(){

  int n;
  ll a;
  scanf( "%d %I64d" , &n , &a );
  
  for( int i = 0; i < n; i++ )
    scanf( "%d" , &d[i] );

  for( int i = 0; i < n; i++ )
    s += d[i];

  for( int i = 0; i < n; i++ ){
    int lb = max( ll(1) , a-(s-d[i]) );
    int ub = min( a-n+1 , ll(d[i]) );
    //printf( "%d %d\n" , lb , ub );
    printf( "%d%c" , d[i]-(ub-lb+1) , i==n-1?'\n':' ' );
  }

  
  return 0;
}