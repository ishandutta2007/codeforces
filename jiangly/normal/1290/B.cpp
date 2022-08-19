#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int n, q;
std::string s;
std::vector<std::vector<int>> cnt;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> s >> q;
    n = s.length();
    cnt.resize(n + 1);
    cnt[0].resize(26);
    for (int i = 0; i < n; ++i) {
        cnt[i + 1] = cnt[i];
        ++cnt[i + 1][s[i] - 'a'];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l;
        bool ans = false;
        if (r - l == 1) {
            ans = true;
        } else {
            auto c = cnt[r];
            for (int j = 0; j < 26; ++j)
                c[j] -= cnt[l][j];
            std::sort(c.begin(), c.end(), std::greater<>());
            if (c[2] > 0 || c[1] > 0 && s[l] != s[r - 1]) {
                ans = true;
            } else {
                ans = false;
            }
        }
        if (ans) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}