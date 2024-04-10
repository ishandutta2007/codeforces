#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef long long i64;
typedef pair<i64, i64> pii;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 100500;

int n, k;
pii p[maxn];

vector<pii> good;
vector<i64> needx, needy;

i64 getMinX(vector<i64>& where, int factor) {
    sort(p, p+n);
    forn(i, min(n, 11)) where.pb(p[i].fi * factor);
    return p[min(n-1, 10)].fi;
}

pii read() {
    int _x1, _y1, _x2, _y2;
    scanf("%d%d%d%d", &_x1, &_y1, &_x2, &_y2);
    i64 x1 = _x1 * 2;
    i64 y1 = _y1 * 2;
    i64 x2 = _x2 * 2;
    i64 y2 = _y2 * 2;

    return {(x1+x2)/2, (y1+y2)/2};
}

int num_out(i64 x1, i64 y1, i64 x2, i64 y2) {
//     cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    if (x1 > x2 || y1 > y2) return 1000000;
    int cnt = 0;
    for (const auto& p: good) {
        if (p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) {
            ++cnt;
        }
    }
    return cnt;
}

void solve() {
    scanf("%d%d", &n, &k);
    forn(i, n) p[i] = read();

    i64 mnx = getMinX(needx, 1);
    forn(i, n) p[i].fi *= -1; reverse(p, p+n);
    i64 mxx = -getMinX(needx, -1);
    forn(i, n) p[i].fi *= -1;

    forn(i, n) swap(p[i].fi, p[i].se);

    i64 mny = getMinX(needy, 1);
    forn(i, n) p[i].fi *= -1; reverse(p, p+n);
    i64 mxy = -getMinX(needy, -1);
    forn(i, n) p[i].fi *= -1;

//     cerr << mnx << ' ' << mny << ' ' << mxx << ' ' << mxy << endl;

    forn(i, n) swap(p[i].fi, p[i].se);

    forn(i, n) {
        if (p[i].fi < mnx || p[i].fi > mxx || p[i].se < mny || p[i].se > mxy)
            good.pb(p[i]);
    }
//     for (auto pt: good)
//         cerr << pt.fi << ' ' << pt.se << '\n';
//     cerr << endl;

    sort(all(needx));
    needx.erase(unique(all(needx)), needx.end());
    sort(all(needy));
    needy.erase(unique(all(needy)), needy.end());

//     cout << needx.size() << " " << needy.size() << endl;
//     cout << "x: "; for (auto x: needx) cout << x << " "; cout << endl;
//     cout << "y: "; for (auto y: needy) cout << y << " "; cout << endl;

//     cout << good.size() << endl;
//     for (auto g: good) cout << g.fi << " " << g.se << endl;
//     cout << endl;

    i64 best = 2e18;
    forn(X2, needx.size()) forn(X1, X2+1) forn(Y2, needy.size()) forn(Y1, Y2+1) {
        i64 x1 = needx[X1];
        i64 x2 = needx[X2];
        i64 y1 = needy[Y1];
        i64 y2 = needy[Y2];
        if (x1 <= mnx && x2 >= mxx && y1 <= mny && y2 >= mxy) {
            if (num_out(x1, y1, x2, y2) <= k) {
//                 cout << x1 << " " << x2 << endl;
                i64 dx = (x2-x1+1)/2;
                i64 dy = (y2-y1+1)/2;
                if (dx == 0) ++dx;
                if (dy == 0) ++dy;
                best = min(best, dx*dy);
            }
        }
    }
    assert(best < 1.9e18);
    cout << best << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}