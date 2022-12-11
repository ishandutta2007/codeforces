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
typedef pair<ll, ll> pll;

const ld inf = 1e9;
const ld eps = 1e-5;

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool lt(ld a, ld b)
{
    return b - a > eps;
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
    pt operator*(ld k) const
    {
        return {x * k, y * k};
    }
    bool operator==(const pt& other) const
    {
        return eq(x, other.x) && eq(y, other.y);
    }
};

ld cross(const pt& p, const pt& q)
{
    return p.x * q.y - p.y * q.x;
}

ld dot(const pt& p, const pt& q)
{
    return p.x * q.x + p.y * q.y;
}

struct line
{
    ld a, b, c;
    line() {}
    line(const pt& p, const pt& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
        ld tmp = sqrt(a * a + b * b);
        a /= tmp, b /= tmp, c /= tmp;
    }
    line(ld a, ld b, ld c) : a(a), b(b), c(c) {}
};

pt intersect(const line& l, const line& m)
{
    ld a1 = l.a, b1 = l.b, c1 = -l.c;
    ld a2 = m.a, b2 = m.b, c2 = -m.c;
    ld det = a1 * b2 - a2 * b1;
    ld det1 = c1 * b2 - c2 * b1;
    ld det2 = a1 * c2 - a2 * c1;
    return {det1 / det, det2 / det};
}

bool on_seg(const pt& p, const pt& a, const pt& b)
{
    return eq(cross(a - p, b - p), 0) && leq(dot(a - p, b - p), 0);
}

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool comp(const pt& a, const pt& b)
{
    return lt(a.x, b.x);
}

ld solve(const pt& a, const pt& b, const pt& c, const pt& d)
{
    ld ans = inf;
    line l(a, b), m(c, d);
    line t(1, 0, -a.x);
    pt p = intersect(t, m);
    if (on_seg(p, c, d)) {
        ld val = dist(a, p);
        if (lt(val, ans)) {
            ans = val;
        }
    }
    t = line(1, 0, -b.x);
    p = intersect(t, m);
    if (on_seg(p, c, d)) {
        ld val = dist(b, p);
        if (lt(val, ans)) {
            ans = val;
        }
    }
    t = line(1, 0, -c.x);
    p = intersect(t, l);
    if (on_seg(p, a, b)) {
        ld val = dist(c, p);
        if (lt(val, ans)) {
            ans = val;
        }
    }
    t = line(1, 0, -d.x);
    p = intersect(t, l);
    if (on_seg(p, a, b)) {
        ld val = dist(d, p);
        if (lt(val, ans)) {
            ans = val;
        }
    }
    return ans;
}

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<pt> y(n), z(n);

    ld lo = 0, a, b, hi;
    cin >> hi >> a >> b;
    a /= 2, b /= 2;

    y[0] = {a, lo};
    z[0] = {b, hi};

    cout << fixed;
    cout.precision(12);

    for (int j = 1; j < n; ++j) {
        ld h, r, R;
        cin >> h >> r >> R;
        r /= 2, R /= 2;
        lo = 0; // the new lowest border
        for (int i = 0; i < j; ++i) {
            hi = z[i].y;
            pt yy = {r, hi};
            pt zz = {R, hi + h};
            ld down = hi - y[i].y;//   
            if (geq(r, z[i].x)) {
                down = 0;
                if (gt(hi - down, lo)) {
                    lo = hi - down;
                }
                continue;
            }
            ld val1 = solve(y[i], z[i], yy, zz);
            if (lt(val1, down)) {
                down = val1;
            }
            //cout << "!" << down << "\n";
            if (gt(hi - down, lo)) {
                lo = hi - down;
            }
        }
        //cout << lo << "\n";
        y[j] = {r, lo};
        z[j] = {R, lo + h};
    }

    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        if (gt(z[i].y, ans)) {
            ans = z[i].y;
        }
    }
    cout << ans << "\n";

}