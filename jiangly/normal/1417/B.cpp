#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int k = 0;
        if (x % 2 == 0) k = std::count(a.begin(), a.end(), x / 2) / 2;
        for (int i = 0; i < n; ++i) std::cout << (2 * a[i] < x || (2 * a[i] == x && k-- > 0)) << " \n"[i == n - 1];
    }
    
    return 0;
}