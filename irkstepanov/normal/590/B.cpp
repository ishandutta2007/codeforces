#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long double ld;

const ld eps = 1e-10;
const ld inf = 1e18;
const int ops = 500;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool gt(ld a, ld b)
{
    return a - b > eps;
}

bool leq(ld a, ld b)
{
    return lt(a, b) || eq(a, b);
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
        return {k * x, k * y};
    }
};

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct circle
{
    pt center;
    ld r;
};

circle create(const pt& center, ld r, const pt& p, ld t)
{
    pt v = center - p;
    pt c = p + v * t;
    return {c, r * t};
}

bool intersect(const circle& a, const circle& b)
{
    ld d = dist(a.center, b.center);
    return leq(d, a.r + b.r);
}

bool inside(const pt& a, const circle& b)
{
    ld d = dist(a, b.center);
    return leq(d, b.r);
}

int main()
{

    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    
    ld vmax, t;
    cin >> vmax >> t;
    
    pt v, w;
    cin >> v.x >> v.y >> w.x >> w.y;
    pt tmp = a + v;
    
    circle c = create(tmp, vmax, a, t);
    if (inside(b, c)) {
        ld lf = 0, rg = t;
        for (int step = 0; step < ops; ++step) {
            ld md = (lf + rg) / 2;
            circle d = create(tmp, vmax, a, md);
            if (inside(b, d)) {
                rg = md;
            } else {
                lf = md;
            }
        }
        cout << fixed;
        cout.precision(12);
        cout << lf << "\n";
        return 0;
    }
    ld lf = 0, rg = inf;
    
    for (int step = 0; step < ops; ++step) {
        ld md = (lf + rg) /2;
        tmp = {b - w};
        circle d = create(tmp, vmax, b, md);
        if (intersect(c, d)) {
            rg = md;
        } else {
            lf = md;
        }
    }
    
    cout << fixed;
    cout.precision(12);
    cout << lf + t << "\n";

}