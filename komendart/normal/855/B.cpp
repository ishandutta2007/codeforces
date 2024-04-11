#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 8e18;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mx = -INF;
    vector<int> pref(n);
    for (int i = 0; i < n; ++i) {
        mx = max(mx, p * a[i]);
        pref[i] = mx;
    }
    mx = -INF;
    vector<int> suf(n);
    for (int i = n - 1; i >= 0; --i) {
        mx = max(mx, r * a[i]);
        suf[i] = mx;
    }
    int ans = -INF;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, pref[i] + q * a[i] + suf[i]);
    }
    cout << ans << '\n';
}