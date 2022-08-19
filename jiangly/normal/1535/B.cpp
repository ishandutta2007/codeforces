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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] % 2 == 0 || a[j] % 2 == 0 || std::gcd(a[i], a[j]) > 1) {
                    ans++;
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}