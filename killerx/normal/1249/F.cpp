#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 205;

int n, K;
int wei[mxn];
std::vector <int> adj[mxn];
int dp[mxn][mxn];

inline void chmax(int &x, int y) {
    if (y > x) x = y;
}

void dfs(int u, int p) {
    memset(dp[u], -0x3f, sizeof(dp[u]));
    dp[u][0] = wei[u];
    dp[u][K + 1] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        static int f[mxn];
        memset(f, -0x3f, sizeof(f));
        for (int a = 0; a <= K + 1; ++ a) {
            for (int b = 0; b <= K + 1; ++ b) {
                if (a + b + 1 > K) chmax(f[std::min(a, b + 1)], dp[u][a] + dp[v][b]);
            }
        }
        memcpy(dp[u], f, sizeof(f));
    }
}

int main() {
    scanf("%d %d", &n, &K);
    rep(i, n) scanf("%d", &wei[i]);
    rep(i, n - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    int ans = -0x3f3f3f3f;
    for (int i = 0; i <= K + 1; ++ i)
        chmax(ans, dp[0][i]);
    printf("%d\n", ans);
	return 0;
}