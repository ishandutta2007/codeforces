#include "bits/stdc++.h"
using namespace std;

pair<int, int> ask(vector<int> const& v) {
    cout << "? " << v.size();
    for (int x : v)
        cout << " " << x+1;
    cout << endl;
    int node, cnt;
    cin >> node >> cnt;
    return {node - 1, cnt};
}

class SparseTable
{
public:
    SparseTable(std::vector<int> v)
    {
        log_table.assign(v.size() + 1, 0);
        for (auto i = 2UL; i < log_table.size(); i++)
            log_table[i] = log_table[i / 2] + 1;

        sparse_table.assign(log_table.back() + 1, std::vector<int>(v.size()));
        sparse_table[0] = v;
        for (auto row = 1UL; row < sparse_table.size(); row++) {
            for (auto i = 0UL; i + (1 << row) <= v.size(); i++) {
                sparse_table[row][i] =
                    std::min(sparse_table[row - 1][i],
                             sparse_table[row - 1][i + (1 << (row - 1))]);
            }
        }
    }

    int minimum(int l, int r)
    {
        int log = log_table[r - l];
        return std::min(sparse_table[log][l],
                        sparse_table[log][r - (1 << log)]);
    }

private:
    std::vector<int> log_table;
    std::vector<std::vector<int>> sparse_table;
};

class LCA
{
public:
    LCA(std::vector<std::vector<int>> adj) : adj(adj) {
        int nodes = adj.size();
        first_encounter.resize(nodes);
        depth.resize(nodes);
        dfs_euler_tour(0, -1);
        st = new SparseTable(euler_tour);
    }

    ~LCA() {
        delete st;
    }

    int query(int u, int v) {
        int fe1 = first_encounter[u];
        int fe2 = first_encounter[v];
        if (fe1 > fe2)
            std::swap(fe1, fe2);
        int LCA_new_index = st->minimum(fe1, fe2+1);
        int LCA_old_index = new_to_old[LCA_new_index];
        return LCA_old_index;
    }

    int distance(int u, int v) {
        int lca = query(u, v);
        return depth[u] + depth[v] - depth[lca]*2;
    }

private:
    void dfs_euler_tour(int v, int p, int d = 0) {
        depth[v] = d;
        int new_index = new_to_old.size();
        new_to_old.push_back(v);
        first_encounter[v] = euler_tour.size();
        euler_tour.push_back(new_index);

        for (int u : adj[v]) {
            if (u == p)
                continue;

            dfs_euler_tour(u, v, d+1);
            euler_tour.push_back(new_index);
        }
    }

    std::vector<std::vector<int>> adj;
    std::vector<int> euler_tour;
    std::vector<int> first_encounter;
    std::vector<int> new_to_old;
    std::vector<int> depth;
    SparseTable* st;
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LCA lca(adj);

    // find distance and one node of path
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    auto [node, distance] = ask(v);

    // find second node at distance >= dist/2 + 2;
    v.clear();
    for (int i = 0; i < n; i++) {
        if (lca.distance(node, i) >= (distance+1) / 2)
            v.push_back(i);
    }
    auto [node2, distance2] = ask(v);
    assert(distance == distance2);

    int current_dist = lca.distance(node, node2);
    int remaining_dist = distance - current_dist;
    while (remaining_dist) {
        v.clear();
        int goal = (remaining_dist + 1) / 2;
        for (int i = 0; i < n; i++) {
            if ((lca.distance(node, i) >= goal && lca.distance(node2, i) >= goal + current_dist) ||
                (lca.distance(node2, i) >= goal && lca.distance(node, i) >= goal + current_dist))
                v.push_back(i);
        }
        auto [node3, distance3] = ask(v);
        assert(distance == distance3);
        if (lca.distance(node3, node) > lca.distance(node3, node2)) {
            node2 = node3;
        } else {
            node = node3;
        }
        
        current_dist = lca.distance(node, node2);
        remaining_dist = distance - current_dist;
    }
    cout << "! " << node + 1 << " " << node2 + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
        string s;
        cin >> s;
        if (s != "Correct")
            break;
    }
}