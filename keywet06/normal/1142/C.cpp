#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using float96 = long double;

struct Point {
    int64 x, y;

    Point() : x(), y() {}
    Point(int64 _x, int64 _y) : x(_x), y(_y) {}

    Point operator+(const Point &a) const { return Point(x + a.x, y + a.y); }
    Point operator-(const Point &a) const { return Point(x - a.x, y - a.y); }
    int64 operator*(const Point &a) const { return x * a.y - y * a.x; }

    double len() const { return sqrtl(float96(x) * x + float96(y) * y); }

    bool operator<(const Point &a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
};

const int N = 100100;
int n;
Point a[N];
Point h[N];
int m;

bool cmp(const Point &v, const Point &u) {
    int64 x = v * u;
    if (x != 0) return x > 0;
    return v.len() < u.len();
}

void graham() {
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        while (m > 1 && (a[i] - h[m - 1]) * (a[i] - h[m - 2]) >= 0) --m;
        h[m++] = a[i];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int64 x, y;
        scanf("%lld%lld", &x, &y);
        a[i] = Point(x, y - x * x);
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i) a[i] = a[i] - a[0];
    graham();
    h[m] = h[0];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (h[i + 1].x < h[i].x) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}