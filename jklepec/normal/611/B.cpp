#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define all(a) (a).begin(), (a).end()
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 1e5 + 5;

vector< llint > v;

int main() {
   llint a, b; cin >> a >> b;
   for( int i = 0; i < 63; ++i ) {
      llint mask = 0;
      for( llint j = 0; j < i; ++j ) {
         mask |= ( 1LL << j );
      }
      for( llint j = i + 1; j < 63; ++j ) {
         mask |= ( 1LL << j );
         v.push_back( mask );
      }
   }
   sort(all(v));
   int cnt = 0;
   for( int i = 0; i < v.size(); ++i ) {
      if( v[ i ] > b )
         break;
      if( cnt ) {
         cnt ++;
         continue;
      }
      if( v[ i ] >= a )
         cnt = 1;
   }
   cout << cnt;
   return 0;
}