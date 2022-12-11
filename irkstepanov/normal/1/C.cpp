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

pt build_outcenter (pt p1, pt p2, pt p3)
{
    line l12, l23;
    l12 = build_line (p1, p2);
    l23 = build_line (p2, p3);
    vct v1, v2;
    v1.x = l12.A, v1.y = l12.B;
    v2.x = l23.A, v2.y = l23.B;
    pt a, b;
    a.x = (p1.x + p2.x) / 2, a.y = (p1.y + p2.y) / 2;
    b.x = (p2.x + p3.x) / 2, b.y = (p2.y + p3.y) / 2;
    line l1, l2;
    l1 = vct_to_line (a, v1);
    l2 = vct_to_line (b, v2);
    return intersect_lines(l1, l2)[0];
}

ld scal (vct a, vct b)
{
    return a.x * b.x + a.y * b.y;
}

ld length (vct a)
{
    return sqrt (a.x * a.x + a.y * a.y);
}

ld angle (pt a, pt c, pt b)
{
    vct v1, v2;
    v1.x = a.x - c.x, v1.y = a.y - c.y;
    v2.x = b.x - c.x, v2.y = b.y - c.y;
    ld cosg = scal (v1, v2) / length (v1) / length (v2);
    if (leq(cosg, -1)) cosg = -1;
    if (geq(cosg, 1)) cosg = 1;
    return acos(cosg);
}

ld dist (pt a, pt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{

    pt a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    pt o = build_outcenter (a, b, c);

    ld alpha1, alpha2;
    alpha1 = angle (a, o, b);
    alpha2 = angle (b, o, c);

    for (int n = 3; n <= 100; n++)
    {
        ld alpha0 = 2 * pi / n;
        bool ok1 = false, ok2 = false;
        for (int j = 1; j <= n; j++)
        {
            if (eq(alpha1, alpha0 * j)) ok1 = true;
            if (eq(alpha2, alpha0 * j)) ok2 = true;
        }
        if (ok1 && ok2)
        {
            ld s = 0.5 * dist(a, o) * dist(a, o) * sin (alpha0) * n;
            cout << fixed;
            cout.precision(6);
            cout << s;
            return 0;
        }
    }

}