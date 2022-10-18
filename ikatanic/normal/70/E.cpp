#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200;
const int inf = 1000000000;

vector< int > E[MAXN];
int g[MAXN][MAXN];
int f[MAXN][MAXN];
int fr[MAXN][MAXN];
int gr[MAXN][MAXN];
int gj[MAXN][MAXN];

int a[MAXN], as[MAXN];
int n, k;

int solve( int x, int dad ) {
  for( int i = 0; i < E[x].size(); ++i )
    if( E[x][i] == dad ) { E[x].erase( E[x].begin() + i ); break; }
  for( int i = 0; i < E[x].size(); ++i )
    solve( E[x][i], x );

  f[x][0] = k;
  for( int i = 0; i < E[x].size(); ++i )
    f[x][0] += g[ E[x][i] ][1];
  fr[x][0] = x;

  int q = f[x][0], fq = x, sj = 0;
  for( int j = 1; j < n; ++j ) {
    f[x][j] = inf;
    g[x][j] = q, gr[x][j] = fq, gj[x][j] = sj;

    int s = a[j];
    for( int i = 0; i < E[x].size(); ++i )
      s += g[ E[x][i] ][j + 1];
    
    if( s < g[x][j] ) g[x][j] = s, gr[x][j] = -1;

    for( int i = 0; i < E[x].size(); ++i ) {
      int w = s - g[ E[x][i] ][j + 1] + f[ E[x][i] ][j - 1];
      if( w < f[x][j] ) f[x][j] = w, fr[x][j] = E[x][i];
      if( w < q ) q = w, fq = E[x][i], sj = j;
    }
  }
}
 
int recon( int x, int j, int z, char c ) {
  if( c == 'f' ) {
    int q = x;
    if( fr[x][j] != x ) q = recon( fr[x][j], j - 1, z, 'f' );
    as[x] = q;
    for( int i = 0; i < E[x].size(); ++i )
      if( E[x][i] != fr[x][j] ) recon( E[x][i], j + 1, q, 'g' );
    return q;
  }
  
  if( gr[x][j] == -1 ) {
    as[x] = z;
    for( int i = 0; i < E[x].size(); ++i )
      recon( E[x][i], j + 1, z, 'g' );
    return z;
  }

  int q = x;
  if( gr[x][j] != x ) q = recon( gr[x][j], gj[x][j] - 1, z, 'f' );
  as[x] = q;
  for( int i = 0; i < E[x].size(); ++i )
    if( E[x][i] != gr[x][j] ) recon( E[x][i], gj[x][j] + 1, q, 'g' );
}

int main( void ) {
  scanf( "%d %d", &n, &k );
  for( int i = 1; i < n; ++i )
    scanf( "%d", a+i );
  
  for( int i = 0; i < n-1; ++i ) {
    int a, b;
    scanf( "%d %d", &a, &b ); --a, --b;
    E[a].push_back( b );
    E[b].push_back( a );
  }

  solve( 0, -1 );

  int ans = f[0][0], gg = 0;
  for( int i = 0; i < n; ++i )
    if( f[0][i] < ans ) ans = f[0][i], gg = i;

  recon( 0, gg, 0, 'f' );
  printf( "%d\n", ans );
  for( int i = 0; i < n; ++i ) {
    if( i ) putchar( ' ' );
    printf( "%d", as[i] + 1 );
  }
  putchar( '\n' );
  return 0;
}