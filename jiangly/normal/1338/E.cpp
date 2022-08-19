#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cctype>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> e(n, std::vector<bool>(n));
    std::vector<int> din(n);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n / 4; ++j) {
            int v = std::isdigit(s[j]) ? s[j] - '0' : s[j] - 'A' + 10;
            e[i][4 * j] = v >> 3;
            e[i][4 * j + 1] = v >> 2 & 1;
            e[i][4 * j + 2] = v >> 1 & 1;
            e[i][4 * j + 3] = v & 1;
        }
        for (int j = 0; j < n; ++j)
            if (e[i][j])
                ++din[j];
    }
    std::queue<int> que;
    int rest = n;
    int s = -1;
    long long ans = 0;
    const long long inf = 614 * n;
    while (true) {
        for (int i = 0; i < n; ++i)
            if (din[i] == 0)
                s = i;
        if (s == -1)
            break;
        --din[s];
        for (int i = 0; i < n; ++i)
            if (e[s][i])
                --din[i];
        --rest;
        ans += rest * (1 + inf);
        s = -1;
    }
    if (rest > 0) {
        int x = std::max_element(din.begin(), din.end()) - din.begin();
        std::vector<int> p, q;
        for (int i = 0; i < n; ++i)
            if (din[i] >= 0)
                (e[x][i] ? q : p).push_back(i);
        ans += 3 * rest * (rest - 1) / 2;
        std::fill(din.begin(), din.end(), 0);
        for (auto a : p)
            for (auto b : q)
                ++(e[a][b] ? din[b] : din[a]);
        auto solve = [&](auto v) {
            std::vector<int> cnt(n);
            for (auto a : v)
                ++cnt[din[a]];
            for (int i = 0; i < n; ++i)
                ans += cnt[i] * (cnt[i] - 1) / 2;
        };
        solve(p);
        solve(q);
    }
    std::cout << ans << "\n";
    return 0;
}