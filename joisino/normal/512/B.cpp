#include "stdio.h"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

const int INF = 1000000000;

const int PRIME_N = 50000;
bool isnprime[50000];

int l[310];
int c[310];

int dp[1<<11];

int main(){

  vector<int> ps;
  for( int i = 2; i < PRIME_N; i++ ){
    if( !isnprime[i] ){
      ps.push_back( i );
      for( int j = i*2; j < PRIME_N; j += i )
	isnprime[i] = true;
    }
  }

  int n;
  scanf( "%d" , &n );

  for( int i = 0; i < n; i++ )
    scanf( "%d" , &l[i] );

  for( int i = 0; i < n; i++ )
    scanf( "%d" , &c[i] );

  
  int ans = INF;
  for( int i = 0; i < n; i++ ){
    vector<int> so;
    for( int j = 0; j < ps.size(); j++ ){
      if( l[i] % ps[j] == 0 ) so.push_back( ps[j] );
      while( l[i] % ps[j] == 0 ) l[i] /= ps[j];
    }
    if( l[i] != 1 ) so.push_back( l[i] );

    for( int j = 0; j < 1<<so.size(); j++ )
      dp[j] = INF;
    dp[0] = c[i];

    for( int j = i+1; j < n; j++ ){
      int res = 0;
      for( int k = 0; k < so.size(); k++ ){
	if( l[j] % so[k] != 0 )
	  res |= 1<<k;
      }
      for( int k = (1<<so.size())-1; k >= 0; k-- ){
	dp[k|res] = min( dp[k|res] , dp[k]+c[j] );
      }
    }

   
    ans = min( ans , dp[(1<<so.size())-1] );

  }

  if( ans != INF ) printf( "%d\n" , ans );
  else printf( "-1\n" );

  return 0;
}