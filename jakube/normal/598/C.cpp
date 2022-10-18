#include <bits/stdc++.h>
using namespace std;

static constexpr long double EPS = 1e-9;

static long double det(long double a11, long double a12, long double a21, long double a22) {
    return a11 * a22 - a12 * a21;
}

class Vector {
public:
    Vector(long double x, long double y) : x(x), y(y) {}

    Vector& operator+=(Vector const& v) { x += v.x; y += v.y; return *this; }
    Vector operator+(Vector const& v) const { Vector u = *this; u += v; return u; }
    Vector& operator-=(Vector const& v) { x -= v.x; y -= v.y; return *this; }
    Vector operator-(Vector const& v) const { Vector u = *this; u -= v; return u; }
    Vector& operator*=(long double const c) { x *= c; y *= c; return *this; }
    Vector operator*(long double const& c) const { Vector u = *this; u *= c; return u; }
    Vector& operator/=(long double const c) { x /= c; y /= c; return *this; }
    Vector operator/(long double const& c) const { Vector u = *this; u /= c; return u; }
    bool operator==(Vector const& v) const { return std::abs(x - v.x) < EPS && std::abs(y - v.y) < EPS; }
    bool operator!=(Vector const& v) const { return !(*this == v); }
    long double operator*(Vector const& v) const { return x*v.x + y*v.y; }

    long double length2() const {
        return x*x + y*y;
    }

    long double length() const {
        return sqrt(length2());
    }

    long double slope() const {
        return atan2(y, x);
    }

    void normalize() {
        long double l = length();
        x /= l;
        y /= l;
    }

    long double angle(Vector const& v) const {
        return acos(*this * v / length() / v.length());
    }

    long double x, y;
};

class Point {
public:
    Point(long double x, long double y) : x(x), y(y) {}

    Point& operator+=(Vector const& v) { x += v.x; y += v.y; return *this; }
    Point operator+(Vector const& v) const { Point p = *this; p += v; return p; }
    Point& operator-=(Vector const& v) { x -= v.x; y -= v.y; return *this; }
    Point operator-(Vector const& v) const { Point p = *this; p -= v; return p; }
    Vector operator-(Point const& p) const { return {p.x - x, p.y - y}; }
    bool operator==(Point const& p) { return std::abs(x - p.x) < EPS && std::abs(y - p.y) < EPS; }
    bool operator!=(Point const& p) { return !(*this == p); }

    long double x, y;
};

class Line {
public:
    // ax + by + c = 0
    Line(long double a, long double b, long double c) : a(a), b(b), c(c) {}
    // y = kx + d
    Line(long double k, long double d) : a(k), b(-1), c(d) {}
    // point, point
    Line(Point p, Point q) {
        long double x_diff = q.x - p.x;
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
        long double d = det(a, b, other.a, other.b);
        long double x = -det(c, b, other.c, other.b) / d;
        long double y = -det(a, c, other.a, other.c) / d;
        return {x, y};
    }

    long double distance(Point const& p) const {
        return std::abs(a*p.x + b*p.y + c) / Vector(a, b).length();
    }

    long double a, b, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<long double, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({Vector(x, y).slope(), i+1});
    }
    sort(v.begin(), v.end());
    auto t = v.front();
    t.first += 2*acos(-1);
    v.push_back(t);
    
    long double m = 999;
    int a, b;
    for (int i = 0; i < n; i++) {
        long double diff = v[i+1].first - v[i].first;
        if (diff < m) {
            a = v[i].second;
            b = v[i+1].second;
            m = diff;
        }
    }
    cout << a << " " << b << endl;
}