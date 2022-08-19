#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    if (n <= 2) {
        std::cout << n << "\n";
        return 0;
    }
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<bool> b(n);
    for (int i = 2; i < n; i++) {
        b[i] = (a[i] == a[i - 1] + a[i - 2]);
    }
    
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (j < i) {
            j = i;
        }
        while (j < n && b[j]) {
            j++;
        }
        ans = std::max(ans, j - i + 2);
    }
    
    std::cout << ans << "\n";
    
    return 0;
}