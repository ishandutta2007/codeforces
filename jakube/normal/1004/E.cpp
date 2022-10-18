#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, w;
};

vector<vector<Edge>> adj;
vector<int> bad_children;
vector<int> depth;
vector<int> parent;
vector<bool> choose;

pair<int, bool> dfs(int v, int p, int back_w, int d, int dep) {
    depth[v] = dep;
    parent[v] = p;
    int m = 0;
    bool children = false;
    for (auto [u, w] : adj[v]) {
        if (u == p) continue;

        auto [mc, b] = dfs(u, v, w, d, dep + 1);
        m = max(m, mc + w);
        children |= b;
    }
    if (m + back_w > d) {
        if (!children)
            bad_children.push_back(v);
        return {m, true};
    }
    return {m, false};
}

bool dfs2(int v, int p, int dist, int d) {
    for (auto [u, w] : adj[v]) {
        if (u == p || choose[u]) continue;
        if (!dfs2(u, v, dist + w, d))
            return false;
    }
    return dist <= d;
}

bool check(vector<int> path, int d) {
    fill(choose.begin(), choose.end(), false);
    for (int v : path) {
        choose[v] = true;
    }
    for (int v : path) {
        if (!dfs2(v, -1, 0, d))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int L = -1; // not possible
    int R = std::numeric_limits<int>::max() / 2; // possible

    depth.resize(n);
    parent.resize(n);
    choose.resize(n);
    while (L + 1 < R) {
        bad_children.clear();
        int M = (L + R) / 2;
        dfs(0, -1, 0, M, 0);
        bool possible = false;
        if (bad_children.size() == 0)
            possible = true;
        if (bad_children.size() == 1) {
            int v = bad_children[0];
            int K = k;
            vector<int> path;
            while (v >= 0 && K > 0) {
                path.push_back(v);
                v = parent[v];
                K--;
            }
            if (check(path, M))
                possible = true;
        }
        if (bad_children.size() == 2) {
            int u = bad_children[0];
            int v = bad_children[1];
            if (depth[u] > depth[v])
                swap(u, v);
            vector<int> path;
            while (depth[v] > depth[u]) {
                path.push_back(v);
                v = parent[v];
            }
            while (u != v) {
                path.push_back(u);
                path.push_back(v);
                u = parent[u];
                v = parent[v];
            }
            path.push_back(u);
            if ((int)path.size() <= k && check(path, M))
                possible = true;
        }

        if (possible)
            R = M;
        else
            L = M;
    }

    cout << R << '\n';
}