#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int64_t sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    int64_t t = (sum - 1ll * n * (n - 1) / 2) / n;
    int x = sum - n * t - 1ll * n * (n - 1) / 2;
    for (int i = 0; i < n; ++i)
        std::cout << t + i + (i < x) << " \n"[i == n - 1];
    return 0;
}