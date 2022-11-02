#include <bits/stdc++.h>

typedef long double dou;

std::pair<dou, int> a[200002];

inline dou dist(dou x, dou y) { return sqrtl(x * x + y * y); }

inline dou cal(dou ax, dou ay, dou bx, dou by, dou x, dou y, dou T) {
    dou rx = (ax + bx) / 2 + (ay - by) * T;
    dou ry = (ay + by) / 2 + (bx - ax) * T;
    return dist(rx - ax, ry - ay) - dist(rx - x, ry - y);
}

inline dou F(dou ax, dou ay, dou bx, dou by, dou x, dou y, dou r) {
    dou L = -1e12, R = 1e12;
    int Lv = cal(ax, ay, bx, by, x, y, L) > r;
    int Rv = cal(ax, ay, bx, by, x, y, R) > r;
    for (int i = 0; i < 100; ++i) {
        dou M = (L + R) / 2;
        int Mv = cal(ax, ay, bx, by, x, y, M) > r;
        (Lv == Mv ? L : R) = M;
    }
    return L;
}

int main() {
    dou ax, ay, bx, by;
    int i, j, n;
    std::cin >> ax >> ay >> bx >> by >> n;
    for (i = 0; i < n; ++i) {
        dou x, y, r;
        scanf("%Lf%Lf%Lf", &x, &y, &r);
        dou L = F(ax, ay, bx, by, x, y, r), R = F(ax, ay, bx, by, x, y, -r);
        if (L > R) std::swap(L, R);
        a[i].first = L, a[i].second = 1;
        a[i + n].first = R, a[i + n].second = -1;
    }
    a[n + n].first = 0;
    a[n + n].second = 0;
    sort(a, a + n + n + 1);
    dou R = 1e12;
    for (i = j = 0; i <= n + n; ++i) {
        if (!j && fabsl(a[i].first) < R) R = fabsl(a[i].first);
        j += a[i].second;
        if (!j && fabsl(a[i].first) < R) R = fabsl(a[i].first);
    }
    std::cout << std::fixed << std::setprecision(12) << sqrtl(.25 + R * R) * dist(ax - bx, ay - by) << '\n';
    return 0;
}