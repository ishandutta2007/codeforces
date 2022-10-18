#include <bits/stdc++.h>
using namespace std;

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
    LCA(std::vector<std::vector<int>> adj, int nodes) : adj(adj) {
        first_encounter.resize(nodes);
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

private:
    void dfs_euler_tour(int v, int p) {
        int new_index = new_to_old.size();
        new_to_old.push_back(v);
        first_encounter[v] = euler_tour.size();
        euler_tour.push_back(new_index);

        for (int u : adj[v]) {
            if (u == p)
                continue;

            dfs_euler_tour(u, v);
            euler_tour.push_back(new_index);
        }
    }

    std::vector<std::vector<int>> adj;
    std::vector<int> euler_tour;
    std::vector<int> first_encounter;
    std::vector<int> new_to_old;
    SparseTable* st;
};

struct Query {
    int u, v;
    int l;
    int h1, h2;
    int ans;
};

vector<int> depth;
vector<int> tin, tout;
vector<vector<int>> adj;
int t = 0;

void dfs(int v, int p=-1) {
    tin[v] = t++;
    depth[v] = p >= 0 ? depth[p] + 1 : 0;
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        dfs(u, v);
    }
    tout[v] = t;
}

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, 0);
    }

    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = data[2 * idx] + data[2 * idx + 1];
    }

    void increment(int idx) {
        idx += n;
        data[idx]++;

        while (idx > 1) {
            idx /= 2;
            data[idx] = data[2 * idx] + data[2 * idx + 1];
        }
    }

    int sum(int left, int right) { // interval [left, right)
        int ret = 0;
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) ret += data[left++];
            if (right & 1) ret += data[--right];
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<int> data;
};

vector<Query> queries;
vector<vector<pair<int, int>>> last_queries;
vector<vector<int>> rs;

vector<int> cnt;
SegmentTree st(1);

void dfs_answer(int v, int p=-1) {
    for (auto [u, i] : last_queries[v]) {
        cnt[i] -= st.sum(tin[u], tout[u]);
    }

    for (int u : adj[v]) {
        if (u == p) continue;
        dfs_answer(u, v);
    }

    for (int u : rs[v]) {
        st.increment(tin[u]);
    }

    for (auto [u, i] : last_queries[v]) {
        cnt[i] += st.sum(tin[u], tout[u]);
        if (cnt[i] > 0)
            queries[i].ans--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    p[0] = -1;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    LCA lca(adj, n);
    depth.resize(n);
    tin.resize(n);
    tout.resize(n);
    dfs(0);

    vector<vector<int>> highest(20, vector<int>(n));
    iota(highest[0].begin(), highest[0].end(), 0);
    int m;
    cin >> m;
    vector<pair<int, int>> roads(m);
    rs.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int l = lca.query(u, v);
        highest[0][u] = min(highest[0][u], l);
        highest[0][v] = min(highest[0][v], l);
        rs[u].push_back(v);
        rs[v].push_back(u);
    }
    
    for (int i = n-1; i > 0; i--) {
        highest[0][p[i]] = min(highest[0][p[i]], highest[0][i]);
    }

    for (int j = 1; j < 20; j++) {
        highest[j][0] = 0;
        for (int i = 1; i < n; i++) {
            highest[j][i] = highest[j-1][highest[0][i]];
        }
    }

    int q;
    cin >> q;
    queries.resize(q);
    last_queries.resize(n);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        queries[i].u = u;
        queries[i].v = v;
        int l = lca.query(u, v);
        queries[i].l = l;
        int x = 0;
        for (int j = 19; j >= 0; j--) {
            if (depth[highest[j][u]] > depth[l]) {
                u = highest[j][u];
                x += 1 << j;
            }
        }
        int y = 0;
        for (int j = 19; j >= 0; j--) {
            if (depth[highest[j][v]] > depth[l]) {
                v = highest[j][v];
                y += 1 << j;
            }
        }
        queries[i].ans = x + y;
        queries[i].h1 = u;
        queries[i].h2 = v;
        if (depth[highest[0][u]] <= depth[l] && depth[highest[0][v]] <= depth[l]) {
            if (u == l && v == l) {

            } else if (u == l || v == l) {
                queries[i].ans++;
            } else {
                queries[i].ans += 2;
                last_queries[u].push_back({v, i});
            }
        } else {
            queries[i].ans = -1;
        }
    }

    st = SegmentTree(n);
    cnt.assign(n, 0);
    dfs_answer(0);

    for (auto q : queries) {
        cout << q.ans << '\n';
    }
}