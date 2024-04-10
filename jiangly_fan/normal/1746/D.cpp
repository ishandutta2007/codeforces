#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1)
        [&](){
            int n, k;
            cin >> n >> k;
            vector<int> p(n + 1), s(n + 1);
            vector<LL> ss(n + 1);
            vector<vector<pair<int, LL>>> dp(n + 1);
            vector<vector<int>> G(n + 1);
            for (int i = 2; i <= n; i += 1) {
                cin >> p[i];
                G[p[i]].push_back(i);
            }
            for (int i = 1; i <= n; i += 1)
                cin >> s[i];
            function<void(int)> DFS = [&](int u) {
                ss[u] = ss[p[u]] + s[u];
                for (int v : G[u]) {
                    for (auto [k, _] : dp[u]) {
                        dp[v].emplace_back(k / G[u].size(), 0);
                        if (k % G[u].size())
                            dp[v].emplace_back(k / G[u].size() + 1, 0);
                    }
                    ranges::sort(dp[v]);
                    dp[v].erase(unique(dp[v].begin(), dp[v].end()), dp[v].end());
                    DFS(v);
                }
                for (auto& [k, y] : dp[u]) {
                    if (G[u].empty()) y = k * ss[u];
                    else {
                        vector<LL> d;
                        for (int v : G[u]) {
                            auto it = lower_bound(dp[v].begin(), dp[v].end(), make_pair(k / (int)G[u].size(), 0LL));
                            y += it->second;
                            if (it != dp[v].end())
                                d.push_back(next(it)->second - it->second);
                        }
                        ranges::sort(d, greater<LL>());
                        for (int i = 0; i < k % G[u].size(); i += 1)
                            y += d[i];
                    }
                }
            };
            dp[1].emplace_back(k, 0);
            DFS(1);
            cout << dp[1][0].second << "\n";
        }();
}