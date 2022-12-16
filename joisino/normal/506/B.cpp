#include "stdio.h"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

const int MAX_N = 100010;
const int INF = 1000000000;

int size[MAX_N];
int par[MAX_N];

void init( int n ){
  for( int i = 0; i < n; i++ ){
    size[i] = 1;
    par[i] = i;
  }
}

int find( int x ){
  if( par[x] == x ) return x;
  return par[x] = find( par[x] );
}

void unite( int x , int y ){
  x = find(x);
  y = find(y);
  if( x == y ) return;
 
  if( size[x] < size[y] ){
    par[x] = y;
    size[y] += size[x];
  } else {
    par[y] = x;
    size[x] += size[y];
  }
}

bool same( int x , int y ){
  return find(x) == find(y);
}


int n , m;
vector<int> G[MAX_N];
set<int> is;

bool hf[MAX_N];

int used[MAX_N];


void dfs( int x , int k ){
  used[x] = k;
  for( int i = 0; i < G[x].size(); i++ ){
    int to = G[x][i];
    if( used[to] == -1 ){
      dfs( to , k );
    } else if( used[to] == k ){
      hf[k] = true;
    }
  }
  used[x] = INF;
}

int main(){

  scanf( "%d %d" , &n , &m );

  init( n );

  for( int i = 0; i < m; i++ ){
    int a , b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].push_back( b );
    unite( a , b );
  }

  fill( used , used+n , -1 );
  for( int i = 0; i < n; i++ )
    if( used[i] == -1 ) dfs( i , find(i) );

  for( int i = 0; i < n; i++ )
    is.insert( find(i) );

  int ans = 0;

  set<int>::iterator ite;
  for( ite = is.begin(); ite != is.end(); ite++ ){
    if( hf[*ite] ) ans += size[*ite];
    else ans += size[*ite]-1;
  }

  printf( "%d\n" , ans );

  return 0;
}