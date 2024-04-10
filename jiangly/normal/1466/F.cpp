#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 1000000007;
struct DSU {
    std::vector<int> f, siz;
    std::vector<bool> g;
    DSU(int n) : f(n), siz(n, 1), g(n) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (g[x] && g[y]) {
            return false;
        }
        siz[x] += siz[y];
        g[x] = g[x] || g[y];
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
    DSU t(m);
    std::vector<int> s;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        if (k == 1) {
            int x;
            std::cin >> x;
            x--;
            x = t.leader(x);
            if (!t.g[x]) {
                t.g[x] = true;
                s.push_back(i);
            }
        } else {
            int x, y;
            std::cin >> x >> y;
            x--;
            y--;
            if (t.merge(x, y)) {
                s.push_back(i);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < int(s.size()); ++i) {
        ans = 2 * ans % P;
    }
    std::cout << ans << " " << s.size() << "\n";
    for (auto x : s) {
        std::cout << x + 1 << " \n"[x == s.back()];
    }
    return 0;
}