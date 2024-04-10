#include <bits/stdc++.h>

using int64 = long long;

inline int64 Ceil(int64 x, int64 y) { return (x + y - 1) / y; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(n);
        for (int &x : a) std::cin >> x;
        std::vector<int> p(m), q(m);
        std::vector<std::vector<int> > b(n);
        std::vector<int64> g(m);
        for (int i = 0; i < m; ++i) {
            int k;
            std::cin >> k;
            b[i].resize(k);
            for (int &x : b[i]) std::cin >> x, g[i] += x;
            p[i] = i;
        }
        std::sort(a.begin(), a.end(), [&](int x, int y) { return x > y; });
        std::sort(p.begin(), p.end(), [&](int x, int y) {
            return g[x] * b[y].size() > g[y] * b[x].size();
        });
        std::vector<int> pre(m), lp(m), rp(m);
        auto Get = [&](int x) { return Ceil(g[x], b[x].size()); };
        auto Dec = [&](int x, int i) {
            return Ceil(g[x] - b[x][i], b[x].size() - 1);
        };
        for (int i = 0; i < m; ++i) pre[i] = Get(p[i]) <= a[i];
        for (int i = 1; i < m; ++i) {
            lp[i] = Get(p[i]) <= a[i - 1];
            rp[i - 1] = Get(p[i - 1]) <= a[i];
        }
        for (int i = 1; i < m; ++i) {
            pre[i] += pre[i - 1];
            lp[i] += lp[i - 1];
            rp[i] += rp[i - 1];
        }
        auto V = [&](std::vector<int> &v, int x) {
            return x >= 0 ? x < v.size() ? v[x] : v.back() : 0;
        };
        auto Pre = [&](int l, int r) { return V(pre, r) - V(pre, l - 1); };
        auto Lp = [&](int l, int r) { return V(lp, r) - V(lp, l - 1); };
        auto Rp = [&](int l, int r) { return V(rp, r) - V(rp, l - 1); };
        for (int i = 0; i < m; ++i) q[p[i]] = i;
        for (int i = 0; i < m; ++i) {
            int x = q[i];
            for (int j = 0; j < b[i].size(); ++j) {
                auto Let = [&](int x) { return x == -1 ? Dec(i, j) : Get(x); };
                int y = std::lower_bound(
                            p.begin(), p.end(), -1,
                            [&](int x, int y) { return Let(x) > Let(y); }) -
                        p.begin();
                int Ans = 0;
                if (x >= y) {
                    Ans = Pre(0, y - 1) + Pre(x + 1, m - 1) + Rp(y, x - 1) +
                          (Let(-1) <= a[y]);
                } else {
                    Ans = Pre(0, x - 1) + Pre(y, m - 1) + Lp(x + 1, y - 1) +
                          (Let(-1) <= a[y - 1]);
                }
                std::cout << (Ans == m);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}