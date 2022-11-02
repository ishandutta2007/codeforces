#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int a, b;
        std::cin >> a >> b;
        std::string s;
        std::cin >> s;
        std::vector<int> x;
        int cur = 0;
        for (char c : s) {
            if (c == '.') {
                ++cur;
            } else if (cur > 0) {
                x.push_back(cur);
                cur = 0;
            }
        }
        if (cur > 0) {
            x.push_back(cur);
        }
        int cnt[2] = {};
        bool ok = false;
        auto f = [&](int x) -> bool { return x >= b && x < a || x >= 2 * b; };
        auto g = [&](int x) -> bool { return x >= a; };
        for (int x : x) cnt[0] += f(x), cnt[1] += g(x);
        for (int x : x) {
            for (int i = 0; i + a <= x; ++i) {
                if (cnt[0] - f(x) + f(i) + f(x - i - a) == 0 &&
                    (cnt[1] - g(x) + g(i) + g(x - i - a)) % 2 == 0) {
                    ok = true;
                }
            }
        }
        if (ok) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}