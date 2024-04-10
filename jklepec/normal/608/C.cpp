#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int INF = 1e9;

map< int, int > sam, cnt;
vector< point > v;
set< int > s;

int main() {
   int n; cin >> n;
   for( int i = 0; i < n; ++i ) {
      int x, y; cin >> x >> y;
      v.push_back( point( x, y ) );
   }
   sort( v.begin(), v.end() );
   s.insert( -INF );
   int sol = INF;
   for( int i = 0; i < n; ++i ) {
      int x = v[ i ].first, pw = v[ i ].second;
      cnt[ x ] = i;
      int r = *( --s.upper_bound( x - pw - 1 ) );
      if( r == -INF )
         sam[ x ] = i;
      else
         sam[ x ] = sam[ r ] + ( i - cnt[ r ] - 1 );
      sol = min( sol, sam[ x ] + n - i - 1 );
      s.insert( x );
   }
   cout << sol;
   return 0;
}