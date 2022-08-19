#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::string s;
    std::cin >> s;
    
    int c = std::count(s.begin(), s.end(), '1');
    
    if (c == 0) {
        std::cout << "1\n";
        std::cout << "1 " << m << "\n";
        return;
    }
    
    if (1LL * c * m % n != 0) {
        std::cout << "-1\n";
        return;
    }
    
    int k = 1LL * c * m / n;
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + s[i] - '0';
    }
    for (int i = 0; i + m <= n; i++) {
        if (sum[i + m] - sum[i] == k) {
            std::cout << "1\n";
            std::cout << i + 1 << " " << i + m << "\n";
            return;
        }
    }
    for (int i = 0; i <= m; i++) {
        if (sum[i] + sum[n] - sum[n - m + i] == k) {
            std::cout << "2\n";
            std::cout << "1 " << i << "\n";
            std::cout << n - m + i + 1 << " " << n << "\n";
            return;
        }
    }
    assert(false);
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