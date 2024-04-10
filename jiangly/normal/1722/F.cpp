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

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    const int N = n * m;
    DSU dsu(N);
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && s[i + 1][j] == s[i][j]) {
                dsu.merge(i * m + j, (i + 1) * m + j);
            }
            if (j + 1 < m && s[i][j + 1] == s[i][j]) {
                dsu.merge(i * m + j, i * m + j + 1);
            }
        }
    }
    
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*' && dsu.size(i * m + j) != 3) {
                ok = false;
            }
            if (i + 2 < n && s[i][j] == '*' && dsu.same(i * m + j, (i + 2) * m + j)) {
                ok = false;
            }
            if (j + 2 < m && s[i][j] == '*' && dsu.same(i * m + j, i * m + j + 2)) {
                ok = false;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && j + 1 < m && s[i + 1][j + 1] == s[i][j]) {
                dsu.merge(i * m + j, (i + 1) * m + j + 1);
            }
            if (i > 0 && j + 1 < m && s[i - 1][j + 1] == s[i][j]) {
                dsu.merge(i * m + j, (i - 1) * m + j + 1);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*' && dsu.size(i * m + j) != 3) {
                ok = false;
            }
        }
    }
    
    if (ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}