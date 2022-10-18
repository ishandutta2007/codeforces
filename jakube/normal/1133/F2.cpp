#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    int size = 1;
    for (auto u : adj[v]) {
        if (visited[u])
            continue;
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    visited.assign(n, false);
    visited[0] = true;

    vector<int> comps;
    for (int v : adj[0]) {
        if (visited[v])
            continue;
        dfs(v);
        comps.push_back(v);
    }

    if (!(comps.size() <= k && k <= adj[0].size())) {
        cout << "NO" << endl;
        return 0;
    }

    std::vector<bool> found(n, false);
    std::queue<std::pair<int, int>> q;
    std::vector<int> dist_to_start(n);
    q.push({0, 0});
    found[0] = true;
    cout << "YES" << '\n';
    for (int v : comps) {
        q.push({v, 0});
        found[v] = true;
        cout << 1 << " " << v + 1 << "\n";
    }

    int taken = comps.size();
    while (!q.empty()) {
        auto p = q.front();
        int cur = p.first;
        int dist = p.second;
        q.pop();

        dist_to_start[cur] = dist;

        for (auto next : adj[cur]) {
            if (cur == 0 && taken == k)
                continue;
            if (!found[next]) {
                cout << cur + 1 << " " << next + 1 << "\n";
                q.push({next, dist + 1});
                found[next] = true;
                if (cur == 0)
                    taken++;
            }
        }
    }
}