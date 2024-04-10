#include <bits/stdc++.h>
#define iter(i) set< i >::iterator
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
#define REP( i, a ) for( int i = 0; i < a; i++ )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 300100, MOD = 1e9 + 7, B = 3137;

int n;
map< int, int > L;
int sol, last;

int main() {

    cin >> n;

    int m = MaxN, M = -1;

    for( int i = 0; i < n; i++ ) {
        int x;
        cin >> x;
        L[x] = i;

        m = min( m, x );
        M = max( M, x );

        if( M - m > 1 ) {
            if( m == x ) {
                last = L[x + 2] + 1;
                M = x + 1;
            }else {
                last = L[x - 2] + 1;
                m = x - 1;
            }
        }

        sol = max( sol, i - last + 1 );

    }

    cout << sol;
    return 0;
}