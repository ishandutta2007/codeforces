#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 5;

typedef long long llint;
typedef pair< int, int > point;

vector < int > v;
int book[ MaxN ];

int main() {
   int n, m; cin >> n >> m;
   for( int i = 0; i < n; ++i ) {
      int x; cin >> x;
      book[ x ]++;
   }
   int sol = 0, tmp = 0;
   for( int i = 0; i < MaxN; ++i ) {
      sol += book[ i ] * tmp;
      tmp += book[ i ];
   }
   cout << sol;
   return 0;
}