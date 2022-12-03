#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5 + 100;
vector<int> g[MAXN];
int dp[MAXN][2], k[MAXN], s[MAXN];

void dfs(int v) {
    vector<int> val;
    for (auto u : g[v]) {
        k[u] = k[v] / g[v].size();
        dfs(u);
        val.push_back(dp[u][1] - dp[u][0]);
    }
    sort(val.begin(), val.end());
    reverse(val.begin(), val.end());
    for (int t = 0; t < 2; ++t) {
        dp[v][t] = (k[v] + t) * s[v];
        if (g[v].empty()) continue;
        for (int u : g[v]) {
            dp[v][t] += dp[u][0];
        }
        for (int i = 0; i < k[v] % g[v].size() + t; ++i) {
            dp[v][t] += val[i];
        }
    }
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n >> k[0];
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            p--;
            g[p].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        dfs(0);
        cout << dp[0][0] << endl;
    }
    return 0;
}