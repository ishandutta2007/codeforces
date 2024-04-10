#include <bits/stdc++.h>
using namespace std;

#define int64 long long
#define pii pair<int, int>
#define fi first
#define se second

const int mxN = 100;
int n, c1[mxN], c2[mxN], v[mxN], a[mxN], dp[2][16][1024], ans;
bool vis[4];
vector<int> adj[4];

int b(int x, int y) {
    for (int i = 3; x; --i, --x) y += i;

    return y;
}

pii c(int x) {
    pii r = {0, x};
    for (int i = 1; r.se >= 4; ++i) {
        ++r.fi;
        r.se -= 4 - i;
    }

    return r;
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c1[i] >> v[i] >> c2[i], --c1[i], --c2[i];
        if (c1[i] > c2[i]) swap(c1[i], c2[i]);
        a[i] = b(c1[i], c2[i]);
    }
    memset(dp[0], 0x80, sizeof(dp[0]));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        memcpy(dp[i & 1 ^ 1], dp[i & 1], sizeof(dp[0]));
        for (int j = 0; j < 16; ++j) {
            int nj = j ^ 1 << c1[i] ^ 1 << c2[i];
            for (int k = 0; k < 1024; ++k)
                dp[i & 1 ^ 1][nj][k | 1 << a[i]] = max(
                    dp[i & 1][j][k] + v[i], dp[i & 1 ^ 1][nj][k | 1 << a[i]]);
        }
    }

    for (int i = 0; i < 16; ++i) {
        if (__builtin_popcount(i) & 1 || __builtin_popcount(i) >= 4) continue;
        for (int j = 1; j < 1024; ++j) {
            vector<int> tt;
            for (int k = 0; k < 4; ++k) adj[k].clear();
            for (int k = 0; k < 10; ++k) {
                if (j >> k & 1 ^ 1) continue;
                pii e = c(k);
                tt.push_back(e.fi);
                tt.push_back(e.se);
                adj[e.fi].push_back(e.se);
                adj[e.se].push_back(e.fi);
            }
            memset(vis, 0, sizeof(vis));
            dfs(tt[0]);
            bool ok = 1;
            for (int tti : tt) ok &= vis[tti];
            if (ok) ans = max(dp[n & 1][i][j], ans);
        }
    }
    cout << ans;
}