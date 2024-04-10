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
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum ^= a[i];
        if (sum == 0) {
            std::cout << "DRAW\n";
            continue;
        }
        int k = std::__lg(sum);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] >> k & 1)
                ++cnt;
        if (cnt % 4 == 1) {
            std::cout << "WIN\n";
        } else {
            std::cout << ((n - cnt) % 2 == 1 ? "WIN" : "LOSE") << "\n";
        }
    }
    return 0;
}