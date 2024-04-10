#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " " << a[i + n] << " \n"[i == n - 1];
        }
    }
    return 0;
}