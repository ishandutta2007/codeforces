#include <bits/stdc++.h>
using namespace std;

constexpr double EPS = 1e-9;

template <class T>
T det(T a11, T a12, T a21, T a22) {
    return a11 * a22 - a12 * a21;
}

template <class T>
T sq(T x) {
    return x * x;
}

template <class T>
class Vector {
public:
    Vector(T x=0, T y=0) : x(x), y(y) {}

    Vector& operator+=(Vector const& v) { x += v.x; y += v.y; return *this; }
    Vector operator+(Vector const& v) const { Vector u = *this; u += v; return u; }
    Vector& operator-=(Vector const& v) { x -= v.x; y -= v.y; return *this; }
    Vector operator-(Vector const& v) const { Vector u = *this; u -= v; return u; }
    Vector& operator*=(T const c) { x *= c; y *= c; return *this; }
    Vector operator*(T const& c) const { Vector u = *this; u *= c; return u; }
    Vector& operator/=(T const c) { x /= c; y /= c; return *this; }
    Vector operator/(T const& c) const { Vector u = *this; u /= c; return u; }
    bool operator==(Vector const& v) const { return std::abs(x - v.x) < EPS && std::abs(y - v.y) < EPS; }
    bool operator!=(Vector const& v) const { return !(*this == v); }
    T operator*(Vector const& v) const { return x*v.x + y*v.y; }
    T operator[](int idx) const { return idx ? y : x; }

    T length2() const {
        return sq(x) + sq(y);
    }

    double length() const {
        return sqrt(length2());
    }

    double atan2_angle() const {
        return atan2(y, x);
    }

    void normalize() {
        double l = length();
        x /= l;
        y /= l;
    }

    double angle(Vector const& v) const {
        double angle = v.atan2_angle() - atan2_angle();
        const double PI = acos(-1);
        if (angle > PI)
            angle -= PI;
        if (angle <= -PI)
            angle += PI;
        return angle;
    }

    T x, y;
};

template <>
bool Vector<long long>::operator==(Vector<long long> const& v) const {
    return x == v.x && y == v.y; 
}

template <>
void Vector<long long>::normalize() {
    long long g = std::gcd(x, y);
    x /= g;
    y /= g;
}

template <class T>
class Point {
public:
    Point(T x=0, T y=0, int idx=0) : x(x), y(y), idx(idx) {}

    Point& operator+=(Vector<T> const& v) { x += v.x; y += v.y; return *this; }
    Point operator+(Vector<T> const& v) const { Point p = *this; p += v; return p; }
    Point& operator-=(Vector<T> const& v) { x -= v.x; y -= v.y; return *this; }
    Point operator-(Vector<T> const& v) const { Point p = *this; p -= v; return p; }
    Vector<T> operator-(Point const& p) const { return {x - p.x, y - p.y}; }
    bool operator==(Point const& p) { return std::abs(x - p.x) < EPS && std::abs(y - p.y) < EPS; }
    bool operator!=(Point const& p) { return !(*this == p); }

    friend int ccw(Point const &p1, Point const &p2, Point const &p3)
    {
        return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    }

    T x, y;
    int idx;
};

template <>
bool Point<long long>::operator==(Point const& p) {
    return x == p.x && y == p.y;
}

template <class T>
class Line {
public:
    // ax + by + c = 0
    Line(T a, T b, T c) : a(a), b(b), c(c) {}
    // y = kx + d
    Line(T k, T d) : a(k), b(-1), c(d) {}
    // point, point
    Line(Point<T> p, Point<T> q) 
        : a(q.y - p.y), 
          b(p.x - q.x),
          c(p.y * q.x - p.x * q.y) {}
    // point + vector
    Line(Point<T> p, Vector<T> v) :
        a(-v.y), 
        b(v.x), 
        c(p.x*v.y - p.y*v.x) {}

    bool parallel(Line const& other) const {
        return std::abs(det(a, b, other.a, other.b)) < EPS;
    }

    Point<T> intersect(Line const& other) const {
        double d = det(a, b, other.a, other.b);
        double x = -det(c, b, other.c, other.b) / d;
        double y = -det(a, c, other.a, other.c) / d;
        return {x, y};
    }

    double distance(Point<T> const& p) const {
        return std::abs(a*p.x + b*p.y + c) / Vector<T>(a, b).length();
    }

    bool contains(Point<T> const& p) const {
        return std::abs(a*p.x + b*p.y + c) < EPS;
    }

    T a, b, c;
};

template <>
bool Line<long long>::parallel(Line<long long> const& other) const {
    return det(a, b, other.a, other.b) == 0;
}

template <>
bool Line<long long>::contains(Point<long long> const& p) const {
    return a*p.x + b*p.y + c == 0;
}

using P = Point<int>;

vector<int> res;
int n;

template <typename ITER>
void f(ITER begin, ITER end) {
    int size = end - begin;
    if (size == 0)
        return;
    // if (size == 2) {
    //     int x = points[0].idx;
    //     int y = points[1].idx;
    //     res[min(x, y)] = max(x, y) - n;
    //     return;
    // }

    sort(begin, end, [](auto const &p, auto const &q) {
        return std::make_pair(p.y, p.x) < std::make_pair(q.y, q.x);
    });
    sort(begin + 1, end, [ref = *begin](auto const &p, auto const &q) {
         return ccw(ref, p, q) < 0;
     });

    int cnt = 0;
    ITER j = begin;
    for (auto i = begin; i < end; i++) {
        cnt += i->idx < n ? -1 : 1;
        if (cnt == 0 && (i->idx < n != begin->idx < n)) {
            if (min(j - begin, end - j) < min(i - begin, end - i))
                j = i;
        }
    }

    int x = begin->idx;
    int y = j->idx;
    res[min(x, y)] = max(x, y) - n;

    f(begin + 1, j);
    f(j + 1, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<P> points(2*n);
    for (int i = 0; i < 2*n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y, i};
    }
    res.resize(n, -1);

    f(points.begin(), points.end());

    for (int x : res) {
        cout << x + 1 << '\n';
    }
}