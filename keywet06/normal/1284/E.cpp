#include <bits/stdc++.h>

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

Point operator-(const Point &lhs, const Point &rhs) {
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

long long cross(const Point &lhs, const Point &rhs) {
    return 1LL * lhs.x * rhs.y - 1LL * lhs.y * rhs.x;
}

long long dot(const Point &lhs, const Point &rhs) {
    return 1LL * lhs.x * rhs.x + 1LL * lhs.y * rhs.y;
}

bool operator<(const Point &lhs, const Point &rhs) {
    bool l = lhs.y > 0 || lhs.y == 0 && lhs.x > 0;
    bool r = rhs.y > 0 || rhs.y == 0 && rhs.x > 0;
    if (l != r) return l;
    return cross(lhs, rhs) > 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<Point> a;
        for (int j = 0; j < n; ++j) {
            if (i != j) a.emplace_back(x[j] - x[i], y[j] - y[i]);
        }
        std::sort(a.begin(), a.end());
        a.insert(a.begin(), a.begin(), a.end());
        long long cnt = 1LL * (n - 1) * (n - 2) * (n - 3) / 6;
        for (int i = 0, j = 0; i < n - 1; ++i) {
            while (j < i + n - 1 && cross(a[i], a[j]) >= 0) ++j;
            cnt -= (j - i - 1) * (j - i - 2) / 2;
        }
        ans += cnt;
    }
    ans = ans * (n - 4) / 2;
    std::cout << ans << "\n";
    return 0;
}