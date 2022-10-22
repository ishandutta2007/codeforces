#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 5;

typedef long long llint;
typedef pair< int, int > point;

vector < int > v;

int main() {
   int n; cin >> n;
   int m; cin >> m;
   for( int i = 0; i < n; ++i ) {
      int x; cin >> x;
      v.push_back( x );
   }
   sort( v.begin(), v.end() );
   reverse( v.begin(), v.end() );
   for( int i = 0; i < n; ++i ) {
      m -= v[ i ];
      if( m <= 0 ) {
         cout << i + 1;
         break;
      }
   }
   return 0;
}