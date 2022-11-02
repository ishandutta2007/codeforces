#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define double long double

struct Point
{
    int x, y;
    Point(int x2 = 0, int y2 = 0) {
        x = x2; y = y2;
    }
};

struct Vector
{
    int x, y;
    Vector(Point a = {0, 0}, Point b = {0, 0}) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    int len() {
        return x * x + y * y;
    }
};

istream& operator>>(istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream &out, Point &p) {
    out << p.x << " " << p.y;
    return out;
}

ostream& operator<<(ostream &out, Vector &v) {
    out << v.x << " " << v.y;
    return out;
}

int cross(const Vector &v1, const Vector &v2) {
    double x1 = v1.x, y1 = v1.y;
    double x2 = v2.x, y2 = v2.y;
    if (x1 * y2 == y1 * x2) {
        return 0;
    }
    if (x1 * y2 > y1 * x2) {
        return 1;
    }
    if (x1 * y2 < y1 * x2) {
        return -1;
    }
}

Point operator+(Point p, Vector v) {
    Point ans = p;
    ans.x += v.x;
    ans.y += v.y;
    return ans;
}

Vector operator+(Vector v1, Vector v2) {
    Vector ans = Vector();
    ans.x += v1.x + v2.x;
    ans.y += v1.y + v2.y;
    return ans;
}

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

bool point_in_angle(const Point &a, const Point &b, const Point &c, const Point &p) {
    return cross(Vector(b, p), Vector(b, a)) * cross(Vector(b, p), Vector(b, c)) <= 0 || b == p;
}

bool point_in_cpoly(const vector<Point> &poly, const Point &p) {
    int n = poly.size();
    if (!point_in_angle(poly[n - 1], poly[0], poly[1], p)) {
        return false;
    }
    int l = 1, r = n - 1;
    while (r - l > 1) {
        // cout << l << " " << r << endl;
        int m = (l + r) / 2;
        if (point_in_angle(poly[l], poly[0], poly[m], p)) {
            r = m;
        } else {
            l = m;
        }
    }
    // cout << l << " " << r << endl;
    return point_in_angle(poly[0], poly[r], poly[l], p) && point_in_angle(poly[r], poly[l], poly[0], p);
}

int64_t len(Vector v) {
    return v.x * v.x + v.y * v.y;
}

bool cmp(const Vector &a, const Vector &b) {
    if (a.y <= 0 && b.y > 0) {
        return false;
    }
    if (a.y > 0 && b.y <= 0) {
        return true;
    }
    if (a.y == 0 && b.y == 0) {
        return a.x < b.x;
    }
    if (cross(a, b) > 0) {
        return true;
    } else if (cross(a, b) == 0) {
        return len(a) < len(b);
    }
    return false;
}

main() {
    int n = 0;
    vector<Vector> al;
    Point p0 = Point(0, 0);
    for (int num = 0; num < 3; ++num) {
        int k;
        cin >> k;
        n += k;
        vector<Point> poly(k);
        Point min_p = Point(1e9, 1e9);
        for (int i = 0; i < k; ++i) {
            cin >> poly[i];
            if (poly[i].y < min_p.y) {
                min_p = poly[i];
            } else if (poly[i].y == min_p.y) {
                if (poly[i].x > min_p.x) {
                    min_p = poly[i];
                }
            }
        }
        p0.x += min_p.x;
        p0.y += min_p.y;
        for (int i = 0; i < k; ++i) {
            Vector v = Vector(poly[i], poly[(i + 1) % k]);
            al.push_back(v);
        }
    }
    sort(al.begin(), al.end(), cmp);
    vector<Vector> al2;
    al2.push_back(al[0]);
    for (int i = 1; i < n; ++i) {
        // cout << al[i] << endl;
        int k = al2.size();
        if (cross(al2[k - 1], al[i]) == 0) {
            al2[k - 1] = al2[k - 1] + al[i];
        } else {
            // cout << i << endl;
            al2.push_back(al[i]);
        }
    }
    n = al2.size();
    /*for (int i = 0; i < n; ++i) {
        cout << al2[i] << endl;
    }*/
    vector<Point> poly(n);
    poly[0] = p0;
    // cout << p0 << endl;
    for (int i = 1; i < n; ++i) {
        poly[i] = poly[i - 1] + al2[i - 1];
        // cout << poly[i] << endl;
    }
    assert(poly[n - 1] + al2[n - 1] == p0);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        Point p;
        cin >> p;
        p.x *= 3;
        p.y *= 3;
        if (point_in_cpoly(poly, p)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    // cout << point_in_angle(poly[n - 1], poly[0], poly[1], Point(3, -1));
    // cout << point_in_angle(poly[9], poly[8], poly[0], Point(0, 2));
    return 0;
}