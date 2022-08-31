#include <bits/stdc++.h>

#include <algorithm>

#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int p = std::min_element(a.begin(), a.end()) - a.begin();
        int ans = 0;
        for (int i = 0; i < n; ++i) if (i != p) ans += (k - a[i]) / a[p];
        std::cout << ans << "\n";
    }
    
    return 0;
}