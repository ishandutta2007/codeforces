#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i)
            std::cin >> p[i];
        int ans = -1;
        for (int i = 0; i + 2 < n; ++i)
            if (p[i] < p[i + 1] && p[i + 1] > p[i + 2])
                ans = i;
        if (ans == -1) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            std::cout << ans + 1 << " " << ans + 2 << " " << ans + 3 << "\n";
        }
    }
    return 0;
}