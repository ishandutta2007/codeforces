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
    
    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    
    Fenwick<int> fen(n);
    for (int i = 1; i < n; i++) {
        fen.add(q[i], 1);
    }
    i64 ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = q[i];
        int y = q[i + 1];
        int t;
        if (x < y) {
            t = fen.rangeSum(x + 1, y);
        } else {
            t = fen.rangeSum(x + 1, n) + fen.sum(y);
        }
        ans += 1LL * (i + 1) * t;
        fen.add(y, -1);
    }
    
    std::cout << ans << "\n";
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