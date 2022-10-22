#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

vector < point > v;
#define x first
#define y second

int main() {
   int n, s; cin >> n >> s;
   for( int i = 0; i < n; ++i ) {
      int x, y;
      cin >> x >> y;
      v.push_back( point( y, x ) );
   }
   sort( v.begin(), v.end() );
   reverse( v.begin(), v.end() );
   int sol = 0;
   for( int i = 0; i < n; ++i ) {
      sol += s - v[ i ].x;
      sol = max( sol, v[ i ].y );
      s = v[ i ].x;
   }
   cout << sol + s;
   return 0;
}