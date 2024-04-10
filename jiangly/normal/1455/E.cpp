#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t ans = 1e18;
        std::pair<int, int> p[4];
        for (int i = 0; i < 4; ++i) std::cin >> p[i].first >> p[i].second;
        
        std::sort(p, p + 4);
        do {
            std::vector<int> cand{0};
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    cand.push_back(p[2 + j].first - p[i].first);
                    cand.push_back(p[2 * j + 1].second - p[2 * i].second);
                }
            }
            
            for (auto d : cand) {
                if (d < 0) continue;
                int64_t res = 0;
                int x[4], y[4];
                for (int i = 0; i < 4; ++i) std::tie(x[i], y[i]) = p[i];
                x[2] -= d, x[3] -= d;
                y[1] -= d, y[3] -= d;
                std::sort(x, x + 4);
                std::sort(y, y + 4);
                for (int i = 0; i < 4; ++i) {
                    res += std::abs(x[i] - x[1]);
                    res += std::abs(y[i] - y[1]);
                }
                if (res < ans) ans = res;
            }
        } while (std::next_permutation(p, p + 4));
        std::cout << ans << "\n";
    }
    
    return 0;
}