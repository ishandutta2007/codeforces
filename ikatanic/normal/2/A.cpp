#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int INF = 1000000000;

vector< int > v[1002];
vector< int > t[1002];

int w[1002], wh[1002];
char s[50];
string name[1002];
map< string, int > M;

int main( void ) {
  int d, m, x, n = 0;
  scanf( "%d", &m );
  for( int i = 0; i < m; ++i ) {
    scanf( "%s %d", s, &x );    
    string a = s;
    if( M.count( a ) ) d = M[a]; else
      M[a] = n, d = n++;
    name[d] = a;
    w[d] += x;
    v[d].push_back( x );
    t[d].push_back( i );
  }

  int maks = 0;
  for( int i = 0; i < n; ++i ) {
    int s = 0, q = 0;
    while( q < w[i] ) q += v[i][s++];
    if( s == 0 ) wh[i] = 0; else
      wh[i] = t[i][s-1];
    if( w[i] > w[maks] || ( w[i] == w[maks] && wh[i] < wh[maks] ) ) maks = i;
  }
  
  printf( "%s\n", name[maks].c_str() );
  return 0;
}