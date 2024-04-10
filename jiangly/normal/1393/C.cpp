#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            --a;
            ++cnt[a];
        }
        int mx = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == mx) {
                ++c;
            } else if (cnt[i] > mx) {
                mx = cnt[i];
                c = 1;
            }
        }
        std::cout << c + (n - mx * c) / (mx - 1) - 1 << "\n";
    }
    return 0;
}