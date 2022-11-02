#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
        --c[i];
    }
    std::vector<bool> good(k, true);
    std::vector<int> a(m), b(m);
    std::vector<int> f(n), d(n), siz(n, 1);
    std::iota(f.begin(), f.end(), 0);
    std::vector<std::pair<int *, int>> his;
    auto leader = [&](int u) {
        int x = u, y = 0;
        while (x != f[x]) {
            y ^= d[x];
            x = f[x];
        }
        return std::make_pair(x, y);
    };
    auto merge = [&](int u, int v, bool rec = false) {
        auto [a, x] = leader(u);
        auto [b, y] = leader(v);
        if (a == b) {
            if (x == y) return false;
            return true;
        } else {
            if (siz[a] < siz[b]) {
                std::swap(a, b);
                std::swap(x, y);
            }
            if (rec) his.emplace_back(&siz[a], siz[a]);
            siz[a] += siz[b];
            if (rec) his.emplace_back(&f[b], f[b]);
            f[b] = a;
            if (rec) his.emplace_back(&d[b], d[b]);
            d[b] = x ^ y ^ 1;
            return true;
        }
    };
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> b[i];
        --a[i], --b[i];
        if (c[a[i]] > c[b[i]]) std::swap(a[i], b[i]);
        if (c[a[i]] == c[b[i]] && !merge(a[i], b[i])) good[c[a[i]]] = false;
    }
    int cnt = std::accumulate(good.begin(), good.end(), 0);
    int64_t ans = int64_t(cnt) * (cnt - 1) / 2;
    std::vector<int> p(m);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return std::make_pair(c[a[i]], c[b[i]]) < std::make_pair(c[a[j]], c[b[j]]); });
    
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && c[a[p[i]]] == c[a[p[j]]] && c[b[p[i]]] == c[b[p[j]]]) ++j;
        if (c[a[p[i]]] != c[b[p[i]]] && good[c[a[p[i]]]] && good[c[b[p[i]]]]) {
            for (int k = i; k < j; ++k) {
                if (!merge(a[p[k]], b[p[k]], true)) {
                    --ans;
                    break;
                }
            }
            while (!his.empty()) {
                *his.back().first = his.back().second;
                his.pop_back();
            }
        }
        i = j;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}