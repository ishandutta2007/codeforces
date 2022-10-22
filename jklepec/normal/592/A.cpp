#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define razmak(x) cout << x << " _ "
#define red(x) cout << x << endl
using namespace std;

int n = 8;
char c[10][10];
int biow[10], biob[10];
int minw = 10, minb = 10;

int main() {

    ios_base::sync_with_stdio(false);

    REP( i, n ) {
        REP( j, n ) {
            cin >> c[i][j];
            if( c[i][j] == 'B' ) biob[j] = true;
            if( c[i][j] == 'W' ) biow[j] = i;
            if( c[i][j] == 'W' and !biob[j] ) minw = min( minw, i );
        }
    }

    REP( i, n )
        REP( j, n )
            if( c[i][j] == 'B' and biow[j] < i ) minb = min( minb, n-i-1 );

    if( minb >= minw ) cout << 'A';
    else cout << 'B';
    return 0;
}