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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pt(n);
    vector<pair<int, int>> xs(n), ys(n);
    forn(i, 0, n) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xs[i] = {x1 + x2, i};
        ys[i] = {y1 + y2, i};
    }
    sort(all(xs));
    sort(all(ys));
    ll ans = LINF;
    fore(xb, 0, k) fore(xe, 0, k) fore(yb, 0, k) fore(ye, 0, k) {
        set<int> rem;
        forn(i, 0, xb) rem.insert(xs[i].sn);
        forn(i, 0, xe) rem.insert(xs[n - 1 - i].sn);
        forn(i, 0, yb) rem.insert(ys[i].sn);
        forn(i, 0, ye) rem.insert(ys[n - 1 - i].sn);
        if (rem.size() > k) continue;
        ll minx, maxx, miny, maxy;
        int i;
        for (i = 0; rem.find(xs[i].sn) != rem.end(); ++i);
        minx = xs[i].fs;
        for (i = n - 1; rem.find(xs[i].sn) != rem.end(); --i);
        maxx = xs[i].fs;
        for (i = 0; rem.find(ys[i].sn) != rem.end(); ++i);
        miny = ys[i].fs;
        for (i = n - 1; rem.find(ys[i].sn) != rem.end(); --i);
        maxy = ys[i].fs;
        //cerr << minx << ' ' << maxx << ' ' << miny << ' ' << maxy << '\n';
        ll xl = (maxx - minx + 1) / 2, yl = (maxy - miny + 1) / 2;
        if (xl == 0) ++xl;
        if (yl == 0) ++yl;
        ans = min(ans, xl * yl);
    }
    cout << ans << '\n';
}