#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int ans = 10;
        for (int mask = 0; mask < (1 << 10); mask++) {
            bool ok = true;
            for (int i = 0; i < 10; i++) {
                if (s[i] != '?' && s[i] - '0' != (mask >> i & 1)) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            int diff = 0;
            for (int i = 0; i < 10; i++) {
                if (mask >> i & 1) {
                    if (i % 2 == 0) {
                        diff++;
                    } else {
                        diff--;
                    }
                }
                if (diff > (10 - i) / 2 || -diff > (9 - i) / 2) {
                    ans = std::min(ans, i + 1);
                    break;
                }
            }
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}