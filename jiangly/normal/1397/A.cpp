#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int cnt[26] = {};
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            for (auto c : s)
                ++cnt[c - 'a'];
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] % n)
                ok = false;
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}