#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 1, u, v; i < n; i += 1) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    LL ans = 0;
    vector<vector<LL>> dp(n, vector<LL>(n));
    for (int i = 0; i < n; i += 1)
        for (int j = 1; j < n; j += 1) {
            if (i == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) * (mod + 1) / 2 % mod;
        }
    for (int i = 1; i <= n; i += 1)
        for (int j = i + 1; j <= n; j += 1) {
            vector<int> size(n + 1), dep(n + 1), par(n + 1);
            function<void(int)> DFS = [&](int u) {
                size[u] = 1;
                for (int v : G[u]) if (v != par[u]) {
                    dep[v] = dep[u] + 1;
                    par[v] = u;
                    DFS(v);
                    size[u] += size[v];
                }
            };
            DFS(i);
            int L = 0;
            for (int p = j; p; p = par[p]) {
                ans = (ans + dp[dep[j] - dep[p]][dep[p]] * (size[p] - L)) % mod;
                L = size[p];
            }
        }
    cout << ans * power(n, mod - 2) % mod;
}