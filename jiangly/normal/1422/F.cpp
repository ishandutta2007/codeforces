#include <bits/stdc++.h>
constexpr int P = 1000000007, M = 4e7;
struct Node {
    int lc;
    int rc;
    int prod;
} t[M];
int cnt;
int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P)
        if (b & 1) res = 1ll * res * a % P;
    return res;
}
int modify(int p, int l, int r, int x, int v) {
    int u = ++cnt;
    if (r - l == 1) {
        t[u].prod = 1ll * t[p].prod * v % P;
    } else {
        int m = (l + r) / 2;
        if (x < m) {
            t[u].lc = modify(t[p].lc, l, m, x, v);
            t[u].rc = t[p].rc;
        } else {
            t[u].lc = t[p].lc;
            t[u].rc = modify(t[p].rc, m, r, x, v);
        }
        t[u].prod = 1ll * t[t[u].lc].prod * t[t[u].rc].prod % P;
    }
    return u;
}
int query(int p, int l, int r, int x) {
    if (l >= x) return 1;
    if (r <= x) return t[p].prod;
    int m = (l + r) / 2;
    return 1ll * query(t[p].lc, l, m, x) * query(t[p].rc, m, r, x) % P;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int aMax = *std::max_element(a.begin(), a.end());
    // sieve
    std::vector<int> minp(aMax + 1), primes;
    for (int i = 2; i <= aMax; ++i) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > aMax) break;
            minp[i * p] = p;
            if (i % p == 0) break;
        }
    }
    std::vector<std::vector<std::pair<int, int>>> stk(aMax + 1, {std::make_pair(-1, 0)});
    std::vector<int> inv(aMax + 1);
    for (int i = 1; i <= aMax; ++i) inv[i] = power(i, P - 2);
    std::vector<int> rt(n + 1);
    t[0].prod = 1;
    for (int i = 0; i < n; ++i) {
        rt[i + 1] = rt[i];
        int x = a[i];
        while (x > 1) {
            int p = minp[x], q = 1;
            while (minp[x] == p) x /= p, q *= p;
            while (stk[p].size() > 1 && q > stk[p].back().second) {
                auto [pos, u] = stk[p].back();
                stk[p].pop_back();
                rt[i + 1] = modify(rt[i + 1], 0, n, pos + 1, u);
                rt[i + 1] = modify(rt[i + 1], 0, n, stk[p].back().first + 1, inv[u]);
            }
            rt[i + 1] = modify(rt[i + 1], 0, n, stk[p].back().first + 1, q);
            stk[p].emplace_back(i, q);
        }
        if (i + 1 < n) rt[i + 1] = modify(rt[i + 1], 0, n, i + 1, inv[a[i]]);
    }
    int q;
    std::cin >> q;
    int last = 0;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l = (l + last) % n;
        r = (r + last) % n;
        if (l > r) std::swap(l, r);
        ++r;
        std::cout << (last = query(rt[r], 0, n, l + 1)) << "\n";
    }
    
    return 0;
}