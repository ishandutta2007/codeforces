#include <bits/stdc++.h>
using namespace std;
long double e = 1e-13;
const long double inf = 1e18;

int main() {
    int i, j, k, n;
    long double xl, yr, xr, yl, x, y, vx, vy, tl, tr;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    tl = 0, tr = 1e18;
    cin >> n;
    cin >> xl >> yl >> xr >> yr;
    if (xl > xr)
        swap(xl, xr);
    if (yl > yr)
        swap(yl, yr);
    for (i = 0; i < n; ++i) {
        cin >> x >> y >> vx >> vy;
        long double tl1 = 0, tr1 = inf;
        if (vx == 0 && !(xl < x && x < xr)) {
            cout << -1;
            return 0;
        }
        if ((vx > 0 && x > xr) || (x < 0 && x < xl)) {
            cout << -1;
            return 0;
        }
        if (vx > 0) {
            if (x < xl)
                tl1 = max(tl1, (xl - x) / vx);
            tr1 = min(tr1, (xr - x) / vx);
        } else if (vx != 0) {
            if (x > xr)
                tl1 = max(tl1, (xr - x) / vx);
            tr1 = min(tr1, (xl - x) / vx);
        }
        if (vy == 0 && !(yl < y && y < yr)) {
            cout << -1;
            return 0;
        }
        if ((vy > 0 && y > yr) || (y < 0 && y < yl)) {
            cout << -1;
            return 0;
        }
        if (vy > 0) {
            if (y < yl)
                tl1 = max(tl1, (yl - y) / vy);
            tr1 = min(tr1, (yr - y) / vy);
        } else if (vy != 0) {
            if (y > yr)
                tl1 = max(tl1, (yr - y) / vy);
            tr1 = min(tr1, (yl - y) / vy);
        }
        tl = max(tl, tl1);
        tr = min(tr, tr1);
    }
    if (tl + e < tr)
        cout << fixed << setprecision(12) << tl + e;
    else
        cout << -1;
}