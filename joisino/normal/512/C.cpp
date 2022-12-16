#include "stdio.h"
#include "algorithm"
#include "vector"
#include "string.h"

using namespace std;

const int INF = 1000000000;


struct edge{ int to , cap , rev; };

const int MAX_V = 310;
struct MINFLOW{
  vector<edge> G[MAX_V];
  bool used[MAX_V];

  void add_edge( int from , int to , int cap ){
    G[from].push_back( (edge){ to , cap , G[to].size() } );
    G[to].push_back( (edge){ from , 0 , G[from].size()-1 } );
  }

  int dfs( int v , int t , int f ){
    if( v == t ) return f;
    used[v] = true;
    for( int i = 0; i < G[v].size(); i++ ){
      edge &e = G[v][i];
      if( !used[e.to] && e.cap > 0 ){
	int d = dfs( e.to , t , min( f , e.cap ) );
	if( d > 0 ){
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }

  int min_flow( int s , int t ){
    int flow = 0;
    while( 1 ){
      memset( used , 0 , sizeof( used ) );
      int f = dfs( s , t , INF );
      if( f == 0 ) return flow;
      flow += f;
    }
  }
};

const int PRIME_N = 20000;
bool isnprime[PRIME_N] = {};
vector<int> ps;
bool isprime( int x ){
  if( *lower_bound( ps.begin() , ps.end() , x ) == x ) return true;
  return false;
}

int a[310];

MINFLOW mf;

vector<int> G[310];
vector<int> ans[310];
bool used[310] = {};

void dfs( int x , int c ){
  used[x] = true;
  ans[c].push_back( x );
  for( int i = 0; i < G[x].size(); i++ ){
    if( !used[ G[x][i] ] ){
      dfs( G[x][i] , c );
    }
  }
}


int main(){

  for( int i = 2; i < PRIME_N; i++ ){
    if( !isnprime[i] ){
      ps.push_back( i );
      for( int j = i*2; j < PRIME_N; j += i )
	isnprime[j] = true;
    }
  }

  int n;
  scanf( "%d" , &n );


  for( int i = 0; i < n; i++ )
    scanf( "%d" , &a[i] );

  int s = n;
  int t = n+1;
  for( int i = 0; i < n; i++ ){
    if( a[i] % 2 == 1 ) mf.add_edge( s , i , 2 );
    else mf.add_edge( i , t , 2 );
  }

  for( int i = 0; i < n; i++ )
    for( int j = 0; j < n; j++ )
      if( isprime( a[i]+a[j] ) && a[i] % 2 == 1 ) mf.add_edge( i , j , 1 );



  int f = mf.min_flow( s , t );

  if( f != n ){
    printf( "Impossible\n" );
    return 0;
  }

  for( int i = 0; i <= n; i++ ){
    if( a[i] % 2 == 0 ) continue;
    for( int j = 0; j < mf.G[i].size(); j++ ){
      edge &e = mf.G[i][j];
      if( e.cap == 0 ){
	G[i].push_back( e.to );
	G[e.to].push_back( i );
      }
    }
  }

  int c = 0;
  for( int i = 0; i < n; i++ ){
    if( !used[i] ){
      dfs( i , c );
      c++;
    }
  }

  printf( "%d\n" , c );
  for( int i = 0; i < c; i++ ){
    printf( "%d" , ans[i].size() );
    for( int j = 0; j < ans[i].size(); j++ )
      printf( " %d" , ans[i][j]+1 );
    printf( "\n" );
  }

  return 0;
}