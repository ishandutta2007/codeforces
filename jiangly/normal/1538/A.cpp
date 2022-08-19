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
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int u = std::find(a.begin(), a.end(), 1) - a.begin();
        int v = std::find(a.begin(), a.end(), n) - a.begin();
        if (u > v) {
            std::swap(u, v);
        }
        int ans = std::min({u + 1 + n - v, n - u, v + 1});
        std::cout << ans << "\n";
    }
    return 0;
}