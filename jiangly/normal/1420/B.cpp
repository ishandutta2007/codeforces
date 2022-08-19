#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int cnt[30] = {};
        int64_t ans = 0;
        while (n--) {
            int x;
            std::cin >> x;
            ans += cnt[std::__lg(x)]++;
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}