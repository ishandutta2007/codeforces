#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long llint;

const int MaxN = 100005;

vector< int > E[ MaxN ];
int mup[ MaxN ];
int md[ MaxN ], mu[ MaxN ], mp[ MaxN ];
int n;

void dfs_down( int x, int  dad ) {
  int c1 = 0, c2 = 0;
  for( int i = 0; i < E[x].size(); ++i ) {
    int y = E[x][i];
    if( y == dad ) {
      swap( E[x][i], E[x].back() );
      E[x].pop_back(); --i;
      continue;
    }

    dfs_down( y, x );
    if( md[y]+1 >= c1 ) c2 = c1, c1 = md[y]+1; else
      if( md[y]+1 >= c2 ) c2 = md[y]+1;
    mp[x] = max( mp[x], mp[y] );
  }
  md[x] = c1;
  mp[x] = max( mp[x], md[x] );
  mp[x] = max( mp[x], c1+c2 );
}

void dfs_up( int x, int dad ) {		      
  mup[x] = max( mup[x], mu[x] );
  int f = mu[x], fp = mup[x];
  int c1 = mu[x], c2 = 0;
  for( int i = 0; i < E[x].size(); ++i ) {
    int y = E[x][i];
    mu[y] = max( mu[y], f+1 );
    mup[y] = max( mup[y], fp );
    if( md[y]+1 >= c1 ) c2 = c1, c1 = md[y]+1; else
      if( md[y]+1 >= c2 ) c2 = md[y]+1;
    f = max( f, md[y]+1 );
    fp = max( fp, mp[y] );
    fp = max( fp, c1+c2 );
  }
  
  f = mu[x], fp = mup[x];
  c1 = mu[x], c2 = 0;
  for( int i = E[x].size()-1; i >= 0; --i ) {
    int y = E[x][i];
    mu[y] = max( mu[y], f+1 );
    mup[y] = max( mup[y], fp );
    if( md[y]+1 >= c1 ) c2 = c1, c1 = md[y]+1; else
      if( md[y]+1 >= c2 ) c2 = md[y]+1;
    f = max( f, md[y]+1 );
    fp = max( fp, mp[y] );
    fp = max( fp, c1+c2 );
  }
  for( int i = 0; i < E[x].size(); ++i )
    dfs_up( E[x][i], x );
}
  
int main( void ) {
  scanf( "%d", &n );
  for( int i = 0; i < n-1; ++i ) {
    int a, b;
    scanf( "%d %d", &a, &b ); --a, --b;
    E[a].push_back( b );
    E[b].push_back( a );
  }

  dfs_down( 0, -1 );
  dfs_up( 0, -1 );

  llint ans = 0;
  for( int x = 0; x < n; ++x ) {
    int c1 = mu[x], c2 = 0, c3 = 0, f = mup[x];
    int p1 = 0, p2 = 0;
    for( int i = 0; i < E[x].size(); ++i ) {
      int y = E[x][i];
      if( md[y]+1 >= c1 ) c3 = c2, c2 = c1, c1 = md[y]+1; else
	if( md[y]+1 >= c2 ) c3 = c2, c2 = md[y]+1; else
	  if( md[y]+1 >= c3 ) c3 = md[y]+1;
      if( mp[y] >= p1 ) p2 = p1, p1 = mp[y]; else
	if( mp[y] >= p2 ) p2 = mp[y];
    }

    for( int i = 0; i < E[x].size(); ++i ) {
      f = mup[x];
      int y = E[x][i];
      if( mp[y] == p1 ) f = max( f, p2 ); else f = max( f, p1 );
      if( md[y]+1 == c1 ) f = max( f, c2+c3 ); else
	if( md[y]+1 == c2 ) f = max( f, c1+c3 ); else
	  if( md[y]+1 == c3 ) f = max( f, c1+c2 );

      ans = max( ans, llint(f)*mp[y] );
    }
  }
  printf( "%lld\n", ans );
  return 0;
}