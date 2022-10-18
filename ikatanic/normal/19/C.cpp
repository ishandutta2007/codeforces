#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair< int, int > par;
#define a first
#define b second

typedef long long llint;

const int MaxN = 100005;
const int K = 7;

int N[] = { 143, 9973, 1993, 10007, 14471, 7777, 6666 };

int a[ MaxN ];
llint pw[K][ MaxN ];
llint H[K][ MaxN ];

int P[ MaxN ], n;
map< int, int > M;
vector< int > v[ MaxN ];

int check( int a, int b, int c ) {
  if( a+c > n || b+c > n ) return 0;
  for( int i = 0; i < K; ++i )
    if( H[i][a+c]-H[i][a]*pw[i][c] != H[i][b+c]-H[i][b]*pw[i][c] ) return 0;
  return 1;
}

vector< par > w;
int cmp( const par &a, const par &b ) {
  if( a.b-a.a != b.b-b.a ) return a.b-a.a < b.b-b.a;
  return a.a < b.a;
}

int main( void ) {
  for( int i = 0; i < K; ++i ) {
    pw[i][0] = 1;
    for( int j = 1; j < MaxN; ++j )
      pw[i][j] = pw[i][j-1]*N[i];
  }

  int c = 1;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d", a+i );
    if( !M.count( a[i] ) ) P[c] = a[i], M[ a[i] ] = c++;
    a[i] = M[ a[i] ];
  }
  for( int i = n-1; i >= 0; --i )
    v[ a[i] ].push_back( i );

  for( int i = 0; i < K; ++i ) {
    H[i][0] = 1;
    for( int j = 1; j <= n; ++j )
      H[i][j] = H[i][j-1]*N[i] + a[j-1];
  }
  
  int last = 0;
  for( int i = 0; i < n; ++i ) {
    int x = a[i], o = -1;
    for( int j = v[x].size()-2; j >= 0; --j )
      if( check( i, v[x][j], v[x][j]-i ) ) { o = v[x][j]; break; }
    v[x].pop_back();
    if( o != -1 ) w.push_back( make_pair( i, o ) );
  }

  sort( w.begin(), w.end(), cmp );
  for( int i = 0; i < w.size(); ++i )
    if( w[i].a >= last ) last = w[i].b;

  printf( "%d\n", n-last );
  for( int i = last; i < n; ++i ) {
    if( i > last ) putchar( ' ' );
    printf( "%d", P[a[i]] );
  }
  putchar( '\n' );
  return 0;
}