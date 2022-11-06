#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

struct point {
    int x, y;

    point () {};

    point (int _x, int _y) : x(_x), y(_y) {};
};

ld dist(point a, point b) {
    return sqrtl(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

ld solve(point a, point b, point c) {
    ld A = dist(b, c), B = dist(a, c), C = dist(a, b);
    ld p = (A + B + C) / 2;
    ld sq = sqrtl(p * (p - A) * (p - B) * (p - C));
    ld rez = sq / A;
    return rez;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> a(n);
    forn(i, 0, n) {
        int _x, _y;
        cin >> _x >> _y;
        a[i] = point(_x, _y);
    }
    a.eb(a[0]);
    a.eb(a[1]);
    ld ans = 1e18;
    forn(i, 0, n)
        forn(j, 0, i)
            ans = min(ans, 0.5 * dist(a[i], a[j]));
    forn(i, 0, n) {
        ans = min(ans, solve(a[i], a[i + 1], a[i + 2]));
        ans = min(ans, solve(a[i + 1], a[i + 2], a[i]));
        ans = min(ans, solve(a[i + 2], a[i], a[i + 1]));
    }
    cout << fixed << setprecision(10) << ans << '\n';
}