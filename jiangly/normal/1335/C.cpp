#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            ++cnt[a - 1];
        }
        int dis = 0, max = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > 0)
                ++dis;
            max = std::max(max, cnt[i]);
        }
        std::cout << std::min(dis, max) - (dis == max) << "\n";
    }
    return 0;
}