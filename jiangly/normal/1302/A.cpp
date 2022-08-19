#include <iostream>
#include <vector>
#include <algorithm>
int t, n, m, k;
std::vector<int> a, maxs;
void solve() {
    std::cin >> n >> m >> k;
    --m;
    if (k > m)
        k = m;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    maxs.clear();
    for (int i = 0; i <= m; ++i)
        maxs.push_back(std::max(a[i], a[i + n - m - 1]));
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        int min = 1'000'000'000;
        for (int j = i; j <= i + m - k; ++j)
            min = std::min(min, maxs[j]);
        ans = std::max(ans, min);
    }
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}