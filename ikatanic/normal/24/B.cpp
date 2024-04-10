#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

int pt[] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };

char s[55];
map< string, int > P[55];

int cmp1( const string &a, const string &b ) {
  for( int i = 0; i < 51; ++i )
    if( P[i][a] != P[i][b] ) return P[i][a] > P[i][b];
  return 1;
}

vector< string > v;
int main( void ) {
  int m;
  scanf( "%d", &m );
  for( int c = 0; c < m; ++c ) {
    int n;
    scanf( "%d", &n );

    for( int i = 1; i <= n; ++i ) {
      scanf( "%s", s );
      string a = s;
      v.push_back( a );
      if( P[i].count( a ) == 0 ) P[i][a] = 0;
      if( P[0].count( a ) == 0 ) P[0][a] = 0;

      P[i][a]++;
      if( i <= 10 ) P[0][a] += pt[i-1];
    }
  }
  
  for( int j = 0; j < 51; ++j )
    for( int i = 0; i < v.size(); ++i )
      if( P[j].count( v[i] ) == 0 ) P[j][ v[i] ] = 0;
  
  string w1 = v[0], w2 = v[0];
  for( int i = 0; i < v.size(); ++i ) {
    if( cmp1( v[i], w1 ) ) w1 = v[i];
    if( P[1][ v[i] ] > P[1][w2] || ( P[1][ v[i] ] == P[1][w2] && cmp1( v[i], w2 ) ) ) w2 = v[i];
  }
  
  puts( w1.c_str() );
  puts( w2.c_str() );
  return 0;
}