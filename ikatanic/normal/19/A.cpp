#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>

using namespace std;

int f[55], d[55], s[55];
int g[55];

char ss[1000];
string a[55];

map< string, int > M;

int cmp( const int &a, const int &b ) {
  if( f[a] != f[b] ) return f[a] > f[b];
  if( d[a] != d[b] ) return d[a] > d[b];
  return s[a] > s[b];
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i ) {
    scanf( "%s", ss );
    a[i] = ss;
    M[a[i]] = i;
    g[i] = i;
  }

  int m = ( n*(n-1) )/2;
  for( int i = 0; i < m; ++i ) {
    int X, Y;
    scanf( "%s %d:%d", ss, &X, &Y );
    string x, y;
    
    int p = 0, l = strlen( ss );
    while( ss[p] != '-' ) x.push_back( ss[p++] ); p++;
    while( p < l ) y.push_back( ss[p++] );
    
    int A = M[x], B = M[y];

    if( X > Y ) f[A] += 3;
    if( X < Y ) f[B] += 3;
    if( X == Y ) f[A]++, f[B]++;
    
    s[A] += X, s[B] += Y;
    d[A] += X-Y, d[B] += Y-X;
  }

  sort( g, g + n, cmp );
  
  vector< string > v;
  for( int i = 0; i < (n/2); ++i )
    v.push_back( a[ g[i] ] );

  sort( v.begin(), v.end() );
  for( int i = 0; i < v.size(); ++i )
    puts( v[i].c_str() );
  return 0;
}