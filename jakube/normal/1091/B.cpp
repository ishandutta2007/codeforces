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
    bool operator<(Vector const& v) const { return x < v.x || (x == v.x && y < v.y); }
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
    Point(T x=0, T y=0) : x(x), y(y) {}

    Point& operator+=(Vector<T> const& v) { x += v.x; y += v.y; return *this; }
    Point operator+(Vector<T> const& v) const { Point p = *this; p += v; return p; }
    Point& operator-=(Vector<T> const& v) { x -= v.x; y -= v.y; return *this; }
    Point operator-(Vector<T> const& v) const { Point p = *this; p -= v; return p; }
    Vector<T> operator-(Point const& p) const { return {x - p.x, y - p.y}; }
    bool operator==(Point const& p) { return std::abs(x - p.x) < EPS && std::abs(y - p.y) < EPS; }
    bool operator!=(Point const& p) const { return !(*this == p); }
    bool operator<(Point const& p) const { return x < p.x || (x == p.x && y < p.y); }
    friend std::istream& operator>>(std::istream& is, Point<T>& pt) { return is >> pt.x >> pt.y; }
    friend std::ostream& operator<<(std::ostream& os, Point<T> const& pt) { return os << pt.x << " " << pt.y; }

    T x, y;
};

using P = Point<int>;
using V = Vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<P> xy(n);
    for (auto& x : xy)
        cin >> x.x >> x.y;
    vector<V> ab(n);
    for (auto& x : ab)
        cin >> x.x >> x.y;
    set<V> vectors(ab.begin(), ab.end());
    
    for (int i = 0; i < n; i++) {
        P treasure = xy[0] + ab[i];

        bool possible = true;
        for (P p : xy)
            possible &= vectors.count(treasure - p) > 0;
        if (possible) {
            cout << treasure << '\n';
            return 0;
        }
    }
     
}