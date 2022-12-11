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
typedef pair<int, ll> data;

const ld eps = 1e-9;

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool gt(ld a, ld b)
{
    return a - b > eps;
}

struct pt
{
    ld x, y;
    pt() : x(0), y(y) {}
    pt(ld x, ld y) : x(x), y(y) {}
    pt operator-(const pt& other) const
    {
        return {x - other.x, y - other.y};
    }
    pt operator+(const pt& other) const
    {
        return {x + other.x, y + other.y};
    }
};

ld cross(const pt& p, const pt& q)
{
    return p.x * q.y - p.y * q.x;
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

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    ld w, v, u;
    cin >> n >> w >> v >> u;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    bool ok_pos = true, ok_neg = true;
    for (int i = 0; i < n; ++i) {
        if (gt(p[i].y, p[i].x * u / v)) {
            ok_neg = false;
        }
        if (lt(p[i].y, p[i].x * u / v)) {
            ok_pos = false;
        }
    }

    cout << fixed;
    cout.precision(12);

    if (ok_pos || ok_neg) {
        cout << w / u << "\n";
        return 0;
    }

    ld t = 0;
    line l(0, 1, 0);
    pt magic = {v, u};

    for (int i = 0; i < n; ++i) {
        line m(p[i], p[i] + magic);
        pt r = intersect(l, m);
        ld val = r.x / v;
        if (gt(val, t)) {
            t = val;
        }
    }

    t += w / u;
    cout << t << "\n";

}