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
        if (std::count(a.begin(), a.end(), a[0]) == n) {
            std::cout << n << "\n";
        } else {
            std::cout << 1 << "\n";
        }
    }
    return 0;
}