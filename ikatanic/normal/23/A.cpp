#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

set< string > S;

char a[105];

int main( void ) {
  scanf( "%s", a );
  int n = strlen( a ), ans = 0;
  for( int i = 0; i < n; ++i ) {
    string s = "";
    for( int j = i; j < n; ++j ) {
      s.push_back( a[j] );
      if( S.count( s ) ) ans = max( ans, (int)s.size() );
      S.insert( s );
    }
  }

  printf( "%d\n", ans );
  return 0;
}