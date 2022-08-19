#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int64_t k;
        std::cin >> k;
        k = (k - 1) % 2 + 1;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        while (k--) {
            int64_t d = *std::max_element(a.begin(), a.end());
            for (int i = 0; i < n; ++i)
                a[i] = d - a[i];
        }
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}