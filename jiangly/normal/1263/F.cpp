#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> subtree;
    auto solve = [&]() {
        int m;
        cin >> m;
        vector<vector<int>> e(m);
        vector<int> sz(m), l(m, n), r(m), connect(m, -1);
        for (int i = 1; i < m; ++i) {
            int p;
            cin >> p;
            --p;
            e[p].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            --x;
            connect[x] = i;
        }
        function<void(int)> dfs = [&](int u) {
            sz[u] = 1;
            if (connect[u] != -1) {
                l[u] = connect[u];
                r[u] = connect[u] + 1;
            }
            for (int v : e[u]) {
                dfs(v);
                sz[u] += sz[v];
                l[u] = min(l[u], l[v]);
                r[u] = max(r[u], r[v]);
            }
            subtree.emplace_back(l[u], r[u], sz[u] - (u == 0));
        };
        dfs(0);
    };
    solve();
    solve();
    sort(subtree.begin(), subtree.end());
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (auto t : subtree) {
        int l, r, w;
        tie(l, r, w) = t;
        dp[r] = max(dp[r], dp[l] + w);
    }
    cout << dp[n] << endl;
    return 0;
}