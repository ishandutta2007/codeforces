#include <bits/stdc++.h>

using i64 = long long;
struct DSU {
    std::vector<int> f, siz, mn, mx;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0), mn = mx = f; }
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
        mn[x] = std::min(mn[x], mn[y]);
        mx[x] = std::max(mx[x], mx[y]);
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
    int min(int x) { return mn[leader(x)]; }
    int max(int x) { return mx[leader(x)]; }
};

void solve() {
    int n;
    std::cin >> n;
    
    std::vector good(n, std::vector<bool>(n));
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n - i; j++) {
            good[i][i + j] = s[j] - '0';
        }
    }
    DSU dsu(n);
    
    std::vector<int> nxt(n);
    std::iota(nxt.begin(), nxt.end(), 0);
    
    for (int len = 0; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            if (!good[i][i + len]) {
                continue;
            }
            if (dsu.same(i, i + len)) {
                continue;
            }
            std::vector<int> a;
            for (int j = i; j <= i + len; j++) {
                if (a.empty() || dsu.leader(j) != dsu.leader(a.back())) {
                    a.push_back(j);
                }
            }
            assert(a.size() != 3);
            if (a.size() == 2) {
                int x = std::max(i, dsu.min(a[0]));
                int y = std::min(i + len, dsu.max(a[1]));
                std::cout << x + 1 << " " << y + 1 << "\n";
                dsu.merge(x, y);
            } else {
                std::vector<int> b;
                int l = 0, r = a.size() - 1, t = 0;
                while (l < r) {
                    if (!t) {
                        b.push_back(a[l++]);
                    } else {
                        b.push_back(a[r--]);
                    }
                    t ^= 1;
                }
                b.insert(b.begin(), a[l]);
                for (int j = 0; j < int(b.size()) - 1; j++) {
                    int x = b[j], y = b[j + 1];
                    if (x > y) {
                        std::swap(x, y);
                    }
                    x = std::max(i, dsu.min(x));
                    y = std::min(i + len, dsu.max(y));
                    std::cout << x + 1 << " " << y + 1 << "\n";
                    dsu.merge(x, y);
                }
            }
        }
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