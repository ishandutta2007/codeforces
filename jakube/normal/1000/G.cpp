#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, w;
};

vector<int> a;
vector<vector<Edge>> adj;

vector<int> depth;
vector<long long> dp;
// dp[v] = best way of going from v to v (without going up)
vector<vector<int>> parent;
// parent[v][i] = 2^i parent
vector<vector<pair<int, int>>> coming_from;
vector<vector<long long>> dp2;
// dp2[v][i] = sum going from v (not down!) to 2^i up.
vector<long long> upper;

void subtract_if(long long &x, int v, int w) {
    long long y = dp[v] - 2 * w;
    if (y > 0)
        x -= y;
}

void add_if(long long &x, int v, int w) {
    long long y = dp[v] - 2 * w;
    if (y > 0)
        x += y;
}

void dfs(int v, int p, int W) {
    if (p >= 0)
        depth[v] = depth[p] + 1;

    parent[v][0] = p;
    coming_from[v][0] = {v, W};
    for (int i = 0; i < 19 && parent[v][i] != -1; i++) {
        parent[v][i+1] = parent[parent[v][i]][i];
        coming_from[v][i+1] = coming_from[parent[v][i]][i];
    }

    dp[v] = a[v];
    for (auto [u, w] : adj[v]) {
        if (u == p) continue;
        dfs(u, v, w);
        add_if(dp[v], u, w);
    }
}

void dfs2(int v, int p, long long WWW) {
    if (p >= 0) {
        upper[v] = WWW;
    }

    dp2[v][0] = dp[parent[v][0]];
    auto [c, W] = coming_from[v][0];
    subtract_if(dp2[v][0], c, W);
    dp2[v][0] -= W;

    for (int i = 1; i < 20 && parent[v][i] != -1; i++) {
        dp2[v][i] = dp2[v][i-1] + dp2[parent[v][i-1]][i-1];
    }

    for (auto [u, w] : adj[v]) {
        if (u == p) continue;
        long long WWW2 = WWW + dp[v];
        subtract_if(WWW2, u, w);
        dfs2(u, v, max(0LL, WWW2 - 2 * w));
    }
}

long long solve(int u, int v) {
    if (u == v) {
        return dp[u] + upper[u];
    }

    if (depth[u] > depth[v])
        swap(u, v);

    long long ans = 0;
    ans += dp[v];
    int diff = depth[v] - depth[u];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
            ans += dp2[v][i];
            v = parent[v][i];
        }
    }
    if (u == v) {
        return ans + upper[u];
    }

    // else different branches
    ans += dp[u];
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            ans += dp2[u][i];
            ans += dp2[v][i];
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    auto [x, w1] = coming_from[u][0];
    auto [y, w2] = coming_from[v][0];
    int P = parent[u][0];
    ans += dp[P];
    ans -= w1;
    ans -= w2;
    subtract_if(ans, u, w1);
    subtract_if(ans, v, w2);
    return ans + upper[P];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    depth.assign(n, 0);
    dp.assign(n, 0);
    parent.assign(n, vector<int>(20, -1));
    coming_from.assign(n, vector<pair<int, int>>(20, {-1, -1}));
    dp2.assign(n, vector<long long>(20, -1));
    upper.assign(n, 0);
    dfs(0, -1, 0);
    dfs2(0, -1, 0);

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << solve(u, v) << '\n';
    }
}