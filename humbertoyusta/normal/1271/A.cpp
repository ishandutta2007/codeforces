#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int ans = 0;
    if( e >= f ){
        ans += min( a , d );
        d -= ans;
        ans *= e;
        ans += min( min( b , c ) , d ) * f;
    }
    else{
        ans += min( min( b , c ) , d );
        d -= ans;
        ans *= f;
        ans += min( a , d ) * e;
    }

    cout << ans << '\n';

    return 0;
}