#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 6e5;
vector<pair<int, int>> g[MAXN];
int used[MAXN];
int k;
int dp[MAXN], dp1[MAXN];

void dfs(int v) {
    used[v] = true;
    dp[v] = 0;
    dp1[v] = 0;
    vector<int> arr;
    for (auto e : g[v]) {
        int u = e.first;
        int w = e.second;
        if (!used[u]) {
            dfs(u);
            dp[v] += dp[u];
            dp1[v] += dp[u];
            arr.push_back(w + dp1[u] - dp[u]);
        }
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < min((size_t)(k - 1), arr.size()); ++i) {
        if (arr[i] > 0) {
            dp[v] += arr[i];
            dp1[v] += arr[i];
        }
    }
    if (k <= arr.size()) {
        if (arr[k - 1] > 0) {
            dp[v] += arr[k - 1];
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            used[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(0);
        cout << dp[0] << endl;
    }
    return 0;
}