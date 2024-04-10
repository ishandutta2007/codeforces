#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <chrono>
#include <queue>
#include <set>
#include <cassert>
#include <random>
#include <chrono>
#include <complex>
#include <cstring>
#include <map>
int query(const std::vector<int> &a) {
    std::cout << "? " << a.size();
    for (auto i : a)
        std::cout << " " << i + 1;
    std::cout << std::endl;
    int res;
    std::cin >> res;
    return res;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<std::vector<int>> s(k);
        for (int i = 0; i < k; ++i) {
            int c;
            std::cin >> c;
            s[i].resize(c);
            for (auto &j : s[i]) {
                std::cin >> j;
                --j;
            }
        }
        std::vector<int> a(n);
        std::iota(a.begin(), a.end(), 0);
        int mx = query(a);
        int l = 0, r = k;
        while (l < r) {
            int m = (l + r + 1) / 2;
            a.clear();
            for (int i = 0; i < m; ++i)
                a.insert(a.end(), s[i].begin(), s[i].end());
            if (query(a) == mx) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        std::vector<int> ans(k, mx);
        if (l < k) {
            std::vector<bool> v(n);
            for (auto i : s[l])
                v[i] = true;
            a.clear();
            for (int i = 0; i < n; ++i)
                if (!v[i])
                    a.push_back(i);
            ans[l] = query(a);
        }
        std::cout << "!";
        for (auto i : ans)
            std::cout << " " << i;
        std::cout << std::endl;
        std::string res;
        std::cin >> res;
    }
    return 0;
}