#include <bits/stdc++.h>

const int N = 60005;
const int C = 256;

int n, q;
int p[N], h[N], a[N], p2[N], was[N];
int pp[9][N];
int go[N][C];
int dp[2][N][C];

std::vector<int> To[N];

int gt(int x) { return x >> 8; }
int gt2(int x) { return x & 255; }

void dfs1(int v) {
    was[v] = 1;
    for (int u : To[v]) {
        if (was[u]) continue;
        p[u] = v;
        h[u] = h[v] + 1;
        dfs1(u);
    }
    if (h[v] >= C) {
        int x = v;
        for (int j = 0; j < C; ++j) {
            go[v][gt(a[x])] = std::max(go[v][gt(a[x])], gt2(a[x]) ^ j);
            x = p[x];
        }
    }
    for (int i = 0; i < C; ++i) dp[0][v][i] = (gt(a[v]) ^ i);
}

void init() {
    dfs1(0);
    for (int i = 0; i < n; ++i) pp[0][i] = p[i];
    for (int i = 1; i <= 8; ++i) {
        for (int j = 0; j < n; ++j) pp[i][j] = pp[i - 1][pp[i - 1][j]];
    }
    for (int i = 0; i < n; ++i) {
        if (h[i] >= C) {
            p2[i] = pp[8][i];
        } else {
            p2[i] = -1;
        }
    }
    for (int i = 1; i <= 8; ++i) {
        for (int j = 0; j < n; ++j) {
            if (h[j] >= (1 << i)) {
                for (int k = 0; k < C; ++k) {
                    dp[i & 1][j][k] = std::max(dp[1 - (i & 1)][j][k], dp[1 - (i & 1)][pp[i - 1][j]][k]);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        To[a].push_back(b);
        To[b].push_back(a);
    }
    init();
    for (int i = 0; i < q; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        int ans = 0, cur = 0, mx = 0, x = v;
        while (h[u] + C <= h[x]) mx = std::max(mx, dp[0][x][cur]), ++cur, x = p2[x];
        x = v, cur = 0;
        while (h[u] + C <= h[x]) ans = std::max(ans, go[x][mx ^ cur]), ++cur, x = p2[x];
        ans += (mx << 8), cur <<= 8;
        while (h[x] >= h[u]) {
            ans = std::max(ans, a[x] ^ cur);
            if (x == 0) break;
            ++cur, x = p[x];
        }
        printf("%d\n", ans);
    }
    return 0;
}