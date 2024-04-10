#include <bits/stdc++.h>

using int64 = long long;

int n, m, x, y, vx, vy;

int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }

void gcd(int a, int64 &x, int b, int64 &y) {
    if (a == 0) {
        x = 0, y = 1;
    } else {
        int64 xx, yy;
        gcd(b % a, xx, a, yy);
        x = yy - b / a * xx, y = xx;
    }
}

int main() {
    scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &vx, &vy);
    if (vx == -1 && vy == 0) {
        if (y == 0 || y == m) {
            printf("0 %d\n", y);
        } else {
            printf("-1\n");
        }
    } else if (vx == 1 && vy == 0) {
        if (y == 0 || y == m) {
            printf("%d %d\n", n, y);
        } else {
            printf("-1\n");
        }
    } else if (vx == 0 && vy == -1) {
        if (x == 0 || x == n) {
            printf("%d 0\n", x);
        } else {
            printf("-1\n");
        }
    } else if (vx == 0 && vy == 1) {
        if (x == 0 || x == n) {
            printf("%d %d\n", x, m);
        } else {
            printf("-1\n");
        }
    } else {
        int X0 = 0, X1 = n, Y0 = 0, Y1 = m;
        if (vx != 1) std::swap(X0, X1), x = n - x;
        if (vy != -1) std::swap(Y0, Y1), y = m - y;
        int a = n, b = m, c = x + y, g = gcd(a, b);
        a /= g, b /= g;
        if (c % g) return printf("-1\n"), 0;
        c /= g;
        int64 x, y;
        gcd(a, x, b, y);
        x *= c, y *= c;
        if (x > 0) {
            int64 tk = x / b + bool(x % b);
            x -= b * tk, y += a * tk;
        }
        if (y <= 0) {
            int64 tk = (-y) / a + 1;
            x -= b * tk, y += a * tk;
        }
        int64 tk = std::max((-x) / b + 1, y / a + bool(y % a));
        x += b * tk, y -= a * tk;
        printf("%d %d\n", (x % 2 ? X1 : X0), (y % 2 ? Y1 : Y0));
    }
    return 0;
}