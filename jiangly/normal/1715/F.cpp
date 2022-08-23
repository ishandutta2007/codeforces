#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1E-12;

double query(std::vector<std::array<double, 2>> p) {
    std::cout << "? " << p.size() << std::endl;
    for (auto [x, y] : p) {
        std::cout << x << " " << y << std::endl;
    }
    double ans;
    std::cin >> ans;
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << std::fixed << std::setprecision(12);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::array<double, 2>> p;
    p.push_back({0., 1. * m});
    for (int i = 0; i < n; i++) {
        p.push_back({1. * i, 0.});
        p.push_back({1. + i, 1. * m - eps});
    }
    p.push_back({1. * n, 1. * m});
    
    auto res = query(p);
    double y = (res * 2 * m - 1) / 2;
    
    p = {};
    
    p.push_back({1. * n, 0.});
    for (int i = 0; i < m; i++) {
        p.push_back({0., 1. * i});
        p.push_back({1. * n - eps, 1. + i});
    }
    p.push_back({1. * n, 1. * m});
    
    res = query(p);
    double x = (res * 2 * n - 1) / 2;
    
    std::cout << "! " << x << " " << y << std::endl;
    
    return 0;
}