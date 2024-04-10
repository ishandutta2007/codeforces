#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int64_t ans = 0;
    std::vector<std::vector<int64_t>> pre(2, std::vector<int64_t>(n + 1));
    for (int i = 0; i < n; ++i) {
        pre[0][i + 1] = pre[0][i];
        pre[1][i + 1] = pre[1][i];
        pre[i & 1][i + 1] += a[i];
    }
    for (int i = 0; i <= n; ++i)
        ans = std::max(ans, pre[(i & 1) ^ 1][i] + (pre[i & 1][n] - pre[i & 1][i]));
    std::cout << ans << "\n";
    return 0;
}