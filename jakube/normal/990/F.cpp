#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edges;
vector<bool> finished;
vector<int> value;
vector<int> b;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;

int dfs(int v, int p = -1) {
    visited[v] = true;
    int sum = 0;
    for (auto [u, i]: adj[v]) {
        if (u == p) continue;
        if (finished[i]) continue;

        if (!visited[u]) {
            int x = dfs(u, v);
            sum -= x;
            value[i] = edges[i].first == v ? x : -x;
        } else {
            value[i] = 0;
        }
        finished[i] = true;
    }
    return b[v] - sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int m;
    cin >> m;
    adj.resize(n);
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges[i] = {u, v};
    }

    visited.assign(n, false);
    finished.assign(m, false);
    value.assign(m, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i) != 0) {
                cout << "Impossible" << '\n';
                return 0;
            }
        }
    }

    cout << "Possible" << '\n';
    for (auto x : value) {
        cout << x << '\n';
    }
}