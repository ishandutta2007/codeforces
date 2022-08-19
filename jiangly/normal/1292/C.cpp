#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3'000;
int n;
vector<int> e[N];
int dis[N][N], sz[N][N];
long long dp[N][N];
void dfs(int u, int p, int root) {
    sz[root][u] = 1;
    for (int v : e[u]) {
        if (v != p) {
            dfs(v, u, root);
            sz[root][u] += sz[root][v];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
        fill(dis[i], dis[i] + n, -1);
    for (int i = 0; i < n; ++i)
        dfs(i, -1, i);
    queue<pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0;
        que.emplace(i, i);
    }
    while (!que.empty()) {
        auto [u, v] = que.front();
        que.pop();
        for (int x : e[u]) {
            int y = v;
            if (x > y)
                swap(x, y);
            if (dis[x][y] == -1) {
                dis[x][y] = dis[u][v] + 1;
                dp[x][y] = dp[u][v] + sz[x][y] * sz[y][x];
                que.emplace(x, y);
            } else if (dis[x][y] == dis[u][v] + 1) {
                dp[x][y] = max(dp[x][y], dp[u][v] + sz[x][y] * sz[y][x]);
            }
        }
        for (int x : e[v]) {
            int y = u;
            if (x > y)
                swap(x, y);
            if (dis[x][y] == -1) {
                dis[x][y] = dis[u][v] + 1;
                dp[x][y] = dp[u][v] + sz[x][y] * sz[y][x];
                que.emplace(x, y);
            } else if (dis[x][y] == dis[u][v] + 1) {
                dp[x][y] = max(dp[x][y], dp[u][v] + sz[x][y] * sz[y][x]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, *max_element(dp[i], dp[i] + n));
    cout << ans << endl;
    return 0;
}