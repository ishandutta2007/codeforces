#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

const long double EPS = 1e-7;
const long double phi = 0.6180339887498948482045868343656;

struct TPoint3 {
    long double x, y, z;

    TPoint3(long double _x = 0, long double _y = 0, long double _z = 0)
        : x(_x), y(_y), z(_z) {}

    TPoint3 operator*(long double r) { return TPoint3(x * r, y * r, z * r); }

    TPoint3 operator+(TPoint3 r) { return TPoint3(x + r.x, y + r.y, z + r.z); }

    TPoint3 operator-(TPoint3 r) { return TPoint3(x - r.x, y - r.y, z - r.z); }
};

struct TPoint2 {
    long double x, y;

    TPoint2(long double _x = 0, long double _y = 0) : x(_x), y(_y) {}
};

long double dist(TPoint2 a, TPoint2 b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long double maxD(TPoint2 C, vector<TPoint2> &points) {
    if (points.empty()) {
        return -1e9;
    }
    long double result = dist(C, points[0]);
    for (size_t i = 1; i < points.size(); ++i) {
        result = max(result, dist(C, points[i]));
    }
    return result;
}

long double maxXD(long double X, long double miny, long double maxy,
                  vector<TPoint2> &points) {
    long double y1 = miny + (1.0 - phi) * (maxy - miny);
    long double y2 = miny + phi * (maxy - miny);
    long double f1 = maxD(TPoint2(X, y1), points);
    long double f2 = maxD(TPoint2(X, y2), points);
    while (maxy - miny > EPS) {
        if (f1 < f2) {
            maxy = y2;
            y2 = y1;
            f2 = f1;
            y1 = miny + (1.0 - phi) * (maxy - miny);
            f1 = maxD(TPoint2(X, y1), points);
        } else {
            miny = y1;
            y1 = y2;
            f1 = f2;
            y2 = miny + phi * (maxy - miny);
            f2 = maxD(TPoint2(X, y2), points);
        }
    }
    return maxD(TPoint2(X, miny), points);
}

long double minR(vector<TPoint2> &points) {
    if (points.empty()) {
        return 0.0;
    }
    long double minx, maxx, miny, maxy;
    minx = maxx = points[0].x;
    miny = maxy = points[0].y;
    for (size_t i = 1; i < points.size(); ++i) {
        minx = min(minx, points[i].x);
        maxx = max(maxx, points[i].x);
        miny = min(miny, points[i].y);
        maxy = max(maxy, points[i].y);
    }

    long double x1 = minx + (1.0 - phi) * (maxx - minx);
    long double x2 = minx + phi * (maxx - minx);
    long double f1 = maxXD(x1, miny, maxy, points);
    long double f2 = maxXD(x2, miny, maxy, points);
    while (maxx - minx > EPS) {
        if (f1 < f2) {
            maxx = x2;
            x2 = x1;
            f2 = f1;
            x1 = minx + (1.0 - phi) * (maxx - minx);
            f1 = maxXD(x1, miny, maxy, points);
        } else {
            minx = x1;
            x1 = x2;
            f1 = f2;
            x2 = minx + phi * (maxx - minx);
            f2 = maxXD(x2, miny, maxy, points);
        }
    }

    return maxXD(minx, miny, maxy, points);
}

long double scal(TPoint3 &a, TPoint3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

TPoint3 vectmul(TPoint3 &a, TPoint3 &b) {
    return TPoint3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<TPoint3> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }

    for (int M = 0; M < m; ++M) {
        int A, B, C;
        cin >> A >> B >> C;
        TPoint3 vect = TPoint3(A, B, C);
        long double r = sqrt(1.0 * scal(vect, vect));
        vect = vect * (1.0 / r);
        int d = -1;
        for (int i = 0; i < n; ++i) {
            TPoint3 v = points[i] - vect * (scal(points[i], vect));
            if (scal(v, v) > EPS) {
                d = i;
                break;
            }
        }
        if (d < 0) {
            printf("%.10lf\n", 0.0);
            continue;
        }

        TPoint3 v1 = points[d] - vect * (scal(points[d], vect));
        v1 = v1 * (1.0 / sqrt(scal(v1, v1)));
        TPoint3 v2 = vectmul(vect, v1);
        vector<TPoint2> points2(n);
        for (int i = 0; i < n; ++i) {
            TPoint3 cur = points[i] - vect * (scal(points[i], vect));
            points2[i].x = scal(cur, v1);
            points2[i].y = scal(cur, v2);
        }

        printf("%.10Lf\n", sqrt(minR(points2)));
    }

    return 0;
}