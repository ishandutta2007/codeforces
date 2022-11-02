#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x), y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y], f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void Solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    auto work = [&](auto a) {
        DSU dsu(30);
        std::vector<bool> use(30);
        int Ans = 0, T = 30;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) ++a[i], ++Ans;
            int x = __builtin_ctz(a[i]);
            for (int j = x; j < 30; ++j) {
                if (a[i] >> j & 1) use[j] = true, dsu.merge(x, j);
            }
            T = std::min(T, x);
        }
        bool ok = true;
        for (int i = 0; i < 30; ++i) {
            if (use[i] && !dsu.same(T, i)) ok = false;
        }
        if (ok) return std::pair(Ans, a);
        for (int i = 0; i < n; ++i) {
            int x = __builtin_ctz(a[i]);
            if (T > 0) T = 0, ++a[i], ++Ans, dsu.merge(0, x);
            if (!dsu.same(0, x)) ++a[i], ++Ans, dsu.merge(0, x);
        }

        return std::pair(Ans, a);
    };
    auto Ans = work(a);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) continue;
        --a[i];
        auto res = work(a);
        ++a[i];
        if (++res.first < Ans.first) Ans = res;
    }
    std::cout << Ans.first << "\n";
    for (int i = 0; i < n; ++i) std::cout << Ans.second[i] << " \n"[i == n - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}