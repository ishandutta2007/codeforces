#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pref[i] = pref[i - 1] ^ x;
    }
    map<int, int> cnt;
    int M = (1 << k) - 1;
    for (auto i: pref) {
        i = min(i, i ^ M);
        ++cnt[i];
    }
    ll ans = n * (ll) (n + 1) / 2;
    for (auto it: cnt) {
        ll a = it.second / 2;
        ll b = it.second - a;
        ans -= a * (a - 1) / 2;
        ans -= b * (b - 1) / 2;
    }
    cout << ans << '\n';
}