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

void computePrimesSmallest(int n, std::vector<int> &smallest)
{
    smallest.resize(n + 1);
    std::iota(smallest.begin(), smallest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == smallest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                smallest[j] = min(i, smallest[j]);
            }
        }
    }
}

template <int MOD>
class Modular {
public:
    Modular(long long v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return power(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    int value;
    static const int MOD_value = MOD;
};

using ModInt = Modular<1'000'000'007>;

struct Query
{
    int u, v, lca, x;
    ModInt ans = 1;
};

vector<vector<int>> adj;
vector<int> smallest;
vector<int> a;

void dfs(int v, int p, vector<int>& parent) {
    parent[v] = p;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, parent);
        }
    }
}

void dfs1(int v, int p, int prime, vector<int>& max_e) {
    int x = a[v];
    while (x % prime == 0) {
        x /= prime;
        max_e[v]++;
    }

    for (int u : adj[v]) {
        if (u != p) {
            dfs1(u, v, prime, max_e);
        }
    }
}

void dfs2(int v, int p, int e, int s, vector<int>& max_e, vector<int>& sums) {
    sums[v] = s + min(e, max_e[v]);
    for (int u : adj[v]) {
        if (u != p) {
            dfs2(u, v, e, sums[v], max_e, sums);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computePrimesSmallest(1e7, smallest);

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
    LCA lca(adj, n);

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    vector<Query> queries(q);
    map<int, map<int, vector<int>>> m;
    for (int i = 0; i < q; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        queries[i] = {u, v, lca.query(u, v), x};
        while (x > 1) {
            int p = smallest[x];
            int cnt = 0;
            do {
                x /= p;
                cnt++;
            } while (smallest[x] == p);
            m[p][cnt].push_back(i);
        }
    }

    vector<int> parent(n);
    dfs(0, -1, parent);
    for (const auto& [p, data] : m) {
        vector<int> max_e(n, 0);
        dfs1(0, 0, p, max_e);
        vector<int> sums(n, 0);
        for (const auto& [e, indices] : data) {
            dfs2(0, 0, e, 0, max_e, sums);
            for (int i : indices) {
                int c = 0;
                auto& q = queries[i];
                c += sums[q.u];
                c += sums[q.v];
                c -= sums[q.lca];
                if (parent[q.lca] >= 0)
                    c -= sums[parent[q.lca]];
                q.ans *= power(ModInt(p), c);
            }
        }
    }

    for (auto& q : queries) {
        cout << q.ans << '\n';
    }
}