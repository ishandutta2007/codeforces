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
        int n = s.size();
        for (int i = 1; i < n; i += 2) {
            if (s[i] != '?') {
                s[i] ^= 1;
            }
        }
        int cnt[2] = {};
        i64 ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] != '?') {
                cnt[s[i] - '0']++;
            }
            while (cnt[0] && cnt[1]) {
                if (s[j] != '?') {
                    cnt[s[j] - '0']--;
                }
                j++;
            }
            ans += i - j + 1;
        }
        std::cout << ans << "\n";
    }
    return 0;
}