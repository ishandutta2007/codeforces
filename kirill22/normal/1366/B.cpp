#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    vector<pii> a(m);
    for (int i = 0; i < m; i++) cin >> a[i].fi >> a[i].se;
    int L = x, R = x;
    for (int j = 0; j < m; j++) {
        if (a[j].se < L || a[j].fi > R) continue;
        L = min(L, a[j].fi);
        R = max(R, a[j].se);
    }
    cout << R - L + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}