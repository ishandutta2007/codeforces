#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::pair<int, long long> neg, pos;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                neg = std::max(neg, std::make_pair(pos.first + 1, pos.second + a[i]));
            } else {
                pos = std::max(pos, std::make_pair(neg.first + 1, neg.second + a[i]));
            }
        }
        std::cout << std::max(neg, pos).second << "\n";
    }
    return 0;
}