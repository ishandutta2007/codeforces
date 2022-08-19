#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            int w;
            std::cin >> w;
            ++cnt[--w];
        }
        int ans = 0;
        for (int v = 0; v <= 2 * n - 2; ++v) {
            int res = 0;
            for (int i = 0; 2 * i <= v; ++i) {
                if (v - i >= n)
                    continue;
                if (2 * i == v) {
                    res += cnt[i] / 2;
                } else {
                    res += std::min(cnt[i], cnt[v - i]);
                }
            }
            ans = std::max(ans, res);
        }
        std::cout << ans << "\n";
    }
    return 0;
}