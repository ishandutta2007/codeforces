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
    
    int n, d;
    std::cin >> n >> d;
    
    DSU g(n);
    
    int extra = 0;
    while (d--) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        if (!g.merge(x, y)) {
            extra++;
        }
        
        std::vector<int> a;
        for (int i = 0; i < n; i++) {
            if (g.leader(i) == i) {
                a.push_back(g.size(i));
            }
        }
        
        std::sort(a.begin(), a.end(), std::greater());
        
        std::cout << std::accumulate(a.begin(), a.begin() + extra + 1, 0) - 1 << "\n";
    }
    
    return 0;
}