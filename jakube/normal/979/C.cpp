#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int dfs(int v, int p, int x, bool b) {
    int c = v == x || b;
    for (int u : adj[v]) {
        if (u == p) continue;
        c += dfs(u, v, x, b || x == v);
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long c1 = dfs(y, -1, x, false);
    long long c2 = dfs(x, -1, y, false);
    cout << (long long)n * (n-1) - c1 * c2 << '\n';
}