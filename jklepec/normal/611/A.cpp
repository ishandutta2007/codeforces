#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define all(a) (a).begin(), (a).end()
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 1e5 + 5;


int main() {
   int n; cin >> n;
   string s; cin >> s;
   cin >> s;
   if( s == "week" ) {
      cout << 52 + ( n == 5 or n == 6 ? 1 : 0 );
   }
   else if ( n == 30 )
      cout << 11;
   else if( n == 31 )
      cout << 7;
   else
      cout << 12;
   return 0;
}