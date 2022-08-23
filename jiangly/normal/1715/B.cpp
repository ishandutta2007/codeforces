#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k, b;
    i64 s;
    std::cin >> n >> k >> b >> s;
    
    i64 cur = s / k;
    if (b > cur) {
        std::cout << "-1\n";
        return;
    }
    
    std::vector<i64> a(n);
    a[0] = s;
    
    for (int i = 1; i < n; i++) {
        if (cur > b && a[0] >= k) {
            cur -= (a[0] % k != k - 1);
            a[0] -= k - 1;
            a[i] = k - 1;
        }
    }
    
    if (cur != b) {
        std::cout << "-1\n";
        return;
    }
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