#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }
    
    auto check = [&](int n, int m) {
        std::vector<int> b(k);
        for (int i = 0; i < k; i++) {
            b[i] = a[i] / m;
            if (b[i] == 1) {
                b[i] = 0;
            }
        }
        if (std::accumulate(b.begin(), b.end(), 0LL) < n) {
            return false;
        }
        if (std::count(b.begin(), b.end(), 0) + std::count(b.begin(), b.end(), 2) == k && n % 2 == 1) {
            return false;
        }
        return true;
    };
    
    if (check(n, m) || check(m, n)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
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