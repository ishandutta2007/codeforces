#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 1024 + 1;

int pw( int x ) {
   int ret = 1;
   while( x ) {
      x--;
      ret *= 2;
   }
   return ret;
}

string pattern[ MaxN ];

string inv( string s ) {
   string ret = "";
   for( int i = 0; i < s.size(); ++i )
      ret += ( s[ i ] == '+' ? '*' : '+' );
   return ret;
}

int main() {
   int k; cin >> k;
   int stupanj = 0;
   pattern[ 0 ] = "+";
   while( stupanj < k ) {
      int sz = pw( stupanj );
      for( int i = 0; i < sz; ++i ) {
         pattern[ i + sz ] = pattern[ i ] + inv( pattern[ i ] );
         pattern[ i ] += pattern[ i ];
      }
      stupanj ++;
   }
   for( int i = 0; i < pw( k ); ++i )
      cout << pattern[ i ] << endl;
   return 0;
}