#include <bits/stdc++.h>

using i64 = long long;
struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> parent(n), dep(n);
    parent[0] = -1;
    
    auto dfs = [&](auto self, int u) -> void {
        for (auto v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            dep[v] = dep[u] + 1;
            parent[v] = u;
            self(self, v);
        }
    };
    dfs(dfs, 0);
    
    auto getPath = [&](int u, int v) -> std::vector<int> {
        std::vector<int> l, r;
        while (u != v) {
            if (dep[u] > dep[v]) {
                l.push_back(u);
                u = parent[u];
            } else {
                r.push_back(v);
                v = parent[v];
            }
        }
        l.push_back(u);
        l.insert(l.end(), r.rbegin(), r.rend());
        return l;
    };
    
    std::vector<std::array<char, 2>> cand(n, {'a', 'b'});
    
    std::vector<std::tuple<int, int, std::string>> res(q);
    for (int i = 0; i < q; i++) {
        int u, v;
        std::string s;
        std::cin >> u >> v >> s;
        u--;
        v--;
        res[i] = {u, v, s};
        
        auto p = getPath(u, v);
        int l = p.size();
        for (int j = 0; j < l; j++) {
            cand[p[j]][0] = s[j];
            cand[p[j]][1] = s[l - j - 1];
        }
    }
    
    TwoSat ts(n + q);
    
    for (int i = 0; i < q; i++) {
        auto [u, v, s] = res[i];
        auto p = getPath(u, v);
        int l = p.size();
        for (int j = 0; j < l; j++) {
            for (int x = 0; x < 2; x++) {
                if (cand[p[j]][x] != s[j]) {
                    ts.addClause(p[j], !x, n + i, 1);
                }
                if (cand[p[j]][x] != s[l - j - 1]) {
                    ts.addClause(p[j], !x, n + i, 0);
                }
            }
        }
    }
    
    if (ts.satisfiable()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
        return 0;
    }
    
    auto ans = ts.answer();
    for (int i = 0; i < n; i++) {
        std::cout << cand[i][ans[i]];
    }
    std::cout << "\n";
    
    return 0;
}