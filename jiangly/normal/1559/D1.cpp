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
    
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    
    DSU t1(n), t2(n);
    
    for (int i = 0; i < m1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        t1.merge(u, v);
    }
    
    for (int i = 0; i < m2; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        t2.merge(u, v);
    }
    
    int ans = n - 1 - std::max(m1, m2);
    std::cout << ans << "\n";
    
    std::vector<int> v1[n], v2[n];
    while (ans > 0) {
        for (int i = 0; i < n; i++) {
            v1[i].clear();
            v2[i].clear();
        }
        
        for (int i = 0; i < n; i++) {
            v1[t1.leader(i)].push_back(i);
            v2[t2.leader(i)].push_back(i);
        }
        
        int i = 0, j = 0;
        while (true) {
            while (i < n && t1.leader(i) != i) {
                i++;
            }
            while (j < n && t2.leader(j) != j) {
                j++;
            }
            if (i == n || j == n) {
                break;
            }
            
            int a = -1, b = -1, c = -1, d = 0;
            for (auto x : v1[i]) {
                if (!t2.same(x, j)) {
                    a = x;
                } else {
                    c = x;
                }
            }
            for (auto x : v2[j]) {
                if (!t1.same(x, i)) {
                    b = x;
                } else {
                    c = x;
                }
            }
            
            if (a != -1 && b != -1) {
                std::cout << a + 1 << " " << b + 1 << "\n";
                t1.merge(a, b);
                t2.merge(b, a);
            } else {
                while (t1.same(d, i) || t2.same(d, j)) {
                    d++;
                }
                std::cout << c + 1 << " " << d + 1 << "\n";
                t1.merge(c, d);
                t2.merge(c, d);
            }
            ans--;
            
            i++;
            j++;
        }
    }
    
    return 0;
}