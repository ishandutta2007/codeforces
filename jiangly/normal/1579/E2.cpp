#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int v[n];
    std::copy(a, a + n, v);
    std::sort(v, v + n);
    int m = std::unique(v, v + n) - v;
    
    Fenwick<int> f(m);
    
    i64 res = 0;
    for (int i = 0; i < n; i++) {
        int x = std::lower_bound(v, v + m, a[i]) - v;
        f.add(x, 1);
        res += std::min(f.sum(x), f.rangeSum(x + 1, m));
    }
    
    std::cout << res << "\n";
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