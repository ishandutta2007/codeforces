#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long int ull;

const int SIZE = 3;
const ull MOD = 1000000009;
const ull B[] = { 1000000007 , 727272727 , 222277777 };

const int INF = 1e9;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

set<ull> ss[SIZE];
ull e[SIZE][600010];

char str[600010];

ull rh( string s , int t ){
  ull h = 0;
  for( int i = 0; i < s.length(); i++ )
    h = (h*B[t] + ull(s[i]))%MOD;
  return h;
}

ull h[SIZE];

int main(){

  int n , m;
  scanf( "%d %d" , &n , &m );

  
  for( int t = 0; t < SIZE; t++ ){
    e[t][0] = 1;
    for( int i = 1; i < 600010; i++ )
      e[t][i] = (e[t][i-1] * B[t])%MOD;
  }
  
  for( int i = 0; i < n; i++ ){
    scanf( "%s" , str );
    for( int t = 0; t < SIZE; t++ )
      ss[t].insert( rh( str , t ) );
  }

  for( int i = 0; i < m; i++ ){
    scanf( "%s" , str );
    int len = strlen( str );
    for( int t = 0; t < SIZE; t++ )
      h[t] = rh( str , t );
    bool ok = false;
    for( int j = 0; j < len; j++ ){
      for( char k = 'a'; k <= 'c'; k++ ){
	if( k == str[j] ) continue;
	bool res = true;
	for( int t = 0; t < SIZE; t++ ){
	  ull nh = (h[t] + (MOD*MOD - ull(str[j])*e[t][len-j-1])%MOD + (ull(k)*e[t][len-j-1])%MOD)%MOD;
	  if( ss[t].find( nh ) == ss[t].end() ) res = false;
	}
	ok |= res;
      }
    }
    if( ok ) printf( "YES\n" );
    else printf( "NO\n" );
  }
    
  
  return 0;
}