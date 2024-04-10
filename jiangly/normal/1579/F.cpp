#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, d;
    std::cin >> n >> d;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int t = std::gcd(n, d);
    int res = 0;
    for (int i = 0; i < t; i++) {
        std::vector<int> b;
        for (int j = 0; j < n / t; j++) {
            b.push_back(a[(i + 1LL * d * j) % n]);
        }
        if (std::count(b.begin(), b.end(), 0) == 0) {
            std::cout << "-1\n";
            return;
        }
        for (int i = 0, j = 0; i < n / t; i++) {
            while (j < i || b[j % (n / t)] != 0) {
                j++;
            }
            res = std::max(res, j - i);
        }
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