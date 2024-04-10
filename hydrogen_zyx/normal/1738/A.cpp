#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll a[N], b[N];

ll solve(vector<ll> v1, vector<ll> v2) {

    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    if (v1.empty()) {
        ll ans = 0;
        for (auto x: v2) {
            ans += x;
        }
        return ans;
    }
    if (v2.empty()) {
        ll ans = 0;
        for (auto x: v1) {
            ans += x;
        }
        return ans;
    }

    ll ans = v2.back();
    for (ll i = 0; i < min(v1.size(), v2.size() - 1); i++) {
        ans += v1[i] * 2 + v2[i] * 2;
    }
    bool f = 1;
    for (ll i = min(v1.size(), v2.size() - 1); i < v1.size(); i++) {
        if (f) ans += v1[i] * 2;
        else ans += v1[i];
        f = 0;
    }

    for (ll i = min(v1.size(), v2.size() - 1); i < v2.size() - 1; i++) {
        ans += v2[i];
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v1, v2;
        for (ll i = 1; i <= n; i++) cin >> a[i];
        for (ll i = 1; i <= n; i++) cin >> b[i];
        for (ll i = 1; i <= n; i++) {
            if (a[i] == 0) v1.push_back(b[i]);
            else v2.push_back(b[i]);
        }

        ll ans = max(solve(v1, v2), solve(v2, v1));
        cout << ans << endl;
    }
}