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
        int sum = std::accumulate(a.begin(), a.end(), 0);
        if (sum % n) {
            std::cout << "-1\n";
            continue;
        }
        int ans = std::count_if(a.begin(), a.end(), [&](int x) {
            return x > sum / n;
        });
        std::cout << ans << "\n";
    }
    return 0;
}