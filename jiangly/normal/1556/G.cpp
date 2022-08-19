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
    
    std::vector<i64> v{0LL, 1LL << n};
    
    int op[m];
    i64 x[m], y[m];
    for (int i = 0; i < m; i++) {
        std::string t;
        std::cin >> t;
        if (t == "block") {
            op[i] = 0;
            std::cin >> x[i] >> y[i];
            y[i]++;
            v.push_back(x[i]);
            v.push_back(y[i]);
        } else {
            op[i] = 1;
            std::cin >> x[i] >> y[i];
        }
    }
    
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    
    int N = v.size() - 1;
    for (int i = 0; i < N; i++) {
        i64 l = v[i];
        i64 r = v[i + 1] - 1;
        int k = 0;
        while ((l >> k) != (r >> k)) {
            k++;
        }
        if (k > 0) {
            v.push_back(r & ~((1LL << (k - 1)) - 1));
        }
    }
    
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    
    N = v.size() - 1;
    
    DSU g(N);
    
    std::vector<int> adj[N];
    
    auto add = [&](int i, int j, int k) {
        i64 l = std::max(v[i], v[j] - (1LL << k));
        i64 r = std::min(v[i + 1], v[j + 1] - (1LL << k)) - 1;
        if ((~l >> k & 1) || (~r >> k & 1) || (l >> k) != (r >> k)) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    };
    
    for (int k = 0; k < n; k++) {
        i64 d = 1LL << k;
        for (int i = 0, j = 0; i < N; i++) {
            while (j < N && v[j + 1] <= v[i] + d) {
                j++;
            }
            while (j < N && v[j + 1] <= v[i + 1] + d) {
                add(i, j, k);
                j++;
            }
            if (j < N && v[j] < v[i + 1] + d) {
                add(i, j, k);
            }
        }
    }
    
    bool vis[N];
    std::fill(vis, vis + N, true);
    
    for (int i = 0; i < m; i++) {
        if (op[i] == 0) {
            int j = std::lower_bound(v.begin(), v.end(), x[i]) - v.begin();
            while (v[j] < y[i]) {
                vis[j++] = false;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (vis[i]) {
            for (auto j : adj[i]) {
                if (vis[j]) {
                    g.merge(i, j);
                }
            }
        }
    }
    
    int res[m];
    
    for (int i = m - 1; i >= 0; i--) {
        if (op[i] == 0) {
            int j = std::lower_bound(v.begin(), v.end(), x[i]) - v.begin();
            while (v[j] < y[i]) {
                vis[j] = true;
                for (auto k : adj[j]) {
                    if (vis[k]) {
                        g.merge(j, k);
                    }
                }
                j++;
            }
        } else {
            int a = std::upper_bound(v.begin(), v.end(), x[i]) - v.begin() - 1;
            int b = std::upper_bound(v.begin(), v.end(), y[i]) - v.begin() - 1;
            res[i] = g.same(a, b);
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (op[i] == 1) {
            std::cout << res[i] << "\n";
        }
    }
    
    return 0;
}