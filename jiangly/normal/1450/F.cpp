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
        std::vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
            ++cnt[a[i]];
        }
        if (*std::max_element(cnt.begin(), cnt.end()) * 2 > n + 1) {
            std::cout << -1 << "\n";
            continue;
        }
        cnt.assign(n, 0);
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                ++ans;
                ++cnt[a[i]];
                ++cnt[a[i + 1]];
            }
        }
        ++cnt[a[0]];
        ++cnt[a[n - 1]];
        ans = std::max(ans, *std::max_element(cnt.begin(), cnt.end()) - 2);
        std::cout << ans << "\n";
    }
    
    return 0;
}