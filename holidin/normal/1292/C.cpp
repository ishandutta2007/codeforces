#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 3e3 + 144;

int sz[N][N], nm[N], tin[N], pref[N][N], suf[N][N];
int tout[N];
int dp[N][N];
vector <int> e[N];
int top = 0, n;

void dfs(int u, int pr) {
    tin[u] = ++top;
    nm[top] = u;
    sz[pr][u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        int tp = top;
        dfs(e[u][i], u);
        sz[pr][u] += sz[u][e[u][i]];
        for (int j = 1; j <= n; ++j)
        if (tin[j] <= tp) {
            suf[j][e[u][i]] = u;
            pref[e[u][i]][j] = u;
        }
        for (int j = tp + 1; j <= top; ++j) {
            suf[nm[j]][u] = e[u][i];
            pref[u][nm[j]] = e[u][i];
        }
    }
    tout[u] = top;
    sz[u][pr] = n - sz[pr][u];
}

int f(int u, int v) {
    if (v > u)
        swap(u, v);
    if (dp[u][v] < 0) {
        dp[u][v] = max(f(pref[u][v],v), f(u, suf[u][v])) + sz[suf[u][v]][v] * sz[pref[u][v]][u];
    }
    return dp[u][v];
}

void dfs1(int u, int pr) {
    for (int i = 0; i < e[u].size(); ++i)
     if (e[u][i] != pr) {
        for (int j = 1; j <= n; ++j)
        if (j < tin[e[u][i]] && j > tout[e[u][i]]) {
            f(j, e[u][i]);
            f(e[u][i], j);
        }
        dfs1(e[u][i], u);
    }
}

bool used[N][N];

void solve() {
    int i, j, k, u, v;
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
    if (i != j)
        dp[i][j] = -1;
    else
        used[i][j] = 1;
    int ans = 0;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
        ans = max(ans, f(i, j));
    cout << ans;
}


signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();

}