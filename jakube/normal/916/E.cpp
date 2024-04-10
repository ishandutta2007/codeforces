#include <bits/stdc++.h>
using namespace std;

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(int n) : n(n)
    {
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
    }

    SegmentTreeRecLazy(std::vector<int> const& v) {
        n = v.size();
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
        build(v);
    }

    void build(std::vector<int> const& v, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l == r - 1) {
            data[id] = v[l];
        } else {
            int m = (l + r) >> 1;
            build(v, id << 1, l, m);
            build(v, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
        }
    }

    long long sum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return 0;
        } else if (x <= l && r <= y) {
            return data[id];
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            return sum(x, y, id << 1, l, m) + sum(x, y, id << 1 | 1, m, r);
        }
    }

    void update(int x, int y, long long addend, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
        } else if (x <= l && r <= y) {
            data[id] += (r - l) * addend;
            todo[id] += addend;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            update(x, y, addend, id << 1, l, m);
            update(x, y, addend, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
        }
    }

private:
    void push(int id, int l, int r)
    {
        int m = (l + r) >> 1;
        data[id << 1] += (m - l) * todo[id];
        todo[id << 1] += todo[id];
        data[id << 1 | 1] += (r - m) * todo[id];
        todo[id << 1 | 1] += todo[id];
        todo[id] = 0;
    }

    int n;
    std::vector<long long> data, todo;
};

class LCA_Binary_Lifting
{
public:
    LCA_Binary_Lifting(std::vector<std::vector<int>> adj, int root)
        : root(root), adj(adj)
    {
        int n = adj.size();

        log = 1;
        while ((1 << log) < n)
            log++;
        parents.assign(log, std::vector<int>(n, -1));

        height.resize(n);
        dfs(root, -1, 0);

        for (int l = 1; l < log; l++) {
            for (int v = 0; v < n; v++) {
                if (parents[l - 1][v] >= 0)
                    parents[l][v] = parents[l - 1][parents[l - 1][v]];
            }
        }
    }

    int find_parent(int v, int up)
    {
        for (int l = 0; v != -1 && up > 0; l++, up >>= 1) {
            if (up & 1) {
                v = parents[l][v];
            }
        }
        return v;
    }

    int LCA(int u, int v)
    {
        if (height[u] < height[v])
            std::swap(u, v);
        u = find_parent(u, height[u] - height[v]);

        for (int l = log - 1; l >= 0; l--) {
            if (parents[l][u] != parents[l][v]) {
                u = parents[l][u];
                v = parents[l][v];
            }
        }

        if (u == v)
            return u;
        else
            return parents[0][u];
    }

    void dfs(int v, int p, int h)
    {
        parents[0][v] = p;
        height[v] = h;
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, h + 1);
        }
    }

    int log;
    int root;
    std::vector<std::vector<int>> adj, parents;
    std::vector<int> height;
};



vector<int> cost;
vector<vector<int>> adj;
vector<int> euler;
std::vector<int> first_encounter, last_encounter;
int x = 0;

void dfs_euler_tour(int v, int p) {
    euler[x] = cost[v];
    first_encounter[v] = x;
    x++;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        dfs_euler_tour(u, v);
    }
    last_encounter[v] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    cost.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    euler.resize(n);
    first_encounter.resize(n);
    last_encounter.resize(n);
    dfs_euler_tour(0, -1);
    SegmentTreeRecLazy st(euler);

    LCA_Binary_Lifting lca(adj, 0);
    int root = 0;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            root = v - 1;
        }
        if (t == 2) {
            int u, v, x;
            cin >> u >> v >> x;
            u--;
            v--;
            int w = lca.LCA(u, v) ^ lca.LCA(u, root) ^ lca.LCA(v, root);
            int y = lca.LCA(w, root);
            if (w == root) {
                st.update(0, n, x);
            } else if (y == w) {
                st.update(0, n, x);
                int z = lca.find_parent(root, lca.height[root] - lca.height[w] - 1);
                st.update(first_encounter[z], last_encounter[z], -x);
            } else {
                st.update(first_encounter[w], last_encounter[w], x);
            }
        }
        if (t == 3) {
            int v;
            cin >> v;
            v--;
            int y = lca.LCA(v, root);
            long long ans;
            if (v == root) {
                ans = st.sum(0, n);
            } else if (y == v) {
                ans = st.sum(0, n);
                int z = lca.find_parent(root, lca.height[root] - lca.height[v] - 1);
                ans -= st.sum(first_encounter[z], last_encounter[z]);
            } else {
                ans = st.sum(first_encounter[v], last_encounter[v]);
            }
            cout << ans << '\n';
        }
    }
}