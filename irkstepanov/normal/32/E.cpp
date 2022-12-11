#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const ld eps = 1e-9;

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
    line(const pt& p, const pt& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
        ld tmp = sqrt(a * a + b * b);
        a /= tmp, b /= tmp, c /= tmp;
    }
};

vector<pt> intersect(const line& l, const line& m)
{
    ld a1 = l.a, b1 = l.b, c1 = -l.c;
    ld a2 = m.a, b2 = m.b, c2 = -m.c;
    ld det = a1 * b2 - a2 * b1;
    if (eq(det, 0)) {
        return {};
    }
    ld det1 = c1 * b2 - c2 * b1;
    ld det2 = a1 * c2 - a2 * c1;
    return {{det1 / det, det2 / det}};
}

bool on_seg(const pt& p, const pt& a, const pt& b)
{
    return eq(cross(a - p, b - p), 0) && leq(dot(a - p, b - p), 0);
}

vector<pt> intersect(const pt& a, const pt& b, const pt& c, const pt& d)
{
    line l(a, b), m(c, d);
    vector<pt> v = intersect(l, m);
    vector<pt> ans;
    for (pt& p : v) {
        if (on_seg(p, a, b) && on_seg(p, c, d)) {
            ans.pb(p);
        }
    }
    if (on_seg(a, c, d)) {
        ans.pb(a);
    }
    if (on_seg(b, c, d)) {
        ans.pb(b);
    }
    if (on_seg(c, a, b)) {
        ans.pb(c);
    }
    if (on_seg(d, a, b)) {
        ans.pb(d);
    }
    return ans;
}

int halfplane(const pt& p, const line& l)
{
    ld val = l.a * p.x + l.b * p.y + l.c;
    if (eq(val, 0)) {
        return 0;
    }
    if (gt(val, 0)) {
        return 1;
    }
    return -1;
}

pt ortho(const pt& p, const line& l)
{
    ld alpha = -(l.a * p.x + l.b * p.y + l.c);
    pt n = {l.a, l.b};
    return p + n * alpha;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    pt w1, w2;
    cin >> w1.x >> w1.y >> w2.x >> w2.y;

    pt m1, m2;
    cin >> m1.x >> m1.y >> m2.x >> m2.y;

    line l(m1, m2);

    if (intersect(a, b, w1, w2).empty()) {
        if (!intersect(a, b, m1, m2).empty()) {
            if (halfplane(a, l) != halfplane(b, l)) {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        return 0;
    }

    if (halfplane(a, l) != halfplane(b, l)) {
        cout << "NO\n";
        return 0;
    }

    if (halfplane(a, l) == 0) {
        cout << "NO\n";
        return 0;
    }

    pt h = ortho(b, l);
    pt c = b + (h - b) * 2;
    if (intersect(a, c, m1, m2).empty()) {
        cout << "NO\n";
        return 0;
    }
    pt p = intersect(a, c, m1, m2)[0];
    /*cout << fixed;
    cout.precision(12);
    cout << p.x << " " << p.y << "\n";*/

    if (intersect(a, p, w1, w2).empty() && intersect(p, b, w1, w2).empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}