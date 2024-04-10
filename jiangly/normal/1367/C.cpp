#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        std::vector<int> a;
        for (int i = 0; i < n; ++i)
            if (s[i] == '1')
                a.push_back(i);
        if (a.empty()) {
            std::cout << (n + k) / (k + 1) << "\n";
        } else {
            int ans = 0;
            ans += a[0] / (k + 1);
            for (int i = 0; i < int(a.size()) - 1; ++i)
                ans += (a[i + 1] - a[i] - 1 - k) / (k + 1);
            ans += (n - a.back() - 1) / (k + 1);
            std::cout << ans << "\n";
        }
    }
    return 0;
}