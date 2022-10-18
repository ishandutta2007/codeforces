#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 2002;

vector< int > E[MAXN], F[MAXN];
int dad[MAXN], bio[MAXN];
int dsc[MAXN], lw[MAXN], d[MAXN];
int t, ans;

bool e[MAXN][MAXN];

int findset( int x ) { return x == dad[x] ? x : dad[x] = findset( dad[x] ); }
void merge( int x, int y ) { dad[ findset(y) ] = x; }

void dfs( int x, int d ) {
  lw[x] = dsc[x] = ++t;
  for( int i = 0; i < E[x].size(); ++i ) {
    int y = E[x][i];
    if( y == d ) continue;
    
    if( dsc[y] == -1 ) {
      dfs( y, x );
      lw[x] = min( lw[x], lw[y] );
      if( lw[y] <= dsc[x] ) merge( x, y ), ans++;
    } else
      lw[x] = min( lw[x], dsc[y] );
  }
}

int dfs2( int x, int dad ) {
  int dd = d[x];
  for( int i = 0; i < F[x].size(); ++i ) {
    int y = F[x][i];
    if( y == dad ) continue;
    d[y] = d[x] + 1;
    dfs2( y, x );
    dd = max( dd, d[y] );
  }
  d[x] = dd;
}

int solve( int x, int dad, int y ) {
  // printf( "%d %d\n", x, d[x] );

  int ans = 0;
  if( y > 0 ) {
    if( F[x].size()-(dad!=-1) > 0 ) ans++;
    d[x] = -1;
  }

  for( int i = 0; i < F[x].size(); ++i )
    if( F[x][i] != dad ) {
      if( d[ F[x][i] ] == d[x] ) ans += solve( F[x][i], x, 0 ), d[x] = -1; else
	ans += solve( F[x][i], x, 1 );
    }
  return ans;
}

int main( void ) {
  int n, m;
  scanf( "%d %d", &n, &m );
  for( int i = 0; i < m; ++i ) {
    int a, b;
    scanf( "%d %d", &a, &b ); --a, --b;
    E[a].push_back( b );
    E[b].push_back( a );
  }

  memset( dsc, -1, sizeof( dsc ) );
  for( int i = 0; i < n; ++i ) 
    dad[i] = i;

  ans = 0;
  for( int i = 0; i < n; ++i )
    if( dsc[i] == -1 ) {
      ans++;
      int c = t;
      dfs( i, -1 );
      
      vector< int > v;
      for( int j = 0; j < n; ++j ) {
	//	printf( "%d %d\n", j, dsc[j] );
	if( dsc[j] > c ) {
	  //	  printf( "%d %d\n", j, findset(j) );
	  int x = findset(j);
	  if( !bio[x] ) v.push_back( x ), bio[x] = 1;
	  for( int k = 0; k < E[j].size(); ++k ) {
	    int y = findset(E[j][k]);
	    if( y != x && e[x][y] == 0 ) {
	      F[x].push_back( y );
	      F[y].push_back( x );
	      e[x][y] = e[y][x] = 1;
	    }
	  }
	}
      }      
      //  for( int i = 0; i < v.size(); ++i ) printf( "%d\n", v[i] );

      int f = 1000000000;
      for( int i = 0; i < v.size(); ++i ) {
	d[ v[i] ] = 0;
       	dfs2( v[i], -1 );
	int fs = solve( v[i], -1, 0 );
	//	printf( "%d %d\n\n\n", v[i]+1, fs );
	f = min( f, fs );
      }
      ans += f;
    }

  printf( "%d\n", ans-1 );
  return 0;
}