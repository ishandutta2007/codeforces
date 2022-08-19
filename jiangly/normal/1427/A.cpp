#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int sum = std::accumulate(a.begin(), a.end(), 0);
        if (sum == 0) {
            std::cout << "NO\n";
            continue;
        }
        std::sort(a.begin(), a.end());
        if (sum > 0) std::reverse(a.begin(), a.end());
        std::cout << "YES\n";
        for (int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i == n - 1];
    }
    
    return 0;
}