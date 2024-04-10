#include <bits/stdc++.h>
using namespace std;

constexpr double EPS = 1e-9;

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

    T x, y;
};

vector<Vector<double>> points;
vector<int> results, depend;
int n;

struct S {
    int first = 0, second = 0;
    int minus = 0;
};

void dfs(int a, int b, int c) {
    if (c > n)
        return;
    if (c == n) {
        auto p = points[a];
        auto q = points[b];
        if ((p + q).length() > (p - q).length())
            results[b] *= -1;
        return;
    }

    pair<double, S> m = {1e9, {}};
    array<int, 3> arr = {a, b, c};
    for (int first = 0; first < 3; first++) {
        for (int second = first + 1; second < 3; second++) {
            for (int minus = 0; minus < 2; minus++) {
                auto x = points[arr[first]];
                auto y = points[arr[second]];
                auto z = minus ? x - y : x + y;
                if (z.length() < m.first)
                    m = {z.length(), {arr[first], arr[second], minus}};
            }
        }
    }
    auto best = m.second;
    if (best.minus) {
        results[best.second] *= -1;
        points[best.first] -= points[best.second];
    } else {
        points[best.first] += points[best.second];
    }
    
    dfs(best.first, best.first ^ best.second ^ a ^ b ^ c, c + 1);
    results[best.second] *= results[best.first];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    points.resize(n);
    for (auto& p : points)
        cin >> p.x >> p.y;
    results.assign(n, 1);
    depend.assign(n, -1);
    dfs(0, 1, 2);
    for (auto x : results)
        cout << x << " ";
    cout << endl;
}