#include "bits/stdc++.h"

using namespace std;

const int INF = (1e9)*2;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

int a[200010];
char str[1024];

int main(){

  int n , k;
  scanf( "%d %d\n" , &n , &k );

  int nc = 0;
  for( int i = 0; i < n; i++ ){
    scanf( "%s" , str );
    if( str[0] == '?' ) a[i] = INF;
    else a[i] = atoi( str );
  }

  for( int i = n; i < n+k; i++ )
    a[i] = INF+1;
  
  bool ok = true;
  for( int i = 0; i < k; i++ ){
    int prev = -INF;
    int cnt = 0;
    for( int j = i; j < n+k; j+=k ){
      if( a[j] == INF ) cnt++;
      else {
	if( prev+cnt >= a[j] ) ok = false;
	for( int l = 1; l <= cnt; l++ ) a[j-l*k] = max( prev+cnt-l+1 , min( -cnt/2+(cnt-l) , a[j]-l ) );
	cnt = 0;
	prev = a[j];
      }
    }
  }
  
  
  if( ok ){
    for( int i = 0; i < n; i++ )
      printf( "%d%c" , a[i] , i==n-1?'\n':' ' );
  } else {
    printf( "Incorrect sequence" );
  }
  
  return 0;
}