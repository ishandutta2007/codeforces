#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dists;
priority_queue<pair<int, int>> pq;

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

vector<vector<pair<int, int>>> ds;

int dfs2(int v, int p=-1) {
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        int m = dfs2(u, v) + 1;
        ds[v].push_back({m, u});
    }
    sort(ds[v].begin(), ds[v].end());
    return dists[v] = (ds[v].size() ? ds[v].back().first : 0);
}

void dfs(int v, int d) {
    dists[v] = -1;

    if (d == 0)
        return;

    auto [dd, u] = ds[v].back();
    dfs(u, d-1);
    ds[v].pop_back();

    if (!ds[v].empty())
        pq.push({ds[v].back().first, v});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto dists0 = bfs(0);
    int farthest = 0;
    for (int i = 0; i < n; i++) {
        if (dists0[i] > dists0[farthest])
            farthest = i;
    }

    dists.resize(n);
    ds.resize(n);
    dfs2(farthest);
    dists[farthest] = -1;
    vector<int> res(n, 1);
    pq.push({*max_element(dists.begin(), dists.end()) + 1, farthest});

    int idx = 1;
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        dfs(cur, d);
        res[idx] = res[idx-1] + d;
        idx++;
    }
    for (int i = idx; i < n; i++) {
        res[i] = res[i-1];
    }

    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}