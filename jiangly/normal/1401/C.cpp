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
        int x = *std::min_element(a.begin(), a.end());
        auto b = a;
        std::sort(b.begin(), b.end());
        for (auto &i : a)
            if (i % x == 0)
                i = 0;
        for (auto &i : b)
            if (i % x == 0)
                i = 0;
        std::cout << (a == b ? "YES" : "NO") << "\n";
    }
    return 0;
}