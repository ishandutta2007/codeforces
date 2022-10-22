#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

void solve(){
    ll n;
    cin >> n;
    ll nzs = 1;
    ll res = 0;
    for(ll j=2; j<=100 && n >= nzs; j++){
        ll dif = j/__gcd(nzs, j);
        ll g = n/nzs;
        res = (res + j*(g - g/dif))%MOD;
        nzs *= dif;
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}