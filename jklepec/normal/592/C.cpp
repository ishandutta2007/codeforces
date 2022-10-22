#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define razmak(x) cout << x << " _ "
#define red(x) cout << x << endl
using namespace std;

typedef long long llint;

llint gcd( llint a, llint b ) {
    return b / __gcd( a, b );
}

int main() {

    ios_base::sync_with_stdio(false);

    llint a, b, x, y, t, GCD;
    cin >> t >> a >> b;

    GCD = gcd( a, b );

    if( t / GCD + 1 >= a ) {
        GCD *= a;
        x = min( a, b ) * ( t / GCD ) + min( t % GCD, min( a, b ) - 1 );
    }
    else x = min( t, min( a, b ) - 1 );

    GCD = __gcd( x, t );
    cout << x / GCD << "/" << t / GCD;

    return 0;
}