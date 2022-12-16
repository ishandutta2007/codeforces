#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

int n , m;
int par[32][100010];
int dep[100010];
int chs[100010];

vector<int> G[100010];

int dfs( int x , int p , int d ){
  chs[x] = 1;
  par[0][x] = p;
  dep[x] = d;
  for( int i = 0; i < G[x].size(); i++ )
    if( G[x][i] != p )
      chs[x] += dfs( G[x][i] , x , d+1 );
  return chs[x];
}

void init(){
  for( int i = 1; i < 32; i++ ){
    for( int j = 0; j < n; j++ ){
      if( par[i-1][j] != -1 ) par[i][j] = par[i-1][par[i-1][j]];
      else par[i][j] = -1;
    }
  }
}

int lca( int x , int y ){
  if( dep[x] > dep[y] ) swap( x , y );
  for( int i = 31; i >= 0; i-- )
    if( par[i][y] != -1 && dep[x] <= dep[par[i][y]] ) y = par[i][y];

  if( x == y ) return x;
  
  for( int i = 31; i >= 0; i-- ){
    if( par[i][x] != par[i][y] ){
      x = par[i][x];
      y = par[i][y];
    }
  }
  return par[0][x];
}

int main(){

  scanf( "%d" , &n );
  
  for( int i = 0; i < n-1; i++ ){
    int a , b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].push_back( b );
    G[b].push_back( a );
  }

  dfs( 0 , -1 , 1 );
  init();

  scanf( "%d" , &m );

  for( int i = 0; i < m; i++ ){
    int a , b;
    scanf( "%d %d" , &a , &b ); a--; b--;

    if( dep[a] > dep[b] ) swap( a , b );

    int l = lca( a , b );
    int d = dep[a]-dep[l]+dep[b]-dep[l];
    if( d % 2 == 1 ){
      printf( "0\n" );
      continue;
    }

    if( a == b ){
      printf( "%d\n" , n );
      continue;
    }
    
    if( dep[a] == dep[b] ){
      int up = dep[a]-dep[l]-1;
      for( int j = 31; j >= 0; j-- ){
	if( up&(1<<j) ){
	  a = par[j][a];
	  b = par[j][b];
	}
      }
      printf( "%d\n" , n-chs[a]-chs[b] );
      continue;
    }
    
    int up = d/2-1;
    for( int j = 31; j >= 0; j-- )
      if( up&(1<<j) ) b = par[j][b];

    printf( "%d\n" , chs[par[0][b]]-chs[b] );
  }
  
  return 0;
}