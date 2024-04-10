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
        return v.atan2_angle() - atan2_angle();
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
    bool operator!=(Point const& p) { return !(*this == p); }

    T x, y;
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

template <class T>
class Circle {
public:
    Circle(Point<T> m, T r) : m(m), r(r) {}
    Circle(T r) : m({0, 0}), r(r) {}

    bool inside(Point<T> p) {
        return (p - m).length2() < r*r;
    }

    std::vector<Point<T>> intersect(Line<T> line) {
        std::vector<Point<T>> intersections;
        T a = line.a;
        T b = line.b;
        T c = a*m.x + b*m.y + line.c;
        double d2 = sq(a) + sq(b);
        Point<T> closest(-a*c/d2, -b*c/d2);

        T diff = sq(r)*d2 - sq(c);
        if (diff > EPS) {
            double d = sq(r) - sq(c)/d2;
            double factor = sqrt(d / d2);
            intersections.push_back(closest + Vector<T>{b, -a} * factor);
            intersections.push_back(closest + Vector<T>{-b, a} * factor);
        } else if (std::abs(diff) <= EPS) {
            intersections.push_back(closest);
        }

        for (auto& p : intersections)
            p += Vector<T>{m.x, m.y};
        return intersections;
    }

    std::vector<Point<T>> intersect(Circle other) {
        Line<T> line(2*(other.m.x - m.x), 
                  2*(other.m.y - m.y), 
                  sq(other.r) - sq(r) + sq(m.x) + sq(m.y)
                  - sq(other.m.x) - sq(other.m.y));
        return intersect(line);
    }

    Point<T> m;
    T r;
};


template <typename T>
class Matrix : public std::vector<std::vector<T>> {
public:
    Matrix(int n, int m, T init=0) 
        : std::vector<std::vector<T>>(n, std::vector<T>(m, init)) {}
};

template <typename T>
std::vector<T> operator*(std::vector<T> const& v, Matrix<T> const& M) {
    std::vector<T> res(v.size(), 0);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)res.size(); j++)
            res[i] += v[j] * M[j][i];
    }
    return res;
}

template <typename T>
std::vector<T> operator*(Matrix<T> const& M, std::vector<T> const& v) {
    std::vector<T> res(M.size(), 0);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++)
            res[i] += M[i][j] * v[j];
    }
    return res;
}

template <typename T>
Matrix<T> operator*(Matrix<T> const& A, Matrix<T> const& B) {
    auto res = A;
    for (int i = 0; i < (int)res.size(); i++)
        res[i] = A[i] * B;
    return res;
}

template <typename T>
Matrix<T> operator+(Matrix<T> const& A, Matrix<T> const& B) {
    auto res = A;
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)res[0].size(); j++) {
            res[i][j] += B[i][j];
        }
    }
    return res;
}

template <typename T>
Matrix<T> createTranslation2D(Point<T> from, Point<T> to) {
    auto vec = to - from;
    Matrix<T> translation(3, 3);
    for (int i = 0; i < 2; i++) {
        translation[i][i] = 1;
        translation[i][2] = vec[i];
    }
    translation[2][2] = 1;
    return translation;
}

Matrix<double> createRotation2D(double angleRadian) {
    Matrix<double> rotation(3, 3);
    rotation[0][0] = rotation[1][1] = std::cos(angleRadian);
    rotation[0][1] = -std::sin(angleRadian);
    rotation[1][0] = -rotation[0][1];
    rotation[2][2] = 1;
    return rotation;
}

template<typename T>
Point<T> operator*(Matrix<T> const& M, Point<T> p) {
    vector<T> v = {p.x, p.y, 1};
    auto res = M * v;
    return {res[0], res[1]};
}

template<typename T>
double signedArea(std::vector<Point<T>> polygon) {
    auto translate = Point<T>{0, 0} - polygon[0];
    for (auto& p : polygon)
        p += translate;

    double area = 0;
    for (int i = 0; i < (int)polygon.size(); i++) {
        auto p = i ? polygon[i-1] : polygon.back();
        auto q = polygon[i];
        area += (double)p.x*q.y - (double)q.x*p.y;
    }
    return area / 2;
}

Point<double> centerOfGravity(std::vector<Point<double>> polygon) {
    auto translate = Point<double>{0, 0} - polygon[0];
    for (auto& p : polygon)
        p += translate;

    double Cx = 0;
    double Cy = 0;
    for (int i = 0; i < (int)polygon.size(); i++) {
        auto p = i ? polygon[i-1] : polygon.back();
        auto q = polygon[i];
        Cx += (p.x + q.x)  * (p.x * q.y - p.y * q.x);
        Cy += (p.y + q.y)  * (p.x * q.y - p.y * q.x);
    }
    double area = signedArea(polygon);
    Point<double> center = {Cx / 6 / area, Cy / 6 / area};
    return center - translate;
}

using dPoint = Point<double>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(10);

    int n, m;
    cin >> n >> m;

    vector<dPoint> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    auto center = centerOfGravity(points);
    int nails = 0 ^ 1;
    Matrix<double> M(3, 3);
    M[0][0] = M[1][1] = M[2][2] = 1;

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 2) {
            int x;
            cin >> x;
            auto P = M * points[x-1];
            cout << P.x << " " << P.y << '\n';
        } else {
            int f, t;
            cin >> f >> t;
            nails ^= f-1;
            double angle = (center - points[nails]).angle({0, -1});
            auto old_pos = M * points[nails];
            
            auto M1 = createTranslation2D(points[nails], {0, 0});
            auto M2 = createRotation2D(angle);
            auto M3 = createTranslation2D({0, 0}, old_pos);
            M = M3 * M2 * M1;

            nails ^= t-1;
        }
    }
}