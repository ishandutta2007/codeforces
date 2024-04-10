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
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
typedef long double ld;


#define y1 fuck
int sx, sy, tx, ty, x1, y1, x2, y2;
int vmax, tc;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return hypotl(x1-x2, y1-y2);
}

bool ok(ld t) {
    ld ms = vmax * t;
//     cout << "ms = " << ms << endl;
    if (t < tc) {
        return ms + 1e-10 >= dist(sx+x1*t, sy+y1*t, tx, ty);
    } else {
        return ms + 1e-10 >= dist(sx+x1*tc+x2*(t-tc), sy+y1*tc+y2*(t-tc), tx, ty);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> sx >> sy >> tx >> ty >> vmax >> tc >> x1 >> y1 >> x2 >> y2;
    ld l = 0, r = 1e8;
    forn(i, 1000) {
        ld m =  (r+l)/2;
        if (ok(m)) r = m;
        else l = m;
    }
    cout.precision(10);
    cout << fixed << (r+l)/2 << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}