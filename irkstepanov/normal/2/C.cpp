#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

const ld eps = 0.000001;
const ld pi = 4 * atan (1.0);

bool eq (ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool geq (ld a, ld b)
{
    return eq(a, b) || a - b >= eps;
}

bool leq (ld a, ld b)
{
    return eq(a, b) || b - a >= eps;
}

struct pt
{
    ld x, y;
};

struct line
{
    ld A, B, C;
};

struct vct
{
    ld x, y;
};

struct circle
{
    ld xc, yc, r;
};

line vct_to_line (pt p, vct v)
{
    line ans;
    ans.A = -v.y;
    ans.B = v.x;
    ans.C = p.x * v.y - p.y * v.x;
    return ans;
}

line build_line (pt a, pt b)
{
    line l;
    l.A = a.y - b.y;
    l.B = b.x - a.x;
    l.C = a.x * b.y - b.x * a.y;
    return l;
}

vector <pt> intersect_lines (line l1, line l2)
{
    vector <pt> ans;
    if (eq(l1.A * l2.B, l1.B * l2.A)) return ans;
    if (eq(l1.A, 0)) return intersect_lines(l2, l1);
    pt p;
    p.y = (l1.A * l2.C - l2.A * l1.C) / (l1.B * l2.A - l2.B * l1.A);
    p.x = (l1.B * p.y + l1.C) / l1.A;
    p.x = -p.x;
    ans.pb(p);
    return ans;
}

ld dist (pt a, pt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void build_appollo (pt a, pt b, ld k, line &l, circle &c)
{
    ld x1 = a.x, y1 = a.y;
    ld x2 = b.x, y2 = b.y;
    if (eq(k, 1.0))
    {
        l.A = -2 * (x2 - x1);
        l.B = -2 * (y2 - y1);
        l.C = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1;
    }
    else
    {
        c.xc = (k * k * x2 - x1) / (k * k - 1);
        c.yc = (k * k * y2 - y1) / (k * k - 1);
        c.r = c.xc * c.xc + c.yc * c.yc - (k * k * x2 * x2 - x1 * x1) / (k * k - 1) - (k * k * y2 * y2 - y1 * y1) / (k * k - 1);
        c.r = sqrt(c.r);
    }
}

ld dist (pt a, line l)
{
    ld d = l.A * a.x + l.B * a.y + l.C;
    d = abs(d);
    d /= sqrt(l.A * l.A + l.B * l.B);
    return d;
}

vector <ld> solve_equation (ld a, ld b, ld c) // a != 0
{
    vector <ld> ans;
    ld d = b * b - 4 * a * c;
    if (leq(d, 0.0) && !eq(d, 0.0)) return ans;
    if (eq(d, 0.0))
    {
        ans.pb(-b / 2.0 / a);
        return ans;
    }
    else
    {
        ans.pb((-b - sqrt(d)) / 2.0 / a);
        ans.pb((-b + sqrt(d)) / 2.0 / a);
        return ans;
    }
}

vector <pt> intersect_line_and_circle (line l, circle c)
{
    vector <pt> ans;
    pt o;
    o.x = c.xc, o.y = c.yc;
    ld s = dist(o, l);
    if (geq(s, c.r) && !eq(s, c.r)) return ans;
    if (eq(l.B, 0.0))
    {
        pt p;
        p.x = -l.C / l.A;
        p.y = solve_equation(1, -2 * c.yc, c.yc * c.yc + l.C * l.C / l.A / l.A + c.xc * c.xc + 2 * c.xc * l.C / l.A - c.r * c.r)[0];
        ans.pb(p);
        return ans;
    }
    else
    {
        ld k = -l.A / l.B;
        ld b = -l.C / l.B;
        vector <ld> x;
        x = solve_equation(1 + k * k, -2 * c.xc + 2 * k * b - 2 * c.yc * k, c.xc * c.xc + b * b - 2 * c.yc * b + c.yc * c.yc - c.r * c.r);
        vector <ld> y;
        for (int i = 0; i < x.size(); i++)
            y.pb(k * x[i] + b);
        pt p;
        for (int i = 0; i < x.size(); i++)
        {
            p.x = x[i], p.y = y[i];
            ans.pb(p);
        }
        return ans;
    }
}

vector <pt> intersect_circles (circle c1, circle c2)
{
    ld x1 = c1.xc, y1 = c1.yc, r1 = c1.r;
    ld x2 = c2.xc, y2 = c2.yc, r2 = c2.r;
    line l;
    l.A = 2 * (x2 - x1);
    l.B = 2 * (y2 - y1);
    l.C = x1 * x1 - x2 * x2 + y1 * y1 - y2 * y2 + r2 * r2 - r1 * r1;
    return intersect_line_and_circle(l, c1);
}

int main()
{

    circle c1, c2, c3;
    cin >> c1.xc >> c1.yc >> c1.r;
    cin >> c2.xc >> c2.yc >> c2.r;
    cin >> c3.xc >> c3.yc >> c3.r;

    line l12 = {0, 0, 0}, l23 = {0, 0, 0};
    circle c12 = {0, 0, 0}, c23 = {0, 0, 0};

    pt o1 = {c1.xc, c1.yc}, o2 = {c2.xc, c2.yc}, o3 = {c3.xc, c3.yc};
    build_appollo(o1, o2, c1.r / c2.r, l12, c12);
    build_appollo(o2, o3, c2.r / c3.r, l23, c23);

    vector <pt> ans;
    if (eq(l12.A, 0.0) && eq(l12.B, 0.0) && eq(l12.C, 0.0)) //12 - circle
    {
        if (eq(l23.A, 0.0) && eq(l23.B, 0.0) && eq(l23.C, 0.0)) //23 - circle
            ans = intersect_circles(c12, c23);
        else ans = intersect_line_and_circle(l23, c12);
    }
    else
    {
        if (eq(l23.A, 0.0) && eq(l23.B, 0.0) && eq(l23.C, 0.0))
            ans = intersect_line_and_circle(l12, c23);
        else ans = intersect_lines(l12, l23);
    }
    
    if (!ans.size()) return 0;

    pt p = ans[0];
    ld f1 = 2 * asin(c1.r / dist(p, o1));
    if (ans.size() > 1)
    {
        ld f2 = 2 * asin(c1.r / dist(ans[1], o1));
        if (geq(f2, f1) && !eq(f2, f1)) p = ans[1];
    }

    if (eq(p.x, 0.0)) p.x = 0.0;
    if (eq(p.y, 0.0)) p.y = 0.0;

    cout.precision(10);
    cout << fixed;
    cout << p.x << " " << p.y << "\n";

}