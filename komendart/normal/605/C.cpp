#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y): x(x), y(y) {}

    bool operator < (const Point &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }

    const Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    const Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    const Point operator - () const {
        return Point(-x, -y);
    }

    double length() const {
        return sqrt(x * x + y * y);
    }
};

double wedge_product(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    double a, b, c;

    Line(const Point &p, const Point &q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -(a * p.x + b * p.y);
    }

    Point intersect(const Line &line) {
        double y = -(c * line.a - a * line.c) / (b * line.a - a * line.b);
        double x = -(c * line.b - b * line.c) / (a * line.b - b * line.a);
        return Point(x, y);
    }
};

bool include(Point a, Point b, Point c) {
    int x1 = a.x, x2 = b.x;
    int y1 = a.y, y2 = b.y;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    return x1 <= c.x && c.x <= x2 && y1 <= c.y && c.y <= y2;
}

vector<Point> convex_hull(vector<Point> pt) {
    sort(pt.begin(), pt.end());
    vector<Point> ans;
    for (int t = 0; t < 2; ++t) {
        int start = ans.size();
        for (auto p: pt) {
            while (ans.size() >= start + 2 && wedge_product(ans.back() - ans[ans.size() - 2], ans.back() - p) >= 0) {
                ans.pop_back();
            }
            ans.push_back(p);
        }
        ans.pop_back();
        reverse(pt.begin(), pt.end());
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    Point goal;
    int n;
    cin >> n >> goal.x >> goal.y;
    vector<Point> pt(n);
    double mx = 0, my = 0;
    for (int i = 0; i < n; ++i) {
        cin >> pt[i].x >> pt[i].y;
        mx = max(mx, pt[i].x);
        my = max(my, pt[i].y);
    }
    pt.push_back(Point(0, 0));
    pt.push_back(Point(mx, 0));
    pt.push_back(Point(0, my));

    pt = convex_hull(pt);
    n = pt.size();

    Line v(Point(0, 0), goal);
    double ans = 1e18;
    for (int i = 1; i < n - 1; ++i) {
        Point a = pt[i], b = pt[i + 1];
        Point c = v.intersect(Line(a, b));
        if (include(a, b, c)) {
            ans = min(ans, goal.length() / c.length());
        }
    }

    cout << fixed << setprecision(12) << ans << '\n';
}