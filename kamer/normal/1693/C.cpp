#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;

void dfs(int root, const vector<vector<int>>& graph, vector<int>& dist) {
    if (dist[root] != -2) {
        return;
    }

    vector<int> n_dist;
    for (auto v : graph[root]) {
        dfs(v, graph, dist);
        n_dist.push_back(dist[v]);
    }

    sort(n_dist.begin(), n_dist.end());
    int n = n_dist.size();

    if (n_dist[n - 1] == -1) {
        dist[root] = -1;
        return;
    }

    int index = 0;
    while (n_dist[index] == -1) {
        index++;
    }

    dist[root] = index + n_dist[n - 1] + 1;

    for (int i = n - 2; i >= index; i--) {
        dist[root] = min(dist[root], 1 + index + n - 1 - i + n_dist[i]);
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>());
    vector<int> dist(n, 3 * m);
    vector<int> unfilled(n, 0);
    dist[n - 1] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unfilled[u - 1]++;
        graph[v - 1].push_back(u - 1);
    }

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> q;
    q.emplace(0, n - 1);
    vector<bool> vis(n, false);
    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        if (d > dist[v]) continue;
        if (vis[v]) continue;
        vis[v] = true;

        for (auto u : graph[v]) {
            unfilled[u]--;
            if (dist[u] > dist[v] + 1 + unfilled[u]) {
                // cout << "L " << u + 1 << " " << v + 1 << " " << d << " " << dist[v] << " " << unfilled[u] << "\n";
                dist[u] = dist[v] + 1 + unfilled[u];
                q.emplace(dist[u], u);
            }
        }
    }

    cout << dist[0] << "\n";
}