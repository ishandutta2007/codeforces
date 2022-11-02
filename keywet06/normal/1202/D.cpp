#include <bits/stdc++.h>

int T, n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::vector<std::pair<int, int> > ans;
        for (int i = 10000; i >= 2; --i) {
            int x = i * (i - 1) >> 1;
            if (n / x) ans.emplace_back(i, n / x), n %= x;
        }
        std::string s;
        s.push_back('1');
        for (int i = ans.size() - 1; ~i; --i) {
            int x = ans[i].first, y = ans[i].second;
            if (i < ans.size() - 1) x -= ans[i + 1].first;
            while (x--) s.push_back('3');
            while (y--) s.push_back('7');
        }
        std::cout << s << '\n';
    }
    return 0;
}