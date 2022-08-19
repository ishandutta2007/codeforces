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
        bool ok = true;
        for (int a = 0; a < k; ++a) {
            bool a1 = false, a0 = false;
            for (int i = a; i < n; i += k) {
                if (s[i] == '1') {
                    a1 = true;
                } else if (s[i] == '0') {
                    a0 = true;
                }
            }
            if (a0 && a1) {
                ok = false;
            } else if (a0 || a1) {
                for (int i = a; i < n; i += k)
                    s[i] = a0 ? '0' : '1';
            }
        }
        int l = 0, r = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] == '1') {
                ++l;
                ++r;
            } else if (s[i] == '?') {
                ++r;
            }
        }
        if (ok && l <= k / 2 && k / 2 <= r) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}