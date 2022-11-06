#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

int n, m;
vector<int> edge[2005];
bool vis[2005];
int dfs(int x) {
    vis[x] = 1;
    int ret = 1;
    for (int i : edge[x]) {
        if (vis[i]) continue;
        ret += dfs(i);
    }
    return ret;
}

const int M = 4005, mod = 1e9 + 7;

void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int mul(int x, int y) {
    return llong(x) * y % mod;
}

int dp[2005][8010], ep[2005][8010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vis[1] = 1;
    vector<int> S;
    for (int i : edge[1]) {
        if (vis[i]) continue;
        S.push_back(dfs(i) + 1);
    }
    m = S.size();
    dp[0][M] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < M + M; ++j) {
            if (dp[i][j]) {
                add(dp[i + 1][j + S[i]], dp[i][j]);
                add(dp[i + 1][j - S[i]], dp[i][j]);
                add(ep[i + 1][j + S[i] - 1], mul(2, dp[i][j]));
                add(ep[i + 1][j - S[i] + 1], mul(2, dp[i][j]));
            }
            if (ep[i][j]) {
                add(ep[i + 1][j + S[i]], ep[i][j]);
                add(ep[i + 1][j - S[i]], ep[i][j]);
            }
        }
    }
    int ans = dp[m][M];
    add(ans, ep[m][M]);
    memset(dp, 0, sizeof(dp));
    memset(ep, 0, sizeof(ep));
    dp[0][M] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < M + M; ++j) {
            if (!dp[i][j]) continue;
            add(dp[i + 1][j + S[i]], dp[i][j]);
            add(dp[i + 1][j], dp[i][j]);
            add(dp[i + 1][j - S[i]], dp[i][j]);
        }
    }
    ep[m][M] = 1;
    for (int i = m; i--; ) {
        for (int j = 0; j < M + M; ++j) {
            if (!ep[i + 1][j]) continue;
            add(ep[i][j + S[i]], ep[i + 1][j]);
            add(ep[i][j], ep[i + 1][j]);
            add(ep[i][j - S[i]], ep[i + 1][j]);
        }
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j < M + M; ++j) {
            add(ep[i][j], ep[i][j - 1]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int * d = dp[i], * e = ep[i + 1];
        // -S[i] < j < S[i];
        for (int j = 0; j < M + M; ++j) {
            if (!d[j]) continue;
            int L = 2 - S[i] - (j - M) + M, R = S[i] - 2 - (j - M) + M;
            L = max(L, 1);
            R = min(R, M + M - 1);
            if (L > R) continue;
            add(ans, mul(2 * d[j], e[R] + mod - e[L - 1]));
        }
    }
    printf("%d\n", ans);
    return 0;
}