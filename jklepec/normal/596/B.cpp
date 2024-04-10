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


int main() {

    int n;

    cin >> n;

    llint cur = 0, sol = 0;

    for( int i=0; i<n; i++ ) {
        llint x;
        cin >> x;
        sol += abs( x - cur );
        cur += x - cur;
    }

    cout << sol;
    return 0;
}