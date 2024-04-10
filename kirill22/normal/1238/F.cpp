#include<bits/stdc++.h>

using namespace std;

#define int long long

int ans, n;
vector<vector<int>> g;
vector<int> dp;

void dfs (int v, int pr) {
    vector<int> a;
    for (auto x : g[v]) {
        if (pr != x) {
            dfs(x, v);
            a.push_back(dp[x]);
        }
    }
    sort(a.rbegin(), a.rend());
    if (a.size() == 0) {
        dp[v] = 1;
        return;
    }
    dp[v] = a.size() + a[0];
    ans = max(ans, dp[v]);
    if (a.size() >= 2) {
        if (pr == -1) {
            a[0]--;
        }
        ans = max(ans, a.size() + a[0] + a[1]);
    }
}


signed main() {
    int q;
    cin >> q;
    while (q--) {
        ans = 1;
        cin >> n;
        g.clear();
        g.resize(n);
        dp.clear();
        dp.resize(n, 0);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(0, -1);
        cout << ans << endl;
    }
}