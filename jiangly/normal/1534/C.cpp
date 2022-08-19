#include <bits/stdc++.h>
using i64 = long long;
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
            b[i]--;
        }
        for (int i = 0; i < n; i++) {
            c[a[i]] = b[i];
        }
        int ans = 1;
        std::vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = c[j];
            }
            ans = 2 * ans % P;
        }
        std::cout << ans << "\n";
    }
    return 0;
}