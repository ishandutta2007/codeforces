#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5;

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    Fenwick<i64> f1(N + 1), f2(N + 1);
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 ans = 0;
    i64 suma = 0;
    for (int i = 0; i < n; i++) {
        ans += suma;
        for (int j = a[i]; j <= N; j += a[i]) {
            ans -= f1.rangeSum(j, N + 1) * a[i];
        }
        for (int j = a[i]; j <= N; j += a[i]) {
            f2.add(j, a[i]);
        }
        f1.add(a[i], 1);
        ans += 1LL * a[i] * (i + 1);
        ans -= f2.sum(a[i] + 1);
        suma += a[i];
        std::cout << ans << " \n"[i == n - 1];
    }
    
    return 0;
}