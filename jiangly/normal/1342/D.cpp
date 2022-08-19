#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(k);
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        ++cnt[--m];
    }
    std::vector<int> c(k + 1);
    for (int i = 0; i < k; ++i)
        std::cin >> c[i];
    std::vector<std::vector<int>> v(1);
    int j = 0;
    for (int i = k - 1; i >= 0; --i) {
        if (c[i] > c[i + 1])
            j = 0;
        while (cnt[i]--) {
            if (int(v[j].size()) == c[i])
                ++j;
            if (j == int(v.size()))
                v.emplace_back();
            v[j].push_back(i);
        }
    }
    std::cout << v.size() << "\n";
    for (auto t : v) {
        std::cout << t.size();
        for (auto i : t)
            std::cout << " " << i + 1;
        std::cout << "\n";
    }
    return 0;
}