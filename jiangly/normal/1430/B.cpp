#include <bits/stdc++.h>
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
        std::sort(a.begin(), a.end(), std::greater<>());
        std::cout << std::accumulate(a.begin(), a.begin() + k + 1, 0ll) << "\n";
    }
    
    return 0;
}