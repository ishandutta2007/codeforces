#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    int t = n * (n + 1) / 2;
    i64 sum = std::accumulate(b.begin(), b.end(), 0LL);
    if (sum % t != 0) {
        std::cout << "NO\n";
        return;
    }
    sum /= t;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        i64 v = b[i] - b[(i + n - 1) % n] - sum;
        if (v >= 0 || v % n != 0) {
            std::cout << "NO\n";
            return;
        }
        a[i] = -v / n;
    }
    
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
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