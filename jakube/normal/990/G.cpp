#include <bits/stdc++.h>
using namespace std;

vector<int> cur;
vector<int> color;
vector<vector<int>> adj;

vector<vector<int>> vertices;
vector<vector<pair<int, int>>> edges;
int ma = 200'001;

int dfs(int v) {
    int size = 1;
    color[v] = 2;
    for (auto u : adj[v]) {
        if (color[u] == 2)
            continue;
        size += dfs(u);
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vertices.resize(ma);
    edges.resize(ma);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vertices[a[i]].push_back(i);
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[gcd(a[u], a[v])].push_back({u, v});
    }

    color.assign(n, 0);
    adj.resize(n);

    vector<long long> dp(ma, 0);
    for (int i = 1; i < ma; i++) {
        for (int j = i; j < ma; j += i) {
            for (int v : vertices[j]) {
                color[v] = 1;
                cur.push_back(v);
            }
            for (auto [u, v] : edges[j]) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        for (int x : cur) {
            if (color[x] == 1) {
                int size = dfs(x);
                dp[i] += (long long)size * (size + 1) / 2;
            }
        }
        for (int x : cur) {
            color[x] = 0;
            adj[x].clear();
        }
        cur.clear();
    }

    for (int i = ma - 1; i > 0; i--) {
        for (int j = i + i; j < ma; j += i) {
            dp[i] -= dp[j];
        }
    }

    for (int i = 1; i < ma; i++) {
        if (dp[i])
            cout << i << " " << dp[i] << '\n';
    }
}