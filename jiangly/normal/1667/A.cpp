#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    i64 ans = 1E18;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int k = 0; k < n; k++) {
        std::vector<i64> b(n);
        i64 res = 0;
        for (int i = k + 1; i < n; i++) {
            i64 t = b[i - 1] / a[i] + 1;
            res += t;
            b[i] = a[i] * t;
        }
        for (int i = k - 1; i >= 0; i--) {
            i64 t = b[i + 1] / a[i] + 1;
            res += t;
            b[i] = a[i] * t;
        }
        ans = std::min(ans, res);
    }
    
    std::cout << ans << "\n";
    
    return 0;
}