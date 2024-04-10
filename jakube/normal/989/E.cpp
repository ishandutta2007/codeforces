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

template <typename T>
class Matrix : public std::vector<std::vector<T>> {
public:
    Matrix(int n=0, int m=0, T init=0) 
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point<long long>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    Matrix<double> M(n, n, 0);
    vector<vector<int>> all_lines;
    for (int i = 0; i < n; i++) {
        auto p = points[i];
        vector<pair<Line<long long>, vector<int>>> line_indices;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            auto q = points[j];
            bool found = false;
            for (auto& l_i : line_indices) {
                if (l_i.first.contains(q)) {
                    l_i.second.push_back(j);
                    found = true;
                    break;
                }
            }
            if (!found) 
                line_indices.push_back({{p, q}, {i, j}});
        }
        double p_lines = 1.0 / line_indices.size();
        for (auto [line, indices] : line_indices) {
            double p_line = 1. / indices.size();
            for (auto x : indices) {
                M[i][x] += p_lines * p_line;
            }
            if (indices[0] < indices[1])
                all_lines.push_back(indices);
        }
    }

    vector<Matrix<double>> powers(15);
    powers[0] = M;
    for (int i = 1; i < 15; i++) {
        powers[i] = powers[i-1] * powers[i-1];
    }

    std::cout << std::fixed << std::setprecision(20);
    int q;
    cin >> q;
    for (int Q = 0; Q < q; Q++) {
        int t, m;
        cin >> t >> m;
        vector<double> v(n, 0);
        t--, m--;
        v[t] = 1;
        int e = 0;
        while (m) {
            if (m & 1)
                v = powers[e] * v;
            e++;
            m >>= 1;
        }
        
        double best = 0;
        for (const auto& line : all_lines) {
            double sum = 0;
            for (int x : line)
                sum += v[x];
            sum /= line.size();
            best = max(best, sum);
        }
        cout << best << '\n';
    }
}