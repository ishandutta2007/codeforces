#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long double ld;

const ld inf = 1e18;
const ld eps = 1e-8;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

struct pt
{
    ld x, y;
};

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{

    pt a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    int n;
    cin >> n;
    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    if (n == 1) {
        ld ans = inf;
        ld r = dist(a, p[0]) + dist(c, p[0]);
        if (lt(r, ans)) {
            ans = r;
        }
        r = dist(b, p[0]) + dist(c, p[0]);
        if (lt(r, ans)) {
            ans = r;
        }
        cout << fixed;
        cout.precision(12);
        cout << ans << "\n";
        return 0;
    }

    ld sum = 0;
    vector<ld> v(n);
    for (int i = 0; i < n; ++i) {
        sum += 2 * dist(c, p[i]);
    }
    for (int i = 0; i < n; ++i) {
        v[i] = sum - 2 * dist(c, p[i]) + dist(b, p[i]) + dist(c, p[i]);
    }

    ld best = inf;
    int bestx = -1;
    for (int i = 0; i < n; ++i) {
        if (lt(v[i], best)) {
            best = v[i];
            bestx = i;
        }
    }
    ld ans = best;
    //cout << best << " " << bestx << "\n";
    best = inf;
    int besty = -1;
    for (int i = 0; i < n; ++i) {
        if (lt(v[i], best) && i != bestx) {
            best = v[i];
            besty = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        ld curr = dist(a, p[i]) + dist(c, p[i]);
        ld r1 = inf;
        if (bestx != -1 && bestx != i) {
            r1 = curr + v[bestx] - 2 * dist(c, p[i]);
        }
        ld r2 = inf;
        if (besty != -1 && besty != i) {
            r2 = curr + v[besty] - 2 * dist(c, p[i]);
        }
        ld r3 = curr + (sum - 2 * dist(c, p[i]));
        if (lt(r1, ans)) {
            ans = r1;
        }
        if (lt(r2, ans)) {
            ans = r2;
        }
        if (lt(r3, ans)) {
            ans = r3;
        }
    }

    cout << fixed;
    cout.precision(12);
    cout << ans << "\n";

}