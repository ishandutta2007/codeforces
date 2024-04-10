#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, y;
    scanf("%d", &n);
    scanf("%d", &m);
    long long a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        g[y - 1].push_back(x - 1);
    }
    map<vector<int>, long long> b;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 0) continue;
        sort(g[i].begin(), g[i].end());
        b[g[i]] += a[i];
    }
    long long res = 0;
    for (auto el : b) res = __gcd(res, el.second);
    cout << res << '\n';
}

signed main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        solve();
    }
}