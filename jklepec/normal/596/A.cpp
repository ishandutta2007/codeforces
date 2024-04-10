#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = (a); i < (b); i++ )
#define REP( i, a ) for( int i = 0; i < (a); i++ )
using namespace std;

const int MaxN = 100100, LOG = 19, MOD = 1e9 + 7, B = 3137;
typedef pair< int, int > point;
typedef long long llint;

int add(int x, int y) {
    return (x + y) % MOD;
}
int mult(int x, int y) {
    return (llint)x * y % MOD;
}
int sub(int x, int y) {
    x -= y;
    if (x < 0)
       x += MOD;
    else
        x %= MOD;
    return x;
}

int x1, Y1, biox, bioy;


int main() {

    int n;
    cin >> n;
    int sol = 1, nx = 0, ny = 0;

    REP( i, n ) {
        int x, y;
        cin >> x >> y;
        if( biox == 1 and x != x1 )
            x1 = abs( x1 - x ),
            biox ++;
        else if ( !biox )
            x1 = x,
            biox = 1;

        if( bioy == 1 and y != Y1 )
            Y1 = abs( Y1 - y ),
            bioy ++;
        else if ( !bioy )
            Y1 = y,
            bioy = 1;
    }

    if( biox > 1 and bioy > 1 )
        cout << x1 * Y1;
    else cout << -1;

    return 0;
}