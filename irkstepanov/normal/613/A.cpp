#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll inf = (ll)(1e18);
const ld pi = 4 * atan(1.0);
const ld eps = 0.00000001;

struct pt
{
    ld x, y;
};

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool lt(ld a, ld b)
{
    return b - a > eps;
}

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld solve(const pt& p, const pt& a, const pt& b)
{
    ld A = a.y - b.y;
    ld B = b.x - a.x;
    ld C = a.x * b.y - a.y * b.x;
    ld d = (A * p.x + B * p.y + C) / (A * A + B * B);
    pt r = p;
    r.x -= d * A;
    r.y -= d * B;
    if (eq(dist(r, a) + dist(r, b), dist(a, b))) {
        //cout << r.x << " " << r.y << "\n";
        //cout << "!" << abs(d) * sqrt(A * A + B * B) << "\n";
        return abs(d) * sqrt(A * A + B * B);
    } else {
        d = dist(p, a);
        if (lt(dist(p, b), d)) {
            d = dist(p, b);
        }
        return d;
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //freopen("mine.txt", "w", stdout);

    int n;
    pt p;
    cin >> n >> p.x >> p.y;

    ld rmax = -1;
    vector<pt> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
        if (lt(rmax, dist(p, v[i]))) {
            rmax = dist(p, v[i]);
        }
    }

    ld rmin = inf;
    for (int i = 0; i < n; ++i) {
        ld d = solve(p, v[i], v[(i + 1) % n]);
        if (lt(d, rmin)) {
            rmin = d;
        }
    }
    //cout << rmin << " " << rmax << "\n";

    ld ans = pi * (rmax * rmax - rmin * rmin);
    cout << fixed;
    cout.precision(10);
    cout << (double)ans << "\n";

}