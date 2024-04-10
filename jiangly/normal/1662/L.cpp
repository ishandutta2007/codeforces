#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, v;
    std::cin >> n >> v;
    
    std::vector<int> t(n), a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }
    std::vector<std::array<i64, 2>> b(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[i] = {-a[i] - 1LL * t[i] * v, a[i] - 1LL * t[i] * v};
    }
    b[n] = {0LL, 0LL};
    
    std::sort(b.begin(), b.end());
    std::vector<i64> f;
    
    for (auto [_, x] : b) {
        auto it = std::upper_bound(f.begin(), f.end(), x);
        if (_ == 0 && x == 0) {
            std::cout << it - f.begin() << "\n";
            return 0;
        }
        if (it == f.end()) {
            f.push_back(x);
        } else {
            *it = x;
        }
    }
    
    return 0;
}