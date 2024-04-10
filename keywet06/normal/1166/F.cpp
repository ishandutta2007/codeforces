#include <bits/stdc++.h>

const int N = 100005;

int n, m, c, q, x, y, z;
int f[N];

std::string o;

std::map<int, int> id[N];

std::set<int> rea[N];

inline int find(int u) { return f[u] == u ? u : (f[u] = find(f[u])); }

inline void merge(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (rea[u].size() < rea[v].size()) std::swap(u, v);
    for (int x : rea[v]) rea[u].insert(x);
    f[v] = u;
}

inline void insert(int u, int v, int c) {
    rea[find(u)].insert(v), rea[find(v)].insert(u);
    id[u][c] ? merge(v, id[u][c]) : void(id[u][c] = v);
    id[v][c] ? merge(u, id[v][c]) : void(id[v][c] = u);
}

inline bool solve(int x, int y) { return rea[find(x)].count(y); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> c >> q;
    for (int i = 1; i <= n; ++i) rea[i].insert(i), f[i] = i;
    for (int i = 1; i <= m; ++i) std::cin >> x >> y >> z, insert(x, y, z);
    while (q--) {
        std::cin >> o >> x >> y;
        if (o[0] == '+') std::cin >> z, insert(x, y, z);
        if (o[0] == '?') std::cout << (solve(x, y) ? "Yes" : "No") << '\n';
    }
    return 0;
}