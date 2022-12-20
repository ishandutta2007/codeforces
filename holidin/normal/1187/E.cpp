#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;

long long dp[N], h[N], sz[N], ans = 0, n;
vector <int> e[N];

void dfs1(int u, int pr) {
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs1(e[u][i], u);
        sz[u] += sz[e[u][i]];
        dp[u] += dp[e[u][i]];
    }
    dp[u] += sz[u];
}

void dfs2(int u, int pr) {
    long long sum = n + h[u] + dp[u] - sz[u], x = h[u] + dp[u] - sz[u];
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        h[e[u][i]] = x - dp[e[u][i]] + n - sz[e[u][i]];
        dfs2(e[u][i], u);
    }
    ans = max(ans, sum);
}

int main() {
    int i, j, k, test, v, u;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    cout << ans;
}