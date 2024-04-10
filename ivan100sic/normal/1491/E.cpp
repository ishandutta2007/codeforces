// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

int fib[30];
int n;

struct edge {
    int block, v;
    ull hsh;
};

vector<edge> e[200005];
map<ull, bool> cache;

int sz[200005];
int parent[200005];

void dfs1(int x, int p, vector<int>& vis, ull& h) {
    sz[x] = 1;
    vis.push_back(x);
    for (int i = 0; i < (int)e[x].size(); i++) {
        auto& [block, v, hsh] = e[x][i];
        if (block || v == p) continue;
        h ^= hsh;
        parent[v] = x;
        dfs1(v, x, vis, h);
        sz[x] += sz[v];
    }
}

void set_block(int u, int v, int block) {
    for (auto& g : e[u]) {
        if (g.v == v) {
            g.block = 1;
            return;
        }
    }
}

bool solve(int x, int ord) {
    if (ord <= 4) return true;

    vector<int> vis;
    ull h = 0;
    dfs1(x, x, vis, h);
    auto it = cache.lower_bound(h);
    if (it != cache.end() && it->first == h) {
        return it->second;
    }

    vector<array<int, 4>> to_block;
    for (int x : vis) {
        if (sz[x] == fib[ord-1]) {
            to_block.push_back({x, parent[x], ord-1, ord-2});
        } else if (sz[x] == fib[ord-2]) {
            to_block.push_back({x, parent[x], ord-2, ord-1});
        }
    }

    bool result = false;

    for (auto [u, v, ou, ov] : to_block) {
        set_block(u, v, 1);
        set_block(v, u, 1);

        if (solve(u, ou) && solve(v, ov)) {
            result = true;
        }

        set_block(u, v, 0);
        set_block(v, u, 0);

        if (result) {
            break;
        }
    }

    cache.emplace_hint(it, h, result);
    return result;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    fib[1] = 1;
    for (int i=2; i<30; i++) fib[i] = fib[i-1] + fib[i-2];

    cin >> n;
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        unsigned h = eng();
        e[x].push_back({0, y, h});
        e[y].push_back({0, x, h});
    }

    for (int i=1; i<=n; i++) {
        if (e[i].size() >= 30) {
            cout << "NO\n";
            return 0;
        }
    }

    int ord = find(fib+2, fib+30, n) - fib;
    if (ord == 30) {
        cout << "NO\n";
        return 0;
    }

    cout << (solve(1, ord) ? "YES\n" : "NO\n");
}