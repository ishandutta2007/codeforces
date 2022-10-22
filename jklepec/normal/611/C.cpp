#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define all(a) (a).begin(), (a).end()
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 505;

int c[ MaxN ][ MaxN ], add[ MaxN ][ MaxN ], dom[ MaxN ][ MaxN ], l[ MaxN ][ MaxN ], u[ MaxN ][ MaxN ];

int main() {
   int n, m; cin >> n >> m;
   for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
         char x; cin >> x;
         c[ i ][ j ] = ( x == '.' ? 1 : 0 );
      }
   }
   for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
         add[ i ][ j ] = 0;
         if( i )
            add[ i ][ j ] = add[ i - 1 ][ j ];
         if( i )
            if( c[ i ][ j ] and c[ i - 1 ][ j ] )
               add[ i ][ j ]++;
         if( j )
            if( c[ i ][ j ] and c[ i ][ j - 1 ] )
               add[ i ][ j ]++;
      }
   }
   for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
         dom[ i ][ j ] = 0;
         if( j )
            dom[ i ][ j ] = dom[ i ][ j - 1 ];
         dom[ i ][ j ] += add[ i ][ j ];
      }
   }
   for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
         if( i )
            l[ i ][ j ] = l[ i - 1 ][ j ];
         if( j )
            u[ i ][ j ] = u[ i ][ j - 1 ];
         if( j )
            if( c[ i ][ j ] and c[ i ][ j - 1 ] )
               l[ i ][ j ]++;
         if( i )
            if( c[ i ][ j ] and c[ i - 1 ][ j ] )
               u[ i ][ j ]++;
      }
   }
   int q = 0; cin >> q;
   for( int i = 0; i < q; ++i ) {
      int x, y, a, b;
      cin >> x >> y >> a >> b;
      --x; --y; --a; --b;
      int sol = dom[ a ][ b ];
      if( x )
         sol -= dom[ x - 1 ][ b ];
      if( y )
         sol -= dom[ a ][ y - 1 ];
      if( x and y )
         sol += dom[ x - 1 ][ y - 1 ];
      sol -= u[ x ][ b ] + l[ a ][ y ];
      if( y )
         sol += u[ x ][ y - 1 ];
      if( x )
         sol += l[ x - 1 ][ y ];
      cout << sol << endl;
   }
   return 0;
}