#pragma comment (linker, "/stack:16000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <stack>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define X first
#define Y second
#define ft first
#define sc second

template <typename X> inline X abs (const X& a) { return a < 0 ? -a : a; }
template <typename X> inline X sqr (const X& a) { return a * a; }

typedef long long li;
typedef pair <int, int> pt;
typedef long double ld;
typedef pair <ld, ld> ptd;
const int INF = int (1e9);
const int NMAX = int (1e4);
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

struct targ
{
    int x, y, t;
    ld p;

    targ (int x, int y, int t, ld p) : x(x), y(y), t(t), p(p) {}
};

int n;
vector <targ> v;

inline bool cmp (const targ &a, const targ &b)
{
    if (a.t != b.t)
        return a.t < b.t;

    if (a.x != b.x)
        return a.x < b.x;

    if (a.y != b.y)
        return a.y < b.y;

    return a.p < b.p;
}

const int N = 1000 + 13;

ld d[N];

inline li dist2 (int ax, int ay, int bx, int by)
{
    return (ax - bx) * 1LL * (ax - bx) + (ay - by) * 1LL * (ay - by);
}

inline bool reach (int x, int y, int t, int fx, int fy, int ft)
{
    assert(ft >= t);

    li d = dist2(x, y, fx, fy);

    return d <= (ft - t) * 1LL * (ft - t);
}

int main()
{ 

    cin >> n;

    forn(i, n)
    {
        int tx, ty, tt;
        ld p;

        scanf("%d%d%d", &tx, &ty, &tt);
        cin >> p;

        v.pb(targ(tx, ty, tt, p));
    }

    sort(all(v), cmp);

    ld ans = 0.0;

    forn(i, n)
    {
        ld maxv = 0.0;

        forn(j, i)
            if (reach(v[j].x, v[j].y, v[j].t, v[i].x, v[i].y, v[i].t))
                maxv = max(maxv, d[j]);

        d[i] = maxv + v[i].p;
        ans = max(ans, d[i]);
    }

    cout << setprecision(10) << fixed;

    cout << ans << endl;

    return 0;
}