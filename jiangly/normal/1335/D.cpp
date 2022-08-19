#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
const std::pair<int, int> P[] = {{0, 0}, {3, 1}, {6, 2}, {1, 3}, {4, 4}, {7, 5}, {2, 6}, {5, 7}, {8, 8}};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<std::string> s(9);
        for (int i = 0; i < 9; ++i)
            std::cin >> s[i];
        for (auto [x, y] : P) {
            if (s[x][y] == '9') {
                s[x][y] = '1';
            } else {
                ++s[x][y];
            }
        }
        for (auto v : s)
            std::cout << v << "\n";
    }
    return 0;
}