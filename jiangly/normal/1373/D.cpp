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
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        long long ans = 0, sum = 0;
        long long mn[2] = {0, (long long)1e18};
        for (int i = 0; i < n; ++i) {
            sum += i & 1 ? a[i] : -a[i];
            mn[(i & 1) ^ 1] = std::min(mn[(i & 1) ^ 1], sum);
            ans = std::max(ans, sum - mn[(i & 1) ^ 1]);
        }
        for (int i = 0; i < n; i += 2)
            ans += a[i];
        std::cout << ans << "\n";
    }
    return 0;
}