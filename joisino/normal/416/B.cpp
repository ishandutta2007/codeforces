#include "stdio.h"
#include "algorithm"

using namespace std;

int t[50010][10] = {};
int dp[50010][10] = {};


int main(){
  FILE *fp = stdin;//fopen( "input.txt" , "r" );

  int m , n;
  fscanf( fp , "%d %d" , &m , &n );


  for( int i = 1; i <= m; i++ ){
    for( int j = 1; j <= n; j++ ){
      fscanf( fp , "%d" , &t[i][j] );
    }
  }

  for( int i = 1; i <= m; i++ ){
    for( int j = 1; j <= n; j++ ){
      dp[i][j] = max( dp[i][j-1] , dp[i-1][j] ) + t[i][j];
    }
  }

  for( int i = 1; i <= m; i++ )
    printf( "%d%c" , dp[i][n] , i == m ? '\n' : ' ' );

  return 0;
}