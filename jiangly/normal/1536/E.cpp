#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        bool zero = false;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '0') {
                    zero = true;
                } else {
                    ans = 2 * ans % P;
                }
            }
        }
        ans -= !zero;
        std::cout << ans << "\n";
    }
    return 0;
}