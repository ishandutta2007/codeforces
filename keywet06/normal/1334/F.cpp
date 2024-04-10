#include <bits/stdc++.h>

const long long INF = 1e18;

template <typename T>
struct Fenwick {
    std::vector<T> a;
    void init(int n) { a.assign(n, 0); }
    void add(int x, T v) {
        for (int i = x + 1; i <= int(a.size()); i += i & -i) a[i - 1] += v;
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) ans += a[i - 1];
        return ans;
    }
    T rangeSum(int l, int r) { return sum(r) - sum(l); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) std::cin >> p[i];
    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
        --b[i];
    }
    std::vector<long long> dp(m + 1, INF);
    Fenwick<long long> t;
    t.init(n);
    std::vector<int> pos(n, -1);
    for (int i = 0; i < m; ++i) pos[b[i]] = i;
    long long sneg = 0;
    std::vector<long long> x(n), y(n);
    for (int i = n - 1; i >= 0; --i) {
        if (pos[a[i]] != -1) x[i] = sneg + t.rangeSum(a[i] + 1, n);
        if (p[i] < 0) {
            sneg += p[i];
        } else {
            t.add(a[i], p[i]);
        }
        if (pos[a[i]] != -1) {
            y[i] = sneg +
                   t.rangeSum((pos[a[i]] == 0 ? -1 : b[pos[a[i]] - 1]) + 1, n);
        }
    }
    dp[0] = sneg + t.rangeSum(0, n);
    for (int i = 0; i < n; ++i) {
        if (pos[a[i]] != -1) {
            dp[pos[a[i]] + 1] =
                std::min(dp[pos[a[i]] + 1], dp[pos[a[i]]] - y[i] + x[i]);
        }
    }
    if (dp[m] > 1e15) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::cout << dp[m] << "\n";
    }
    return 0;
}