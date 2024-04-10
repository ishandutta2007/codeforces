#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector v(n, std::vector<int>(n));
    std::vector<std::array<int, 2>> pos(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> v[i][j];
            v[i][j]--;
            pos[v[i][j]] = {i, j};
        }
    }
    
    // cell A is good if you can not go from A to a good cell B which is greater than A
    
    int pp = -inf, pn = -inf, np = -inf, nn = -inf;
    std::vector<std::string> ans(n, std::string(n, 'G'));
    for (int i = n * n - 1; i >= 0; i--) {
        auto [x, y] = pos[i];
        if (pp > x + y + k || pn > x - y + k || np > -x + y + k || nn > -x - y + k) {
            continue;
        }
        ans[x][y] = 'M';
        pp = std::max(pp, x + y);
        pn = std::max(pn, x - y);
        np = std::max(np, -x + y);
        nn = std::max(nn, -x - y);
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << "\n";
    }
    
    return 0;
}