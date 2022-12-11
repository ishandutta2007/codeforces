#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const ld eps = 1e-12;
const ld pi = 4 * atan(1.0);

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool leq(ld a, ld b)
{
    return lt(a, b) || eq(a, b);
}

bool gt(ld a, ld b)
{
    return a - b > eps;
}

bool geq(ld a, ld b)
{
    return gt(a, b) || eq(a, b);
}

struct pt
{
    ld x, y;
    pt() : x(0), y(0) {}
    pt(ld x, ld y) : x(x), y(y) {}
    pt operator-(const pt& other) const
    {
        return {x - other.x, y - other.y};
    }
    pt operator+(const pt& other) const
    {
        return {x + other.x, y + other.y};
    }
    pt operator*(ld k) const
    {
        return {x * k, y * k};
    }
};

ld cross(const pt& p, const pt& q)
{
    return p.x * q.y - p.y * q.x;
}

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct line
{
    ld a, b, c;
    line(const pt& p, const pt& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
        ld tmp = sqrt(a * a + b * b);
        a /= tmp, b /= tmp, c /= tmp;
    }
};

ld polar(const pt& p)
{
    return atan2(p.y, p.x);
}

vector<pll> vct;

void solve(ld x, ld y)
{
    while (lt(x, 0)) {
        x += 2 * pi;
    }
    while (lt(y, 0)) {
        y += 2 * pi;
    }
    if (gt(x, y)) {
        swap(x, y);
    }
    if (leq(x, pi / 2) && geq(y, 3 * pi / 2)) {
        vct.pb(mp(y, 2 * pi));
        vct.pb(mp(0, x));
    } else {
        vct.pb(mp(x, y));
    }
}

struct circle
{
    pt c;
    ld r;
};

vector<pt> intersect(circle& n, circle& m)
{
    ld d = dist(n.c, m.c);
    ld x = d * d - m.r * m.r + n.r * n.r;
    x /= (2 * d);
    line l(m.c, n.c);
    pt v(-l.b, l.a);
    pt p = n.c + v * x;
    ld h = sqrt(n.r * n.r - x * x);
    pt w = {l.a, l.b};
    return {p + w * h, p - w * h};
}

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    double xx, yy, vv, tt;
    ld x_start, y_start, v_start, t_start;
    scanf("%lf%lf%lf%lf", &xx, &yy, &vv, &tt);
    x_start = xx, y_start = yy, v_start = vv, t_start = tt;

    ld d = v_start * t_start;

    int n;
    scanf("%d", &n);

    pt origin = {0, 0};

    while (n--) {
        pt c;
        scanf("%lf%lf", &xx, &yy);
        c.x = xx, c.y = yy;
        ld r;
        scanf("%lf", &vv);
        r = vv;
        c.x -= x_start, c.y -= y_start;
        if (leq(dist(origin, c), r)) {
            cout << fixed;
            cout.precision(12);
            cout << "1\n";
            return 0;
        }
        line l(c, origin);
        pt v(-l.b, l.a);
        ld val1 = dist(origin, c);
        ld val = sqrt(val1 * val1 - r * r);
        if (leq(val, d)) {
            ld alpha = polar(c);
            ld betta = asin(r / dist(origin, c));
            solve(alpha - betta, alpha + betta);
            continue;
        }
        pt f = c - v * r;
        if (geq(dist(origin, f), d)) {
            continue;
        }
        circle c1 = {origin, d};
        circle c2 = {c, r};
        vector<pt> p = intersect(c1, c2);
        solve(polar(p[0]), polar(p[1]));
    }

    sort(all(vct));
    ld len = 0;

    ld pos = 0;
    for (int i = 0; i < sz(vct); ++i) {
        if (leq(vct[i].second, pos)) {
            continue;
        }
        ld c = pos;
        if (gt(vct[i].first, pos)) {
            c = vct[i].first;
        }
        len += vct[i].second - c;
        pos = vct[i].second;
    }

    len /= (2 * pi);
    cout << fixed;
    cout.precision(12);
    cout << len << "\n";

}