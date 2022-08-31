#include <bits/stdc++.h>

using i64 = long long;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    DSU dsu(n);
    std::vector<std::array<int, 2>> edges;
    std::vector<std::vector<int>> adj(n), query(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        if (dsu.merge(u, v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            query[u].push_back(v);
            query[v].push_back(u);
        }
    }
    
    std::vector<int> s(n), nxt(n, -1);
    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        for (auto v : query[u]) {
            if (nxt[v] != -1) {
                s[0]++;
                s[nxt[v]]--;
            } else {
                s[v]++;
            }
        }
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            nxt[u] = v;
            dfs1(v, u);
        }
        nxt[u] = -1;
    };
    dfs1(0, -1);
    
    std::string ans(n, '0');
    std::function<void(int, int)> dfs2 = [&](int u, int p) {
        if (s[u] == m - n + 1) {
            ans[u] = '1';
        }
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            s[v] += s[u];
            dfs2(v, u);
        }
    };
    dfs2(0, -1);
    
    std::cout << ans << "\n";
    
    return 0;
}