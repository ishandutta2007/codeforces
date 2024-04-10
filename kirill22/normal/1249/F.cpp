#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, K;
vector<vector<int>> g;
vector<int> d;
vector<vector<int>> dp;

void dfs(int v, int pr, int k) {
    for (auto c : g[v]) {
        if (c != pr) dfs(c, v, k + 1);
    }
    dp[v][k] = d[v];
    for (auto c : g[v]) {
        if (c != pr) {
            if (k + K < 201) {
                dp[v][k] += dp[c][k + K];
            }
        }
    }
    for (int i = k + 1; i < 201; i++) {
        for (auto c : g[v]) {
            if (c != pr) {
                int ans = dp[c][i];
                for (auto u : g[v]) {
                    if (u != pr && u != c) {
                        int l = max(K - i + 2 * k, i);
                        if (l >= i && l < 201) {
                            ans += dp[u][l];
                        }
                    }
                }
                dp[v][i] = max(dp[v][i], ans);
            }
        }
    }
    for (int i = 200; i >= k; i--) {
        dp[v][i] = max(dp[v][i], dp[v][i + 1]);
    }
}

signed main() {
    cin >> n >> K;
    K++;
    g.resize(n);
    d.resize(n);
    dp.resize(n, vector<int> (210, 0));
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[0][0];
}