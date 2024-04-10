#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 1e5 + 1e5 + 5, INF = 1e9 + 5;

int a[ MaxN ], L[ MaxN ];

int main() {
   int mn = INF;
   int n; cin >> n;
   for( int i = 0; i < n; ++i ) {
      cin >> a[ i ];
      mn = min( mn, a[ i ] );
   }
   for( int i = 0; i < n; ++i ) {
         a[ i ] -= mn;
   }
   L[ 0 ] = ( a[ 0 ] == 0 ? 0 : 1 );
   for( int i = 1; i < n; ++i ) {
      if( a[ i ] ) {
         L[ i ] = L[ i - 1 ] + 1;
      }
      else {
         L[ i ] = 0;
      }
   }
   llint sol = (llint)mn * n;
   for( int i = 0; i < n; ++i ) {
      llint tmp = L[ i ];
      if( L[ i ] == i + 1 )
         tmp += L[ n - 1 ];
      sol = max( sol, tmp + (llint)mn * n );
   }
   cout << sol;
   return 0;
}