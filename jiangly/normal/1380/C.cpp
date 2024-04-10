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
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        int ans = 0;
        for (int r = n, i = n - 1; i >= 0; --i) {
            if (1ll * a[i] * (r - i) >= x) {
                ++ans;
                r = i;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}