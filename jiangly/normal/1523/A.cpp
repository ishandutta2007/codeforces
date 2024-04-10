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
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int d = i - 1 - last;
                if (last == -1) {
                    int x = std::min(m, d);
                    for (int j = 0; j < x; j++) {
                        s[i - 1 - j] = '1';
                    }
                    last = i;
                    continue;
                }
                int x = std::min(m, d / 2);
                for (int j = 0; j < x; j++) {
                    s[last + 1 + j] = s[i - 1 - j] = '1';
                }
                last = i;
            }
        }
        if (last != -1) {
            int x = std::min(m, n - 1 - last);
            for (int j = 0; j < x; j++) {
                s[last + 1 + j] = '1';
            }
        }
        std::cout << s << "\n";
    }
    return 0;
}