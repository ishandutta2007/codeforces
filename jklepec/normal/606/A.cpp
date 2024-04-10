#include <bits/stdc++.h>
#define iter(i) set< i >::iterator
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
#define REP( i, a ) for( int i = 0; i < a; i++ )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 100100, MOD = 1e9 + 7, B = 3137;

int main() {

    //ios_base::sync_with_stdio(false);

    int a, b, c;
    int x, y, z;

    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int uk = 0;

    uk += max( ( a - x ) / 2, 0 );
    uk += max( ( c - z ) / 2, 0 );
    uk += max( ( b - y ) / 2, 0 );

    if( a + uk >= x ) {
        uk -= max( 0, ( x - a ) );
    }else {
        cout << "No";
        return 0;
    }

    if( b + uk >= y ) {
        uk -= max( 0, ( y - b ) );
    }else {
        cout << "No";
        return 0;
    }

    if( c + uk >= z ) {
        uk -= max( 0, ( z - c ) );
    }else {
        cout << "No";
        return 0;
    }

    cout << "Yes";
    return 0;
}