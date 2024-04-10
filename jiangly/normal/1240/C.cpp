#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<vector<LL>> dp(n);
    for (auto &i : dp)
        i.resize(2);
    function<void(int, int)> dfs = [&](int u, int p) {
        vector<LL> x;
        for (auto [v, w] : g[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            dp[v][1] += w;
            dp[u][1] += dp[v][0];
            if (dp[v][1] > dp[v][0])
                x.push_back(dp[v][1] - dp[v][0]);
        }
        sort(x.begin(), x.end(), greater<LL>());
        for (int i = 0; i < min(k - 1, int(x.size())); ++i)
            dp[u][1] += x[i];
        dp[u][0] = dp[u][1];
        if (x.size() >= k)
            dp[u][0] += x[k - 1];
    };
    dfs(0, -1);
    cout << dp[0][0] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}