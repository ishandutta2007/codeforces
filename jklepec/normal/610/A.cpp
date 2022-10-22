#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define all(a) (a).begin(), (a).end()
#define pb push_back
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 1e5 + 5;

int main() {
   int n; cin >> n;
   if( n%2 == 1 )
      cout << 0;
   else if( (double) n / 4. == (double)(n / 4) )
      cout << n / 4 - 1;
   else
      cout << n / 4;
   return 0;
}