#include <bits/stdc++.h>

using int64 = long long;

struct Point {
    int64 x, y;

    Point(int64 x = 0, int64 y = 0) : x(x), y(y) {}

    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
};

bool check(Point p, Point q, Point r) {
    Point pp = p - q, rr = r - q;
    return (long double)pp.x * rr.y >= (long double)pp.y * rr.x;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int64 n;
    int m;
    std::cin >> n >> m;
    int64 add = 0, Sp = 0;
    std::vector<Point> Hu(1, Point(0, 0));
    while (m--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int cnt;
            std::cin >> cnt;
            Hu.clear(), Hu.push_back(Point(0, 0));
            n += cnt, add = Sp = 0;
        } else if (type == 2) {
            int cnt;
            std::cin >> cnt;
            while (Hu.size() > 1 && check(Point(n, -(n * Sp + add)), Hu[Hu.size() - 2], Hu[Hu.size() - 1])) {
                Hu.pop_back();
            }
            Hu.push_back(Point(n, -(n * Sp + add)));
            n += cnt;
        } else {
            int b, s;
            std::cin >> b >> s;
            add += b, Sp += s;
        }
        while (Hu.size() > 1 && Sp * Hu.back().x + Hu.back().y >= Sp * Hu[Hu.size() - 2].x + Hu[Hu.size() - 2].y) {
            Hu.pop_back();
        }
        std::cout << Hu.back().x + 1 << " " << Sp * Hu.back().x + Hu.back().y + add << "\n";
    }
    return 0;
}