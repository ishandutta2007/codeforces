#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int>> adj;

auto bfs(int start, bool b=false) {
    int n = adj.size();
    std::vector<bool> found(n, false);
    std::queue<std::pair<int, int>> q;
    std::vector<int> dist_to_start(n, std::numeric_limits<int>::max());
    std::vector<int> prev(n, -1);

    q.push({start, 0});
    found[start] = true;

    while (!q.empty()) {
        auto p = q.front();
        int cur = p.first;
        int dist = p.second;
        q.pop();

        dist_to_start[cur] = dist;

        for (auto next : adj[cur]) {
            if (b && next == 0)
                continue;
            if (!found[next]) {
                q.push({next, dist + 1});
                found[next] = true;
                prev[next] = cur;
            }
        }
    }

    return make_pair(dist_to_start, prev);
}

vector<bool> visited;
vector<int> comp;

int dfs(int v) {
    visited[v] = true;
    comp.push_back(v);
    int size = 1;
    for (int u : adj[v]) {
        if (!visited[u])
            size += dfs(u);
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto [dist, prev] = bfs(0);

    vector<int> path;
    if (dist[n-1] <= 4) {
        int cur = n-1;
        path.push_back(cur);
        do {
            cur = prev[cur];
            path.push_back(cur);
        } while (cur != 0);
        reverse(path.begin(), path.end());
    } else {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (dist[i] == 2) {
                found = true;
                path.push_back(0);
                path.push_back(prev[i]);
                path.push_back(i);
                path.push_back(0);
                path.push_back(n-1);
                break;
            }
        }

        if (!found) {
            visited.assign(n, false);
            visited[0] = true;
            bool found = false;
            for (int v : adj[0]) {
                if (!visited[v]) {
                    comp.clear();
                    int size = dfs(v);
                    for (int u : comp) {
                        if ((int)adj[u].size() < size) {
                            auto [dist, prev] = bfs(u, true);
                            for (int i = 0; i < n; i++) {
                                if (dist[i] == 2) {
                                    found = true;
                                    path.push_back(0);
                                    path.push_back(u);
                                    path.push_back(prev[i]);
                                    path.push_back(i);
                                    path.push_back(u);
                                    path.push_back(n-1);
                                    break;
                                }
                            }
                        }
                        if (found)
                            break;
                    }
                }
                if (found)
                    break;
            }

            if (!found) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    
    cout << path.size() - 1 << '\n';
    for (auto x : path) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}