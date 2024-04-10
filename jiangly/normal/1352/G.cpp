#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n <= 3) {
            std::cout << -1 << "\n";
        } else {
            std::deque ans{3, 1, 4, 2};
            for (int i = 5; i <= n; i += 2)
                ans.push_front(i);
            for (int i = 6; i <= n; i += 2)
                ans.push_back(i);
            for (auto i : ans)
                std::cout << i << " \n"[i == ans.back()];
        }
    }
    return 0;
}