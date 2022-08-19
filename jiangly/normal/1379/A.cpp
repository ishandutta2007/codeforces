#include <bits/stdc++.h>
const std::string s0 = "abacaba";
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::string ans;
        for (int i = 0; i <= n - 7; ++i) {
            std::string t = s;
            bool ok = true;
            for (int j = 0; j < 7; ++j) {
                if (t[i + j] != s0[j] && t[i + j] != '?') {
                    ok = false;
                } else {
                    t[i + j] = s0[j];
                }
            }
            if (!ok)
                continue;
            for (int j = 0; j < n; ++j)
                if (t[j] == '?')
                    t[j] = 'z';
            for (int j = 0; j <= n - 7; ++j)
                if (j != i && t.substr(j, 7) == s0)
                    ok = false;
            if (ok) {
                ans = t;
                break;
            }
        }
        if (ans.empty()) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
            std::cout << ans << "\n";
        }
    }
    return 0;
}