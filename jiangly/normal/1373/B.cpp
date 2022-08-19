#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int cnt[2][2] = {};
        for (int i = 0; i < int(s.length()); ++i)
            ++cnt[i & 1][s[i] - '0'];
        int f = std::min(cnt[0][0], cnt[1][1]) + std::min(cnt[0][1], cnt[1][0]);
        if (f & 1) {
            std::cout << "DA\n";
        } else {
            std::cout << "NET\n";
        }
    }
    return 0;
}