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
        std::vector<int> cnt(2 * n + 1);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            x--;
            cnt[x]++;
        }
        int ans = 0;
        int last = -1;
        int sum = 0;
        for (int i = 0; i < 2 * n + 1; i++) {
            if (cnt[i] > 0) {
                sum += cnt[i];
                ans++;
            } else {
                if (sum >= i - last) {
                    ans++;
                }
                last = i;
                sum = 0;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}