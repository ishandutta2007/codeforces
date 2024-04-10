#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long llint;

const int MAXN = 707;

int e[MAXN][MAXN];
int c[MAXN][MAXN];
llint d[MAXN];

int main( void ) {
  int n, m;
  scanf( "%d %d", &n, &m );
  for( int i = 0; i < m; ++i ) {
    int a, b;
    scanf( "%d %d", &a, &b ); --a, --b;
    e[a][b] = e[b][a] = 1;
  }

  for( int i = 0; i < n; ++i )
    for( int j = i+1; j < n; ++j ) {
      c[i][j] = 0;
      for( int k = 0; k < n; ++k )
	if( e[i][k] && e[k][j] ) c[i][j]++;
      c[j][i] = c[i][j];
    }

  for( int i = 0; i < n; ++i )
    for( int j = 0; j < n; ++j )
      if( e[i][j] )
	for( int k = j+1; k < n; ++k )
	  if( e[i][k] && e[j][k] ) d[i]++;

  llint ans = 0;
  for( int i = 0; i < n; ++i )
    for( int j = i+1; j < n; ++j )
      if( e[i][j] ) {
	llint f = 0;
	for( int k = 0; k < n; ++k ) {
	  if( i == k || j == k ) continue;

	  int c1 = c[i][k], c2 = c[k][j];
	  if( e[k][j] ) c1--;
	  if( e[k][i] ) c2--;
	  //printf( "%d %d %d, %d %d\n", i, j, k, c1, c2 );

	  f += llint(c1)*c2;
	  //for( int l = 0; l < n; ++l )
	  //if( l != i && l != j && e[k][l] && e[l][i] && e[j][l] ) f--;
	}
	ans += f;
      }
  
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < n; ++j )
      if( e[i][j] ) {
	ans -= d[j];
	for( int k = 0; k < n; ++k )
	  if( e[i][k] && e[k][j] ) ans++;
      }
  ans /= 5;
  printf( "%I64d\n", ans );
  return 0;
}