#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    ll x, y;
    ll ans = -1;
    for(ll i = 0; i < m; ++i){
        cin >> x >> y;
        if(y >= sum){
            ans = max(sum, x);
            break;
        }
    }
    cout << ans << endl;


    return 0;
}