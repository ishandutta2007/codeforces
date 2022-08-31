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
#include <iomanip>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
        --t[i];
    }
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {return t[i] < t[j];});
    for (auto i : p) {
        std::vector<bool> a(e[i].size() + 1);
        for (auto v : e[i]) {
            if (t[i] == t[v]) {
                std::cout << -1 << "\n";
                return 0;
            } else if (t[i] > t[v]) {
                if (t[v] <= int(e[i].size()))
                    a[t[v]] = true;
            }
        }
        int j = 0;
        while (a[j])
            ++j;
        if (j != t[i]) {
            std::cout << -1 << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << p[i] + 1 << " \n"[i == n - 1];
    return 0;
}