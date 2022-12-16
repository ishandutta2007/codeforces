#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 100010;

int n , m;
multiset<int> G[MAX_N];
vector<int> path;
int deg[MAX_N];

void dfs( int x ){
  while( !G[x].empty() ){
    int to = *G[x].begin();
    G[x].erase( G[x].find(to) );
    G[to].erase( G[to].find(x) );
    dfs( to );
  }
  path.push_back( x );
}

int main(){

  scanf( "%d %d" , &n , &m );

  for( int i = 0; i < m; i++ ){
    int a , b;
    scanf( "%d %d" , &a , &b );
    G[a].insert( b );
    G[b].insert( a );
    deg[a]++;
    deg[b]++;
  }

  int odd = -1;
  for( int i = 1; i <= n; i++ ){
    if( deg[i] % 2 == 1 ){
      if( odd == -1 ){
	odd = i;
      } else{
	G[odd].insert( i );
	G[i].insert( odd );
	odd = -1;
	
      }
    }
  }

  /*  
  for( int i = 1; i <= n; i++ )
    for( set<int>::iterator ite = G[i].begin(); ite != G[i].end(); ite++ )
      printf( "%d\n" , *ite );
  */  
  
  dfs( 1 );

  if( path.size() % 2 == 0 ) path.push_back( path[0] );

  printf( "%d\n" , path.size()-1 );
  for( int i = 0; i < path.size()-1; i++ ){
    if( i % 2 == 0 ){
      printf( "%d %d\n" , path[i] , path[i+1] );
    } else {
      printf( "%d %d\n" , path[i+1] , path[i] );
    }
  }
  
  
  return 0;
}