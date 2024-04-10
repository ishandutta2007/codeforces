#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        a[i] = std::count(s.begin(), s.end(), 'B');
        b[i] = s.length() - a[i];
    }
    auto solve = [&](int m) {
        int xMin = 0, xMax = 1e9, yMin = 0, yMax = 1e9, dMin = -1e9, dMax = 1e9;
        for (int i = 0; i < n; ++i) {
            xMin = std::max(xMin, a[i] - m);
            xMax = std::min(xMax, a[i] + m);
            yMin = std::max(yMin, b[i] - m);
            yMax = std::min(yMax, b[i] + m);
            dMin = std::max(dMin, a[i] - b[i] - m);
            dMax = std::min(dMax, a[i] - b[i] + m);
        }
        if (xMin > xMax || yMin > yMax || dMin > dMax || xMin - yMax > dMax ||
            xMax - yMin < dMin)
            return std::make_pair(-1, -1);
        int x, y;
        if (xMin - yMax >= dMin) {
            x = xMin;
            y = yMax;
        } else if (xMax - yMax >= dMin) {
            y = yMax;
            x = dMin + y;
        } else {
            x = xMax;
            y = x - dMin;
        }
        return std::make_pair(x, y);
    };
    int l = 0, r = 5e5;
    while (l < r) {
        int m = (l + r) / 2;
        auto [x, y] = solve(m);
        if (x != -1) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    auto [x, y] = solve(l);
    std::cout << l << "\n";
    std::cout << std::string(x, 'B') + std::string(y, 'N') << "\n";
    return 0;
}