#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
constexpr int P = 998244353;
void gg() {
    std::cout << 0 << "\n";
    exit(0);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m), r(m, -1);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < m; ++i)
        std::cin >> b[i];
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
        if (a[i] == b[j]) {
            r[j] = i;
            --j;
        }
    }
    if (r[0] == -1)
        gg();
    for (int i = 0; i < r[0]; ++i)
        if (a[i] < b[0])
            gg();
    for (int i = 0; i < m; ++i)
        for (int j = r[i] + 1; j < (i == m - 1 ? n : r[i + 1]); ++j)
            if (a[j] < b[i])
                gg();
    int ans = 1;
    for (int i = 0; i < m - 1; ++i) {
        int j = r[i + 1];
        while (j > r[i] + 1 && a[j - 1] >= b[i + 1])
            --j;
        ans = 1ll * ans * (r[i + 1] - j + 1) % P;
    }
    std::cout << ans << "\n";
    return 0;
}