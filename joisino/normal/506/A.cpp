#include "stdio.h"
#include "algorithm"
#include "vector"
#include "string.h"

using namespace std;

const int INF = 1e9;

int gem[30010] = {};
int n , d;

int dp[30010][600];

int main(){

  scanf( "%d %d" , &n , &d );

  for( int i = 0; i < n; i++ ){
    int p;
    scanf( "%d" , &p );
    gem[p]++;
  }

  for( int i = 0; i < 30010; i++ )
    for( int j = 0; j < 600; j++ )
      dp[i][j] = -INF;

  int ans = gem[d];
  dp[d][300] = gem[d];
  for( int i = d; i < 30010; i++ ){
    for( int j = 0; j < 600; j++ ){
      if( dp[i][j] < 0 ) continue;
      for( int k = -1; k <= 1; k++ ){
	int next = i + (j-300+d) + k;
	if( i < next && next <= 30000 && 0 <= j+k && j+k < 600 ){
	  dp[next][j+k] = max( dp[next][j+k] , dp[i][j] + gem[next] );
	  ans = max( ans , dp[next][j+k] );
	}
      }
    }
  }
  
  printf( "%d\n" , ans );
    
  return 0;
}