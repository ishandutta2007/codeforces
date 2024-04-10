#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

void solve(){
    ll x;
    cin >> x;
    cout << ((x/4+1)%MOD)*((x/2-x/4+1)%MOD)%MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}