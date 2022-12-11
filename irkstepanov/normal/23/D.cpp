 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const ld eps = 1e-12;
const ld inf = 1e18;

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
    pt() {}
    pt(ld x, ld y) : x(x), y(y) {}
    pt operator-(const pt& other) const
    {
        return {x - other.x, y - other.y};
    }
    pt operator+(const pt& other) const
    {
        return {x + other.x, y + other.y};
    }
    pt operator/(ld k) const
    {
        return {x / k, y / k};
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
    line(ld a, ld b, ld c) : a(a), b(b), c(c) {}
    line(const pt& p, const pt& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
        ld tmp = sqrt(a * a + b * b);
        a /= tmp, b /= tmp, c /= tmp;
    }
};

pt intersect(const line& l, const line& m)
{
    ld a1 = l.a, b1 = l.b, c1 = -l.c;
    ld a2 = m.a, b2 = m.b, c2 = -m.c;
    ld det = a1 * b2 - a2 * b1;
    if (eq(det, 0)) {
        return {inf, inf};
    }
    ld det1 = c1 * b2 - c2 * b1;
    ld det2 = a1 * c2 - a2 * c1;
    return {det1 / det, det2 / det};
}

line serper(const pt& a, const pt& b)
{
    line l(a, b);
    pt p = (a + b) / 2.0;
    pt v = {l.a, l.b};
    pt q = p + v;
    return line(p, q);
}

pair<pt, pt> build(const pt& p, const line& l, const line& m)
{
    pt q = intersect(l, m);
    if (eq(q.x, inf) && eq(q.y, inf)) {
        return {{inf, inf}, {inf, inf}};
    }
    pt v = p - q;
    pt r = p + v;
    pt a1 = {l.b, -l.a};
    line l1(r, r + a1);
    pt a2 = {m.b, -m.a};
    line m1(r, r + a2);
    pt y = intersect(l1, m);
    pt x = intersect(m1, l);
    return mp(x, y);
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int tt;
    scanf("%d", &tt);
    //cin >> tt;

    while (tt--) {
        vector<pt> p(3);
        for (int i = 0; i < 3; ++i) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        vector<vector<int> > v = {{0, 1, 2}, {1, 0, 2}, {2, 0, 1}};
        bool out = false;
        for (int i = 0; i < 3; ++i) {
            vector<pt> q(3);
            for (int j = 0; j < 3; ++j) {
                q[j] = p[v[i][j]];
            }
            line l = serper(q[0], q[1]);
            line m = serper(q[0], q[2]);
            pair<pt, pt> w = build(q[0], l, m);
            if (eq(w.first.x, inf) && eq(w.first.y, inf)) {
                continue;
            }
            ld len = dist(w.first, q[0]);
            pt a = w.first, b = w.second;
            //cout << i << " " << a.x << " " << a.y << " " << b.x << " " << b.y << "\n";
            if (!eq(dist(b, q[2]), len) || !eq(dist(a, q[1]), len)) {
                continue;
            }
            pt c = b + (q[2] - b) * 2.0;
            pt d = a + (q[1] - a) * 2.0;
            vector<pt> r = {a, b, c, d};
            bool all_negative = true, all_positive = true;
            for (int j = 0; j < 4; ++j) {
                pt aa = r[(j + 1) % 4] - r[j];
                pt bb = r[(j + 2) % 4] - r[(j + 1) % 4];
                if (geq(cross(aa, bb), 0)) {
                    all_negative = false;
                }
                if (leq(cross(aa, bb), 0)) {
                    all_positive = false;
                }
            }
            if (all_negative || all_positive) {
                printf("YES\n");
                printf("%.9f %.9f %.9f %.9f %.9f %.9f %.9f %.9f\n", a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);
                out = true;
                break;
            }
        }
        if (!out) {
            printf("NO\n\n");
        }
    }

}