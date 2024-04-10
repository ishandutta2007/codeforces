#include "bits/stdc++.h"

using namespace std;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

typedef vector<int> vec;

char str[2048];
int n;

bool check( int a , int b ){
  for( int i = a; i <= a+b*4; i+=b ){
    if( i >= n ) return false;
    if( str[i] != '*' ) return false;
  }
  return true;
}

int main(){

  scanf( "%d" , &n );
  scanf( "%s" , str );
  
  bool ans = false;
  for( int i = 0; i < n; i++ )
    for( int j = 1; j < n; j++ )
      ans |= check( i , j );

  if( ans ) printf( "yes\n" );
  else printf( "no\n" );
  
  return 0;
}