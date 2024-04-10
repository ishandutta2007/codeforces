#include <bits/stdc++.h>
#define iter(i) set< i >::iterator
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
#define REP( i, a ) for( int i = 0; i < a; i++ )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 100100, MOD = 1e9 + 7, B = 3137;

llint n, b;

llint x, y;

llint POW( llint a, llint b ) {
    llint ret = 1LL;
    while( b-- ) {
        ret *= a;
    }
    return ret;
}

int main() {

    cin >> n;
    cin >> b;

    REP( i, n ) {
        llint zn;
        cin >> zn;
        x += zn * POW( b, n - i - 1 );
    }

    cin >> n;
    cin >> b;

    REP( i, n ) {
        llint zn;
        cin >> zn;
        y += zn * POW( b, n - i - 1 );
    }

    if( x > y ) cout << ">";
    else if ( x == y ) cout << "=";
    else cout << "<";

    return 0;
}