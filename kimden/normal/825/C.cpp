#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    ll mx = k;
    for(ll i = 0; i < n; ++i){
        while((mx << 1LL) < a[i]){
            mx <<= 1LL;
            ++ans;
        }
        mx = max(mx, a[i]);
    }
    cout << ans << endl;
    return 0;
}