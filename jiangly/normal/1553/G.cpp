#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 5;

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
    
    std::vector<int> minp(N + 1), nxt(N + 1);
    minp[1] = N + 1;
    std::vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            minp[i * p] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
    
    for (int i = 2; i <= N; i++) {
        int x = i;
        while (x % minp[i] == 0) {
            x /= minp[i];
        }
        nxt[i] = x;
    }
    
    int n, q;
    std::cin >> n >> q;
    
    DSU g(N + 1);
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int x = a[i];
        while (x != 1) {
            g.merge(a[i], minp[x]);
            x /= minp[x];
        }
    }
    
    std::vector<std::vector<int>> e(N + 1);
    for (int i = 0; i < n; i++) {
        for (int x = a[i]; x > 1; ) {
            for (int y = a[i] + 1; y > 1; ) {
                int u = g.leader(minp[x]);
                int v = g.leader(minp[y]);
                if (u != v) {
                    e[u].push_back(v);
                    e[v].push_back(u);
                }
                y = nxt[y];
            }
            x = nxt[x];
        }
        for (int x = a[i] + 1; x > 1; ) {
            for (int y = a[i] + 1; y > 1; ) {
                int u = g.leader(minp[x]);
                int v = g.leader(minp[y]);
                if (u != v) {
                    e[u].push_back(v);
                    e[v].push_back(u);
                }
                y = nxt[y];
            }
            x = nxt[x];
        }
    }
    
    for (int i = 2; i <= N; i++) {
        std::sort(e[i].begin(), e[i].end());
        e[i].erase(std::unique(e[i].begin(), e[i].end()), e[i].end());
    }
    
    while (q--) {
        int i, j;
        std::cin >> i >> j;
        i--;
        j--;
        if (g.same(a[i], a[j])) {
            std::cout << "0\n";
        } else {
            int x = g.leader(a[i]);
            if (std::binary_search(e[x].begin(), e[x].end(), g.leader(a[j]))) {
                std::cout << "1\n";
            } else {
                std::cout << "2\n";
            }
        }
    }
    
    return 0;
}