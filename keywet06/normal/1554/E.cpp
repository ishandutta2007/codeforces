#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 998244353;

vector<int> g[N];
int dp[N], d, ok, ans[N];
void dfs(int u, int p = 0) {
    if (!ok) return;
    for (auto v : g[u]) {
        if (v ^ p) {
            dfs(v, u);
        }
    }
    if (dp[u] % d != 0) {
        if (p) {
            dp[u]++;
        }
        if (dp[u] % d != 0) {
            ok = 0;
            return;
        }
    } else {
        dp[p]++;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            ans[i] = 0;
        }
        ans[1] = 1;
        for (int k = 1; k <= n - 1; k++) {
            ans[1] = (ans[1] + ans[1]) % mod;
        }
        for (d = 2; d <= n - 1; d++) {
            if ((n - 1) % d == 0) {
                ok = 1;
                dfs(1);
                ans[d] = ok;
                for (int i = 0; i <= n; i++) {
                    dp[i] = 0;
                }
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = i + i; j <= n; j += i) {
                ans[i] = (ans[i] - ans[j] + mod) % mod;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }
    return 0;
}