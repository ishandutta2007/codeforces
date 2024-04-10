#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> p(1 << n);
    std::iota(p.begin(), p.end(), 0);
    
    auto solve = [&](auto self, auto s, auto p) -> std::pair<std::string, std::vector<int>> {
        if (p.empty()) {
            return {std::string(1, 'z' + 1), p};
        }
        int n = s.length();
        if (p.size() == 1) {
            std::string t(n, '?');
            for (int i = 0; i < n; i++) {
                t[i] = s[i ^ p[0]];
            }
            return {t, p};
        }
        int m = 0;
        while (m < int(p.size()) && p[m] < n / 2) {
            m++;
        }
        for (int i = m; i < int(p.size()); i++) {
            p[i] -= n / 2;
        }
        auto x = self(self, s.substr(0, n / 2), std::vector(p.begin(), p.begin() + m));
        auto y = self(self, s.substr(n / 2), std::vector(p.begin() + m, p.end()));
        
        if (x.first < y.first) {
            y = self(self, s.substr(n / 2), x.second);
            return {x.first + y.first, y.second};
        } else if (x.first > y.first) {
            x = self(self, s.substr(0, n / 2), y.second);
            for (auto &j : x.second) {
                j += n / 2;
            }
            return {y.first + x.first, x.second};
        } else {
            std::string t = x.first;
            for (int i = n / 2; i < n; i++) {
                t += s[i ^ x.second[0]];
            }
            auto u = x.second;
            for (auto j : y.second) {
                u.push_back(j + n / 2);
            }
            return {t, u};
        }
    };
    
    std::cout << solve(solve, s, p).first << "\n";
    
    return 0;
}