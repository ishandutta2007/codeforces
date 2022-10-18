#include <bits/stdc++.h>
using namespace std;

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

    friend Modular operator-(Modular const a) {
        return 0 - a;
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

using ModInt = Modular<998244353>;

std::vector<ModInt> fac;
std::vector<ModInt> f_inv;
std::vector<ModInt> inv;

void precompute_factorial(int n) {
    int m = ModInt::MOD_value;
    fac.resize(n + 1, 1);
    inv.resize(n+1, 1);
    f_inv.resize(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i-1] * i;
        inv[i] = -(m / i) * inv[m % i];
        f_inv[i] = f_inv[i-1] * inv[i];
    }
}

ModInt Binomial(int n, int k) {
    return fac[n] * f_inv[k] * f_inv[n-k];
}

std::vector<int> subtree_sizes;
std::vector<bool> blocked;
vector<int> vertices;
vector<vector<int>> adj_x;

int compute_subtree_sizes(int v, int p, std::vector<std::vector<int>> const& adj)
{
    vertices.push_back(v);
    int size = 1;
    for (int u : adj[v]) {
        if (u != p && !blocked[u])
            size += compute_subtree_sizes(u, v, adj);
    }
    return subtree_sizes[v] = size;
}

int k;

using V = vector<ModInt>;
V operator*(V a, V b) {
    V res(k + 1, 0);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++)
            res[i] += a[j] * b[i - j];
    }
    return res;
}

V& operator+=(V& a, V b) {
    for (int i = 0; i <= k; i++)
        a[i] += b[i];
    return a;
}

V total;
vector<V> f, g;

void dfs(int v, int p, vector<vector<int>> const& adj) {
    if (p >= 0) {
        adj_x[v].push_back(p);
        adj_x[p].push_back(v);
    }
    for (auto u : adj[v]) {
        if (blocked[u] || u == p) continue;
        dfs(u, v, adj);
    }
}

void solve(int v, std::vector<std::vector<int>> const& adj)
{
    vertices.clear();
    int size = compute_subtree_sizes(v, v, adj);
    for (auto x : vertices)
        adj_x[x].clear();
    dfs(v, -1, adj);
    bool pushed = true;
    int p = -1;
    while (pushed) {
        pushed = false;
        for (int u : adj[v]) {
            if (u != p && !blocked[u] && subtree_sizes[u] > size / 2) {
                pushed = true;
                p = v;
                v = u;
                break;
            }
        }
    }

    for (int x : vertices) {
        fill(f[x].begin(), f[x].end(), 0);
        fill(g[x].begin(), g[x].end(), 0);
    }
    f[v][0] = 1;
    g[v][0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int x : vertices) {
            for (int y : adj_x[x]) {
                g[y][i] += g[x][i-1];
                if (y != v)
                    f[y][i] += f[x][i-1];
            }
        }
    }

    for (int x : vertices)
        total += f[x] * g[x];

    blocked[v] = true;
    for (int u : adj[v]) {
        if (!blocked[u])
            solve(u, adj);
    }
}

V cycles_in_tree(int n) {
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    total.assign(k+1, 0);
    blocked.assign(n, false);
    subtree_sizes.assign(n, 0);
    adj_x.assign(n, {});
    f.assign(n, V(k+1, 0));
    g.assign(n, V(k+1, 0));

    solve(0, adj);

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m >> k;
    precompute_factorial(k);

    auto a = cycles_in_tree(n);
    auto b = cycles_in_tree(m);

    ModInt res = 0;
    for (int i = 0; i <= k; i++) {
        res += a[i] * b[k - i] * Binomial(k, i);
    }
    cout << res << '\n';
}