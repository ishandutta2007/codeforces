#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> p;
        int x = 0, y = 0;
        int ans = 0;
        for (auto c : s) {
            int x1 = x;
            int y1 = y;
            if (c == 'N') {
                ++y1;
            } else if (c == 'E') {
                ++x1;
            } else if (c == 'W') {
                --x1;
            } else {
                --y1;
            }
            auto p1 = std::make_pair(x, y);
            auto p2 = std::make_pair(x1, y1);
            auto v = std::minmax(p1, p2);
            if (p.count(v)) {
                ans += 1;
            } else {
                p.insert(v);
                ans += 5;
            }
            x = x1;
            y = y1;
        }
        std::cout << ans << "\n";
    }
    return 0;
}