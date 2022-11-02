#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 5e5, MOD = 998244353;
vector<int> g[MAXN];
int dp[MAXN], used[MAXN];
int fact[MAXN];

void dfs(int v) {
    used[v] = 1;
    dp[v] = 1;
    int cnt = 0;
    for (auto u : g[v]) {
        if (!used[u]) {
            cnt++;
            dfs(u);
            dp[v] *= (dp[v] * 2 * dp[u]) % MOD;
        }
    }
    dp[v] = (dp[v] * fact[cnt]) % MOD;

}

main() {
    int n;
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        ans = (ans * fact[g[i].size()]) % MOD;
    }
    cout << ans;
    return 0;
}