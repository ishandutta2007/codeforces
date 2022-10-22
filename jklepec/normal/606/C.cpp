#include <bits/stdc++.h>
#define iter(i) set< i >::iterator
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
#define REP( i, a ) for( int i = 0; i < a; i++ )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 100100, MOD = 1e9 + 7, B = 3137;
int last[MaxN];

int main() {

    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int mx = 0;
    REP( i, n ) {
        int x; cin >> x;
        last[x] = last[x-1] + 1;
        mx = max( mx, last[x] );
    }

    cout << n - mx;
    return 0;
}