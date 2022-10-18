#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, idx;
};

vector<vector<Edge>> adj;

vector<int> side;
vector<Edge> odd_cycle;
vector<Edge> pre;

bool bipartite(int v=0, int p = -1, int s = 0, int idx = -1)
{
    if (p == -1)
        side.assign(adj.size(), -1);

    if (side[v] >= 0) {
        if (side[v] == s)
            return true;

        odd_cycle.push_back({p, idx});
        int cur = p;
        do {
            odd_cycle.push_back(pre[cur]);
            cur = pre[cur].to;
        } while (cur != v);

        return false;
    }
    side[v] = s;
    pre[v] = {p, idx};

    for (auto u : adj[v]) {
        if (u.to == p)
            continue;
        if (!bipartite(u.to, v, s ^ 1, u.idx))
            return false;
    }

    return true;
}

vector<long long> weigths;
vector<bool> visited;
vector<int> c;

long long dfs_st(int v, int p=-1, int idx=-1) {
    visited[v] = true;
    long long sum = 0;
    for (auto u : adj[v]) {
        if (u.to == p)
            continue;
        if (!visited[u.to])
            sum += dfs_st(u.to, v, u.idx);
    }

    auto todo = c[v] - sum;
    if (idx >= 0)
        weigths[idx] = todo;
    return todo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    weigths.assign(m, 0);
    visited.assign(n, false);
    pre.resize(n);

    if (bipartite()) {
        array<long long, 2> sum = {{0, 0}};
        for (int i = 0; i < n; i++) {
            sum[side[i]] += c[i];
        }
        if (sum[0] == sum[1]) {
            dfs_st(0);
        } else {
            cout << "NO" << '\n';
            return 0;
        }
    } else {
        int start = odd_cycle.back().to;
        auto todo = dfs_st(start) / 2;
        for (auto e : odd_cycle) {
            weigths[e.idx] += todo;
            todo *= -1;
        }
    }
    cout << "YES" << '\n';
    for (auto w : weigths) {
        cout << w << '\n';
    }
}