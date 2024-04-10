#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t m;
    std::cin >> m;
    
    int cnt = 0;
    int64_t sum = 0;
    
    std::function<void(int64_t, int, int64_t)> dfs = [&](int64_t m, int c, int64_t s) {
        if (c > cnt || (c == cnt && s > sum)) {
            cnt = c;
            sum = s;
        }
        int64_t a = std::cbrt(m);
        if (a > 0) {
            dfs(m - a * a * a, c + 1, s + a * a * a);
        }
        if (a > 1) {
            dfs(a * a * a - 1 - (a - 1) * (a - 1) * (a - 1), c + 1, s + (a - 1) * (a - 1) * (a - 1));
        }
    };
    dfs(m, 0, 0);
    
    std::cout << cnt << " " << sum << "\n";
    
    return 0;
}