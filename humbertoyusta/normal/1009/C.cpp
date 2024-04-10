#include<bits/stdc++.h>
using namespace std;

int cnt1;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);

    long double ans=0, x, d;
    long long n, m;

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        cin >> x >> d;
        if( d >= 0 ){
            long long tmp = ( n - 1ll ) * ( n ) / 2ll;
            ans += ( x * (long double)n + d * (long double)tmp );
        }
        else{
            long long tmp = ( ( n / 2ll ) * ( n / 2ll + 1ll ) / 2ll + ( ( n - 1ll ) / 2ll ) * ( ( n - 1ll ) / 2ll + 1ll ) / 2ll );
            ans += ( x * (long double)n + d * (long double)tmp );
        }
    }

    cout << ans / ( long double )( n ) << '\n';

    return 0;
}