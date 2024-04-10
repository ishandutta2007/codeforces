#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const int mxn = 4005;
int n, m, arr[mxn];
int ch[mxn][2];
int rt;

int build(int l, int r) {
    if (l > r) return 0;
    int mid = 0;
    for (int i = l; i <= r; ++ i) {
        if (mid == 0 || arr[i] < arr[mid]) {
            mid = i;
        }
    }
    ch[mid][0] = build(l, mid - 1);
    ch[mid][1] = build(mid + 1, r);
    return mid;
}

int siz[mxn];
i64 dp[mxn][mxn];

void dfs(int u) {
    if (!u) return ;
    dfs(ch[u][0]);
    dfs(ch[u][1]);
    siz[u] = 1 + siz[ch[u][0]] + siz[ch[u][1]];
    memset(dp[u], -0x3f, sizeof(dp[u]));
    rep(a, std::min(siz[ch[u][0]], m) + 1) {
        rep(b, std::min(siz[ch[u][1]], m) + 1) {
            dp[u][a + b] = std::max(dp[u][a + b], dp[ch[u][0]][a] + dp[ch[u][1]][b] - 2LL * a * b * arr[u]);
        }
    }
    for (int a = std::min(m, siz[u] - 1); a >= 0; -- a) {
        dp[u][a + 1] = std::max(dp[u][a + 1], dp[u][a] + 1LL * m * arr[u] - 2LL * a * arr[u] - arr[u]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i) scanf("%d", &arr[i]);
    rt = build(1, n);
    memset(dp[0], -0x3f, sizeof(dp[0]));
    dp[0][0] = 0;
    dfs(rt);
    printf("%lld\n", dp[rt][m]);
    return 0;
}