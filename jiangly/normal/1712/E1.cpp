#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2E5;

template <typename T>
struct Fenwick {
    int n;
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
    
    int t;
    std::cin >> t;
    
    std::vector<std::array<int, 3>> query(t);
    std::vector<i64> ans(t);
    for (int i = 0; i < t; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        query[i] = {l, r, i};
        
        ans[i] = 1LL * (r - l) * (r - l - 1) * (r - l - 2) / 6;
        
        ans[i] -= std::max(0, r / 6 - l / 3);
        ans[i] -= std::max(0, r / 15 - l / 6);
    }
    
    std::sort(query.begin(), query.end(), [&](auto a, auto b) {
        return a[0] > b[0];
    });
    
    Fenwick<i64> fen(N + 1);
    
    std::vector<int> f(N + 1);
    
    int cur = N;
    for (auto [l, r, i] : query) {
        while (cur > l) {
            for (int j = 2 * cur; j <= N; j += cur) {
                fen.add(j, f[j]++);
            }
            cur--;
        }
        ans[i] -= fen.sum(r + 1);
    }
    
    for (int i = 0; i < t; i++) {
        std::cout << ans[i] << "\n";
    }
    
    return 0;
}