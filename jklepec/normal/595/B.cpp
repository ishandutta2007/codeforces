#include <bits/stdc++.h>
using namespace std;

typedef long long llint;
llint a[100100], b[100100];

const llint MOD = 1e9 + 7;
llint sol;

int range( llint X, llint Y, llint Z ) {

    if( X > Y ) return 0;

    if( X % Z != 0)
        X += ( Z - X % Z );
    Y -= Y % Z;

    llint val;
    if(X > Y)
        val = 0;
    else
        val = (Y - X) / Z + 1;

    return val%MOD;

}

llint POW( llint x, llint y ) {

    llint ret = 1;

    while( y -- ) {
        ret *= x;
        ret %= MOD;
    }
    return ret;

}

int main() {


    llint n, k;
    cin >> n >> k;

    llint gornja = POW( 10, k ) - 1;
    llint donja  = ( POW( 10, k-1 ) );

    for( llint i=0; i<n/k; i++ )
        cin >> a[i];
    for( llint i=0; i<n/k; i++ )
        cin >> b[i];

    for( llint i=0; i<n/k; i++ ) {

        llint tmp = 0;

        tmp = range( 0, ( b[i] == 0 ? -1 : b[i] * donja - 1 ), a[i] )%MOD + range( ( ( 1 + b[i] ) * donja ), gornja, a[i] )%MOD;

        tmp %= MOD;

        if( tmp > 0 and sol == 0 ) sol = 1;


        sol *= tmp;
        sol %= MOD;

    }

    cout << sol;

    return 0;
}