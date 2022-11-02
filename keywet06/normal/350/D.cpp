#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;

    Point() { x = y = 0; }

    Point(int x, int y) : x(x), y(y) {}

    void in() { scanf("%d%d", &x, &y); }

    int dist2() { return x * x + y * y; }

    Point rotate() { return Point(y, -x); }

    Point simplify() {
        int xx = x, yy = y;
        if (xx < 0 || xx == 0 && yy < 0) {
            xx = -xx;
            yy = -yy;
        }
        int g = __gcd(abs(xx), abs(yy));
        xx /= g;
        yy /= g;
        return Point(xx, yy);
    }

    Point dec(Point k);
};

struct Circle {
    Point o;
    int r;

    Circle() { o.x = o.y = r = 0; }

    Circle(Point x, int r) : o(x), r(r) {}

    void in() {
        o.in();
        scanf("%d", &r);
    }
};

Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }

Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }

Point operator*(Point a, int k) { return Point(a.x * k, a.y * k); }

bool operator<(Point a, Point b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

Point Point::dec(Point k) {
    if (k.x == 0) {
        return Point(x, 0);
    } else {
        int q = x / k.x;
        Point a = *this - k * q;
        while (a.x < 0) {
            if (k.x > 0) {
                a = a + k;
            } else {
                a = a - k;
            }
        }
        return a;
    }
}

const int N = 300000, M = 1500;
int n, m;
Point a[N], b[N];
Circle c[M];

struct Ent {
    pair<Point, Point> l;
    pair<Point, int> t;

    Ent(Point a, Point b, Point c, int e) {
        l = make_pair(a, b);
        t = make_pair(c, e);
    }
};

bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

bool operator<(const Ent &a, const Ent &b) {
    return a.l < b.l || a.l == b.l && a.t < b.t;
}

int main() {
    vector<Ent> v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        a[i].in(), b[i].in();
        if (!(a[i] < b[i])) swap(a[i], b[i]);
        Point k = (a[i] - b[i]).simplify();
        Point k2 = (a[i] * 2).dec(k);
        v.push_back(Ent(k, k2, a[i] * 2, -1));
        v.push_back(Ent(k, k2, b[i] * 2, 1));
    }
    for (int i = 0; i < m; ++i) c[i].in();
    vector<pair<Point, Point> > key;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (c[i].r == c[j].r &&
                (c[i].o - c[j].o).dist2() > c[i].r * c[i].r * 4) {
                Point k = (c[i].o - c[j].o).rotate().simplify();
                Point k2 = (c[i].o + c[j].o).dec(k);
                v.push_back(Ent(k, k2, c[i].o + c[j].o, 0));
            }
        }
    }
    long long ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
        int j = i;
        while (j + 1 < (int)v.size() && v[i].l == v[j + 1].l) ++j;
        int cnt = 0;
        while (i <= j) {
            if (v[i].t.second == -1) {
                ++cnt;
            } else if (v[i].t.second == 0) {
                ans += cnt;
            } else {
                --cnt;
            }
            ++i;
        }
        --i;
    }
    cout << ans << endl;
    return 0;
}