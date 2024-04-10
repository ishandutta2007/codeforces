#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5;
const int mod = 998244353;

int n;
std::vector <int> adj[mxn];
int dp[mxn][3];

void dfs(int u, int p) {
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        static int f[3];
        f[0] = (2LL * dp[u][0] * dp[v][0] + 1LL * dp[u][0] * dp[v][2]) % mod;
        f[1] = (2LL * dp[u][1] * dp[v][0] + 1LL * dp[u][0] * dp[v][1] + 1LL * dp[u][1] * dp[v][2]) % mod;
        f[2] = (1LL * dp[u][2] * dp[v][0] + 1LL * dp[u][2] * dp[v][2]) % mod;
        dp[u][0] = f[0];
        dp[u][1] = f[1];
        dp[u][2] = f[2];
    }
    std::swap(dp[u][0], dp[u][1]);
    // eprintf("%d %d %d %d\n", u + 1, dp[u][0], dp[u][1], dp[u][2]);
}

int main() {
    scanf("%d", &n);
    rep(i, n - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    printf("%d\n", (dp[0][0] + dp[0][2]) % mod);
	return 0;
}