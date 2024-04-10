#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
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

bool in(ld x, ld a, ld b) { return x >= a && x <= b; }

pair<ld, ld> mget(ld a, ld d, ld t) {
    // (a-t, a+t) * (d-t, d+t)
    ld x[4] = {(a-t) * (d-t), (a-t) * (d+t), (a+t) * (d-t), (a+t) * (d+t)};
    ld mn = *min_element(x, x+4);
    ld mx = *max_element(x, x+4);
    if (in(0, a-t, a+t) || in(0, d-t, d+t)) {
        mn = min(mn, (ld)0);
        mx = max(mx, (ld)0);
    }
    return mp(mn, mx);
}

ld a, b, c, d;

bool can(ld t) {
    auto p1 = mget(a, d, t);
    auto p2 = mget(b, c, t);
    return max(p1.fi, p2.fi) <= min(p1.se, p2.se);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> a >>b >> c >> d;
    ld l = 0, r = 1e10;
    forn(i, 200) {
        ld m = (l+r)/2;
        if (can(m)) r = m;
        else l = m;
    }

    cout.precision(20);
    cout << fixed << (l+r)/2 << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}