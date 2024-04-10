#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > adj[best].size()) {
            best = i;
        }
    }

    int start = best;

    std::vector<bool> found(n, false);
    std::queue<std::pair<int, int>> q;
    std::vector<int> dist_to_start(n);

    q.push({start, 0});
    found[start] = true;

    while (!q.empty()) {
        auto p = q.front();
        int cur = p.first;
        int dist = p.second;
        q.pop();

        dist_to_start[cur] = dist;

        for (auto next : adj[cur]) {
            if (!found[next]) {
                cout << cur + 1 << " " << next + 1 << "\n";
                q.push({next, dist + 1});
                found[next] = true;
            }
        }
    }
}