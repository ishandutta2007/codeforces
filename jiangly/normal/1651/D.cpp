#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> x(n), y(n);
    std::set<std::pair<int, int>> s;
    std::map<std::pair<int, int>, int> id;
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
        id[{x[i], y[i]}] = i;
    }
    
    for (int i = 0; i < n; i++) {
        s.emplace(x[i] - 1, y[i]);
        s.emplace(x[i] + 1, y[i]);
        s.emplace(x[i], y[i] - 1);
        s.emplace(x[i], y[i] + 1);
    }
    
    
    
    std::vector<std::pair<int, int>> ans(n, {-1, -1});
    
    std::queue<std::array<int, 4>> q;
    for (auto [x, y] : s) {
        if (!id.count({x, y})) {
            q.push({x, y, x, y});
        }
    }
    
    while (!q.empty()) {
        auto [x, y, fx, fy] = q.front();
        q.pop();
        
        for (auto [nx, ny] : {std::pair(x - 1, y), {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
            if (!id.count({nx, ny})) {
                continue;
            }
            ans[id[{nx, ny}]] = {fx, fy};
            id.erase({nx, ny});
            q.push({nx, ny, fx, fy});
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i].first << " " << ans[i].second << "\n";
    }
    
    return 0;
}