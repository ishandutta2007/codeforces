#include <bits/stdc++.h>
using namespace std;


static constexpr long long EPS = 1e-9;

static long long det(long long a11, long long a12, long long a21, long long a22) {
    return a11 * a22 - a12 * a21;
}

class Vector {
public:
    Vector(long long x, long long y) : x(x), y(y) {}

    Vector& operator+=(Vector const& v) { x += v.x; y += v.y; return *this; }
    Vector operator+(Vector const& v) const { Vector u = *this; u += v; return u; }
    Vector& operator-=(Vector const& v) { x -= v.x; y -= v.y; return *this; }
    Vector operator-(Vector const& v) const { Vector u = *this; u -= v; return u; }
    Vector& operator*=(long long const c) { x *= c; y *= c; return *this; }
    Vector operator*(long long const& c) const { Vector u = *this; u *= c; return u; }
    Vector& operator/=(long long const c) { x /= c; y /= c; return *this; }
    Vector operator/(long long const& c) const { Vector u = *this; u /= c; return u; }
    bool operator==(Vector const& v) const { return std::abs(x - v.x) < EPS && std::abs(y - v.y) < EPS; }
    bool operator!=(Vector const& v) const { return !(*this == v); }
    long long operator*(Vector const& v) const { return x*v.x + y*v.y; }

    long long length2() const {
        return x*x + y*y;
    }

    long long length() const {
        return sqrt(length2());
    }

    long long atan2_angle() const {
        return atan2(y, x);
    }

    void normalize() {
        long long l = length();
        x /= l;
        y /= l;
    }

    long long angle(Vector const& v) const {
        return acos(*this * v / length() / v.length());
    }

    long long x, y;
};

class Point {
public:
    Point() : x(0), y(0) {}
    Point(long long x, long long y) : x(x), y(y) {}

    Point& operator+=(Vector const& v) { x += v.x; y += v.y; return *this; }
    Point operator+(Vector const& v) const { Point p = *this; p += v; return p; }
    Point& operator-=(Vector const& v) { x -= v.x; y -= v.y; return *this; }
    Point operator-(Vector const& v) const { Point p = *this; p -= v; return p; }
    Vector operator-(Point const& p) const { return {p.x - x, p.y - y}; }
    bool operator==(Point const& p) { return std::abs(x - p.x) < EPS && std::abs(y - p.y) < EPS; }
    bool operator!=(Point const& p) { return !(*this == p); }

    long long x, y;
};

class Line {
public:
    // ax + by + c = 0
    Line(long long a, long long b, long long c) : a(a), b(b), c(c) {}
    // y = kx + d
    Line(long long k, long long d) : a(k), b(-1), c(d) {}
    // point, point
    Line(Point p, Point q) {
        long long x_diff = q.x - p.x;
        if (std::abs(x_diff) < EPS) {
            a = 1;
            b = 0;
            c = -q.x;
        } else {
            a = q.y - p.y;
            b = p.x - q.x;
            c = p.y * q.x - p.x * q.y;
        }
    }
    // point + vector
    Line(Point p, Vector v) {
        a = -v.y;
        b = v.x;
        c = p.x*v.y - p.y*v.x;
    }

    bool parallel(Line const& other) const {
        return std::abs(det(a, b, other.a, other.b)) < EPS;
    }

    Point intersect(Line const& other) const {
        long long d = det(a, b, other.a, other.b);
        long long x = -det(c, b, other.c, other.b) / d;
        long long y = -det(a, c, other.a, other.c) / d;
        return {x, y};
    }

    long long distance(Point const& p) const {
        return std::abs(a*p.x + b*p.y + c);
    }

    long long a, b, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    int idx1 = 0;
    int idx2 = 1;
    for (int i = 2; i < n; i++) {
        if ((points[idx1] - points[idx2]).length2() > (points[idx1] - points[i]).length2()) 
            idx2 = i;
    }

    Line l(points[idx1], points[idx2]);
    int idx3 = 0;
    for (int i = 0; i < n; i++) {
        if (i == idx1 || i == idx2) continue;
        if ((idx3 == 0 || l.distance(points[idx3]) > l.distance(points[i])) && l.distance(points[i]) > 0)
            idx3 = i;
    }

    cout << idx1 + 1 << " " << idx2 + 1 << " " << idx3 + 1 << '\n';
}