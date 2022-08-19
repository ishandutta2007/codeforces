#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int cnt[2] = {};
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            if ((a ^ i) & 1)
                ++cnt[i & 1];
        }
        if (cnt[0] == cnt[1]) {
            std::cout << cnt[0] << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }
    return 0;
}