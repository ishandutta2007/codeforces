#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto [mn, mx] = std::minmax_element(a.begin(), a.end());
    if (*mx - *mn > k) {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            std::cout << j % k + 1 << " \n"[j == a[i] - 1];
        }
    }
    return 0;
}