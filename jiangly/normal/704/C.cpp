#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E5, P = 1E9 + 7;
void inc(int &a, int b) {(a += b) >= P ? a -= P : 0;}
int n, m;
int k[N], lst[N];
bool neg[N], visited[N];
vector<pair<int, int>> e[N];
int ans[2], dp[2];
void update() {
    int tmp[2] {};
    tmp[0] = (1LL * ans[0] * dp[0] + 1LL * ans[1] * dp[1]) % P;
    tmp[1] = (1LL * ans[0] * dp[1] + 1LL * ans[1] * dp[0]) % P;
    ans[0] = tmp[0];
    ans[1] = tmp[1];
}
void solveVertex(int u) {
    visited[u] = true;
    if (k[u] == 1) {
        dp[0] = dp[1] = 1;
    } else {
        dp[0] = 1;
        dp[1] = 3;
    }
    update();
}
void solveChain(int u) {
    visited[u] = true;
    int f[2][2][2] {};
    if (k[u] == 1) {
        f[0][0][0] = f[0][1][1] = 1;
    } else {
        f[0][0][0] = 1;
        f[0][0][1] = 1;
        f[0][1][1] = 2;
    }
    int v, x, cur = 0;
    tie(v, x) = e[u][0];
    while ((int)e[v].size() == 2) {
        visited[v] = true;
        cur ^= 1;
        memset(f[cur], 0, 4 * sizeof(int));
        for (int l = 0; l < 2; ++l)
            for (int t = 0; t < 2; ++t)
                for (int c = 0; c < 2; ++c)
                    inc(f[cur][c][t ^ ((l ^ x) | c)], f[cur ^ 1][l][t]);
        int lst = u;
        u = v;
        tie(v, x) = e[u][0];
        if (v == lst)
            tie(v, x) = e[u][1];
    }
    visited[v] = true;
    dp[0] = dp[1] = 0;
    if (k[v] == 1) {
        for (int l = 0; l < 2; ++l)
            for (int t = 0; t < 2; ++t)
                inc(dp[t ^ (l ^ x)], f[cur][l][t]);
    } else {
        for (int l = 0; l < 2; ++l)
            for (int t = 0; t < 2; ++t)
                for (int c = 0; c < 2; ++c)
                    inc(dp[t ^ ((l ^ x) | c)], f[cur][l][t]);
    }
    update();
}
void solveCircle(int u) {
    visited[u] = true;
    int v, x;
    tie(v, x) = e[u][0];
    int f[2][2][2][2] {};
    int cur = 0;
    f[0][0][0][0] = 1;
    f[0][0][1][1] = 1;
    f[0][1][0][1] = 1;
    f[0][1][1][1] = 1;
    while (!visited[v]) {
        visited[v] = true;
        cur ^= 1;
        memset(f[cur], 0, 8 * sizeof(int));
        for (int s = 0; s < 2; ++s)
            for (int l = 0; l < 2; ++l)
                for (int t = 0; t < 2; ++t)
                    for (int c = 0; c < 2; ++c)
                        inc(f[cur][s][c][t ^ ((l ^ x) | c)], f[cur ^ 1][s][l][t]);
        int lst = u;
        u = v;
        tie(v, x) = e[u][0];
        if (v == lst)
            tie(v, x) = e[u][1];
    }
    dp[0] = (f[cur][0][x][0] + f[cur][1][x ^ 1][0]) % P;
    dp[1] = (f[cur][0][x][1] + f[cur][1][x ^ 1][1]) % P;
    update();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ans[0] = 1;
    cin >> n >> m;
    memset(lst, -1, m * sizeof(int));
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            int x;
            cin >> x;
            bool g = x < 0;
            x = abs(x) - 1;
            if (lst[x] == -1) {
                lst[x] = i;
                neg[x] = g;
            } else {
                e[i].emplace_back(lst[x], g ^ neg[x]);
                e[lst[x]].emplace_back(i, g ^ neg[x]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (e[i].empty())
            solveVertex(i);
    for (int i = 0; i < n; ++i)
        if (!visited[i] && (int)e[i].size() == 1)
            solveChain(i);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            solveCircle(i);
    for (int i = 0; i < m; ++i)
        if (lst[i] == -1)
            ans[1] = 2 * ans[1] % P;
    cout << ans[1] << endl;
    return 0;
}