#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
    double cross(point P) { return x * P.y - y * P.x; }
    double dot(point P) { return x * P.x + y * P.y; }
    point operator-(point P) { return point(x - P.x, y - P.y); }
    point operator+(point P) { return point(x + P.x, y + P.y); }
    point operator*(double k) { return point(k * x, k * y); }
};

struct line {
    point p1, p2;
    line() {}
    line(point _p1, point _p2) {
        p1 = _p1;
        p2 = _p2;
    }
};

double signed_area(point p1, point p2, point p3) {
    return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x -
           p3.y * p1.x;
}

const double eps = 1e-8;

bool intersect(line l1, line l2) {
    double a1 = signed_area(l1.p1, l2.p1, l2.p2);
    double a2 = signed_area(l1.p2, l2.p2, l2.p1);
    double a3 = signed_area(l2.p1, l1.p1, l1.p2);
    double a4 = signed_area(l2.p2, l1.p2, l1.p1);
    if (abs(a1) < eps && abs(a2) < eps && abs(a3) < eps && abs(a4) < eps)
        return !((max(l1.p1.x, l1.p2.x) < min(l2.p1.x, l2.p2.x)) ||
                 (max(l2.p1.x, l2.p2.x) < min(l1.p1.x, l1.p2.x)));
    return ((a1 > -eps && a2 > -eps) || (a1 < eps && a2 < eps)) &&
           ((a3 > -eps && a4 > -eps) || (a3 < eps && a4 < eps));
}

point projection(point x, point a, point b) {
    return a + (b - a) * ((x - a).dot(b - a) / (b - a).dot(b - a));
}

point reflection(point x, point a, point b) {
    return x + (projection(x, a, b) - x) * 2;
}

point intersection(point a, point b, point c, point d) {
    return a + (b - a) * ((c - a).cross(d - c) / (b - a).cross(d - c));
}

int main() {
    point pv, pp, p1, p2;
    line wall, mirror;
    scanf("%lf %lf %lf %lf", &pv.x, &pv.y, &pp.x, &pp.y);
    scanf("%lf %lf %lf %lf", &wall.p1.x, &wall.p1.y, &wall.p2.x, &wall.p2.y);
    scanf("%lf %lf %lf %lf", &mirror.p1.x, &mirror.p1.y, &mirror.p2.x,
          &mirror.p2.y);
    if (!intersect(line(pv, pp), mirror) ||
        abs((pv - pp).cross(mirror.p1 - mirror.p2)) < eps) {
        if (!intersect(line(pv, pp), wall)) {
            cout << "YES\n";
        } else {
            double a1 = signed_area(pv, mirror.p1, mirror.p2);
            double a2 = signed_area(pp, mirror.p1, mirror.p2);
            if (a1 * a2 >= -eps) {
                point pp2 = reflection(pp, mirror.p1, mirror.p2);
                point I = intersection(pv, pp2, mirror.p1, mirror.p2);
                if (!intersect(line(pv, I), wall) &&
                    !intersect(line(pp, I), wall) &&
                    min(mirror.p1.x, mirror.p2.x) - eps <= I.x &&
                    I.x <= max(mirror.p1.x, mirror.p2.x) + eps) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "NO\n";
            }
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}