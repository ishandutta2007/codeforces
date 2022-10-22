#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define INT( c, x ) ( c - '0' == x ? 1 : 0 )
using namespace std;

const int MaxN = 200100;

typedef long long llint;
typedef pair< int, int > point;

int nula[ MaxN ], jedinica[ MaxN ];

int main() {
   string a, b; cin >> a >> b;
   int n = a.size();
   int m = b.size();
   for( int i = 0; i < m; ++i ) {
      int ln, lj;
      if( i ) {
         lj = jedinica[ i - 1 ];
         ln = nula[ i - 1 ];
      }else {
         lj = ln = 0;
      }
      jedinica[ i ] = lj + INT( b[ i ], 1 );
      nula[ i ] = ln + INT( b[ i ], 0 );
   }
   llint sol = 0;
   for( int i = 0; i < n; ++i ) {
      if( a[ i ] == '0' ) {
         sol += (llint)jedinica[ m - n + i ];
      }
      else {
         sol += (llint)nula[ m - n + i ];
      }
      if( !i )
         continue;
      if( a[ i ] == '0' ) {
         sol -= (llint)jedinica[ i - 1 ];
      }
      else {
         sol -= (llint)nula[ i - 1 ];
      }
   }
   cout << sol;
   return 0;
}