#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int64_t MOD = 998244353;
vector<int> g[MAXN];
int p[MAXN];
array<int64_t, 2> dp[MAXN];
int cnte[MAXN];
int K;

void dfs(int v) {
    cnte[v] = 0;
    for (auto u : g[v]) {
        if (u != p[v]) {
            p[u] = v;
            dfs(u);
            cnte[v] += cnte[u] + 1;
        }
    }
    if (K != 1) {
        for (int t = 0; t < 2; ++t) {
            if (v == 0 && t == 1) continue;
            int val = cnte[v] + 1 - t;
            if (v == 0) {
                val--;
                /// assert(val % K == 0);
            }
            if (val % K != 0) {
                dp[v][t] = 0;
                continue;
            }
            int cnt = 0;
            dp[v][t] = 1;
            for (auto u : g[v]) {
                if (u != p[v]) {
                    dp[v][t] *= max(dp[u][0], dp[u][1]);
                    dp[v][t] %= MOD;
                    if (dp[u][0] > 0) {
                        cnt++;
                    }
                }
            }
            if ((g[v].size() - t - cnt) % K != 0) {
                dp[v][t] = 0;
            }
        }
    } else {
        dp[v][0] = 1;
        for (auto u : g[v]) {
            if (u != p[v]) {
                dp[v][0] *= dp[u][0] * (int64_t)2;
                dp[v][0] %= MOD;
            }
        }
        dp[v][0] = dp[v][0];
    }
}

int64_t solve(int n, int k) {
    K = k;
    dfs(0);
    return dp[0][0];
}

int64_t ans[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            p[i] = 0;
            dp[i][0] = dp[i][1] = 0;
            ans[i + 1] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n - 1; ++i) {
            if ((n - 1) % i == 0) {
                ans[i] = solve(n, i);
            }
        }
        for (int i = n; i >= 1; --i) {
            for (int j = 2 * i; j <= n; j += i) {
                ans[i] -= ans[j];
            }
            ans[i] = (ans[i] % MOD + MOD) % MOD;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}