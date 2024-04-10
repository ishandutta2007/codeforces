#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        a[i] = i;
        sum ^= i;
    }
    a[n - 1] = sum;
    if (a[n - 1] < n - 1) {
        if (a[n - 1] == 0) {
            a[1] |= 1 << 20;
        } else {
            a[0] |= 1 << 20;
        }
        a[n - 1] |= 1 << 20;
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