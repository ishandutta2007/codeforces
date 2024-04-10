#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector a(n, std::vector<int>(n));
    std::vector<std::array<int, 2>> pos(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
            a[i][j]--;
            pos[a[i][j]] = {i, j};
        }
    }
    
    i64 ans = 0;
    
    std::vector f(n, std::vector<int>(n));
    auto solve = [&]() {
        std::vector<int> cntr(n), cntc(n, n);
        for (int i = 0; i < n * n; i++) {
            auto [x, y] = pos[i];
            cntc[y]--;
            ans += 1LL * cntr[x] * cntc[y];
            cntr[x]++;
        }
    };
    
    solve();
    std::reverse(pos.begin(), pos.end());
    solve();
    
    ans /= 2;
    std::cout << ans << "\n";
    
    return 0;
}