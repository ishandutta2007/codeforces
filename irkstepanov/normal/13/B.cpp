#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

struct pt
{
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    bool operator==(const pt& other) const
    {
        return x == other.x && y == other.y;
    }
    pt operator-(const pt& other) const
    {
        return {x - other.x, y - other.y};
    }
};

ll cross(const pt& p, const pt& q)
{
    return p.x * q.y - p.y * q.x;
}

ll dot(const pt& p, const pt& q)
{
    return p.x * q.x + p.y * q.y;
}

ll dist2(const pt& a, const pt& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct line
{
    ll a, b, c;
    line(const pt& p, const pt& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
    }
};

bool on_line(const pt& p, const line& l)
{
    return p.x * l.a + p.y * l.b + l.c == 0;
}

bool on_seg(const pt& p, const pt& a, const pt& b)
{
    line l(a, b);
    if (!on_line(p, l)) {
        return false;
    }
    return dot(a - p, b - p) <= 0;
}

bool solve(pt a, pt b, pt c, pt d, pt e)
{
    if (b == c) {
        return false;
    }
    pt u = b - a, v = c - a;
    if (dot(u, v) < 0) {
        return false;
    }
    if (cross(u, v) == 0) {
        return false;
    }
    if (d == a || d == b || d == c) {
        return false;
    }
    if (e == a || e == b || e == c) {
        return false;
    }
    if (on_seg(d, a, c) && on_seg(e, a, b)) {
        swap(d, e);
    }
    if (on_seg(d, a, b) && on_seg(e, a, c)) {
        ll x = dist2(b, d), y = dist2(d, a);
        if (x * (ll)16 < y || y * (ll)16 < x) {
            return false;
        }
        x = dist2(c, e), y = dist2(e, a);
        if (x * (ll)16 < y || y * (ll)16 < x) {
            return false;
        }
        return true;
    }
    return false;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int tt;
    scanf("%d", &tt);

    while (tt--) {
        pt a, b, c, d, e, f;
        scanf("%I64d%I64d%I64d%I64d", &a.x, &a.y, &b.x, &b.y);
        //cin >> a.x >> a.y >> b.x >> b.y;
        scanf("%I64d%I64d%I64d%I64d", &c.x, &c.y, &d.x, &d.y);
        //cin >> c.x >> c.y >> d.x >> d.y;
        scanf("%I64d%I64d%I64d%I64d", &e.x, &e.y, &f.x, &f.y);
        //cin >> e.x >> e.y >> f.x >> f.y;
        bool ok = false;
        //1 + 2
        if (a == c) {
            if (solve(a, b, d, e, f)) {
                ok = true;
                goto okay;
            }
        }
        if (a == d) {
            if (solve(a, b, c, e, f)) {
                ok = true;
                goto okay;
            }
        }
        if (b == c) {
            if (solve(b, a, d, e, f)) {
                ok = true;
                goto okay;
            }
        }
        if (b == d) {
            if (solve(b, a, c, e, f)) {
                ok = true;
                goto okay;
            }
        }
        //1 + 3
        if (a == e) {
            if (solve(a, b, f, c, d)) {
                ok = true;
                goto okay;
            }
        }
        if (a == f) {
            if (solve(a, b, e, c, d)) {
                ok = true;
                goto okay;
            }
        }
        if (b == e) {
            if (solve(b, a, f, c, d)) {
                ok = true;
                goto okay;
            }
        }
        if (b == f) {
            if (solve(b, a, e, c, d)) {
                ok = true;
                goto okay;
            }
        }
        //2 + 3
        if (c == e) {
            if (solve(c, d, f, a, b)) {
                ok = true;
                goto okay;
            }
        }
        if (c == f) {
            if (solve(c, d, e, a, b)) {
                ok = true;
                goto okay;
            }
        }
        if (d == e) {
            if (solve(d, c, f, a, b)) {
                ok = true;
                goto okay;
            }
        }
        if (d == f) {
            if (solve(d, c, e, a, b)) {
                ok = true;
                goto okay;
            }
        }
        okay:;
        printf(ok ? "YES\n" : "NO\n");
    }

}