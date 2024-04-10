#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<vector<int>> adj;

std::vector<int> bfs(int start) {
    int n = adj.size();
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
                q.push({next, dist + 1});
                found[next] = true;
            }
        }
    }

    return dist_to_start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s >> t;
    s--, t--;
    
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dist_s = bfs(s);
    auto dist_t = bfs(t);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (min(dist_s[i] + 1 + dist_t[j], dist_s[j] + 1 + dist_t[i]) >= dist_s[t] ) {
                cnt++;
            }
        }
    }
    cout << cnt - m << '\n';
}