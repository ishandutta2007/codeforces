#include <bits/stdc++.h>

const int P = 998244353;

int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P) {
        if (b & 1) res = 1ll * res * a % P;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> add(n + 1), del(n + 1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        add[l].push_back(i);
        del[r].push_back(i);
    }
    std::vector<int> a(m), b(m);
    std::vector<int> id(n, -1);
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> b[i];
        --a[i], --b[i];
        if (id[a[i]] == -1) id[a[i]] = cnt++;
        if (id[b[i]] == -1) id[b[i]] = cnt++;
    }
    std::vector<int> fac(n + 1), invFac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
    invFac[n] = power(fac[n], P - 2);
    for (int i = n; i; --i) invFac[i - 1] = 1ll * invFac[i] * i % P;
    std::vector<int> ways(m + 1);
    std::vector<int> in(n);
    int64_t mask = 0;
    ways[0] = 1;
    int tot = 0, tp = 0;
    int ans = 0;
    auto C = [&](int n, int m) {
        if (n < m || m < 0) return 0;
        return (int)(1ll * fac[n] * invFac[m] % P * invFac[n - m] % P);
    };
    for (int i = 1; i <= n; ++i) {
        for (auto x : add[i]) in[x] = 1, ++(id[x] == -1 ? tot : tp);
        int64_t nMask = 0;
        for (int j = 0; j < m; ++j) {
            if (in[a[j]]) nMask |= 1ll << id[a[j]];
            if (in[b[j]]) nMask |= 1ll << id[b[j]];
        }
        if (nMask != mask) {
            mask = nMask;
            std::fill(ways.begin(), ways.end(), 0);
            std::function<void(int, int64_t, int)> dfs = [&](int x, int64_t s,
                                                             int coef) {
                if (x == m) {
                    int p = __builtin_popcountll(s);
                    for (int j = 0; j <= m; ++j) {
                        ways[j] = (ways[j] + 1ll * coef * C(tp - p, j - p)) % P;
                    }
                    return;
                }
                if (in[a[x]] && in[b[x]]) {
                    dfs(x + 1, s | 1ll << id[a[x]] | 1ll << id[b[x]], P - coef);
                }
                dfs(x + 1, s, coef);
            };
            dfs(0, 0, 1);
        }
        for (int j = 0; j <= m; ++j) {
            ans = (ans + 1ll * ways[j] * C(tot, i - j)) % P;
        }
        for (auto x : del[i]) in[x] = 0, --(id[x] == -1 ? tot : tp);
    }
    std::cout << ans << "\n";
    return 0;
}