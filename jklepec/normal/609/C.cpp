#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 5, INF = 1e9 + 1e9 + 2;

typedef long long llint;
typedef pair< int, int > point;

vector < int > v;
int a[ MaxN ];
int x, y;


int main() {
   int n; cin >> n;
   int sum = 0;
   for( int i = 0; i < n; ++i ) {
      int x; cin >> x;
      a[ x ]++;
      sum += x;
   }
   int x = sum / n;
   int y = x + ( sum % n ? 1 : 0 );
   int i = 0, j = 2 * (1e4), sol = 0;
   while( 1 ) {
      if( j - i <= 1 )
         break;
      if( !a[ i ] ) {
         ++i;
         continue;
      }
      if( !a[ j ] ) {
         --j;
         continue;
      }
      if( a[ j ] > a[ i ] ) {
         sol += a[ i ];
         a[ i + 1 ] += a[ i ];
         a[ j - 1 ] += a[ i ];
         a[ j ] -= a[ i ];
         a[ i ] -= a[ i ];
         ++i;
      }else if( a[ j ] < a[ i ] ) {
         sol += a[ j ];
         a[ i + 1 ] += a[ j ];
         a[ j - 1 ] += a[ j ];
         a[ i ] -= a[ j ];
         a[ j ] -= a[ j ];
         --j;
      }else {
         sol += a[ j ];
         a[ i + 1 ] += a[ j ];
         a[ j - 1 ] += a[ j ];
         a[ i ] -= a[ j ];
         a[ j ] -= a[ j ];
         --j; ++i;
      }
   }
   cout << sol;
   return 0;
}