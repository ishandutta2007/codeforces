#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int k = std::__lg(n);
    std::vector<std::pair<int, int>> ans;
    auto work = [&](int x, int len) {
        for (int t = 1; t < len; t *= 2)
            for (int i = 0; i < len; i += 2 * t)
                for (int j = 0; j < t; ++j)
                    ans.emplace_back(x + i + j, x + i + j + t);
    };
    work(0, 1 << k);
    work(n - (1 << k), 1 << k);
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) std::cout << x + 1 << " " << y + 1 << "\n";
    
    return 0;
}