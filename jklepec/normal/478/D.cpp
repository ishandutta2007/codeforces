#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define FORD( i, a, b ) for( int i = a; i >=b; --i )
using namespace std;

const int MaxN = 200100, MOD = 1e9+7;

int n;
int dp[MaxN];

void add( int &x, int y ) {
    x += y;
    x %= MOD;
}

int main() {

    int a, b; cin >> a >> b;
    if( a < b ) swap( a, b );
    int H = 1;
    while( ( H + 2 ) * ( H + 1 ) / 2 <= a + b ) H ++;

    dp[0] = 1;
    FOR( h, 1, H+1 ) {
        FORD( i, MaxN-1, 0 ) {
            if( h + i >= MaxN ) continue;
            add( dp[ i + h ], dp[ i ] );
        }
    }

    int sol = 0;
    FOR( i, max( 0, (H*H+H)/2  - a ), b+1 ) add( sol, dp[ i ] );
    cout << sol;
    return 0;
}