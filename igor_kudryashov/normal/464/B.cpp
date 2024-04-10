#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }
inline void clocks() {
    #ifdef SU2_PROJ
        cerr << "=== TIME: " << ld(clock()) / CLOCKS_PER_SEC << " sec ===" << endl;
    #endif
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
inline void makeVariablesUsed() { int a = INF; li b = INF64; ld c = EPS, d = PI; d = a * b + c; }

int a[8][3];

inline bool read()
{
    forn(i, 8) forn(j, 3) assert(scanf("%d", &a[i][j]) == 1);
    return true;
}

struct pt
{
    int x, y, z;
    pt (int x, int y, int z) : x(x), y(y), z(z) {}
    pt (int a[3]) : x(a[0]), y(a[1]), z(a[2]) {}
};

inline pt operator - (const pt& a, const pt& b) { return pt(a.x - b.x, a.y - b.y, a.z - b.z); }
inline pt operator + (const pt& a, const pt& b) { return pt(a.x + b.x, a.y + b.y, a.z + b.z); }
inline bool operator < (const pt& a, const pt& b)
{
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    if (a.z != b.z) return a.z < b.z;
    return false;
}

inline li det (int a, int b, int c, int d) { return a * 1LL * d - b * 1LL * c; }
inline li dist2 (const pt& a, const pt& b) { return sqr(li(a.x - b.x)) + sqr(li(a.y - b.y)) + sqr(li(a.z - b.z)); }
inline li dot (const pt& a, const pt& b) { return li(a.x) * b.x + li(a.y) * b.y + li(a.z) * b.z; }
inline pt cross (const pt& v1, const pt& v2)
{
    return pt(det(v1.y, v1.z, v2.y, v2.z), -det(v1.x, v1.z, v2.x, v2.z), det(v1.x, v1.y, v2.x, v2.y));
}

inline li Round (const ld& x)
{
    if (x < 0) return li(x - EPS);
    return li(x + EPS);
}

inline pt norm (const pt& v, const ld& len)
{
    ld l = sqrt(sqr(ld(v.x)) + sqr(ld(v.y)) + sqr(ld(v.z)));
    ld ax = v.x / l, ay = v.y / l, az = v.z / l;
    return pt(Round(ax * len), Round(ay * len), Round(az * len));
}

struct ptd
{
    ld x, y, z;
    ptd (const ld& x, const ld& y, const ld& z) : x(x), y(y), z(z) {}
};

inline ptd normal (const pt& v)
{
    ld l = sqrt(sqr(ld(v.x)) + sqr(ld(v.y)) + sqr(ld(v.z)));
    return ptd(v.x / l, v.y / l, v.z / l);
}

inline pt Round (const ptd& v, const ld& len) { return pt(Round(v.x * len), Round(v.y * len), Round(v.z * len)); }
inline ld det (const ld& a, const ld& b, const ld& c, const ld& d) { return a * d - b * c; }
inline ptd cross (const ptd& v1, const ptd& v2) { return ptd(det(v1.y, v1.z, v2.y, v2.z), -det(v1.x, v1.z, v2.x, v2.z), det(v1.x, v1.y, v2.x, v2.y)); }

inline bool check ()
{
    pt p0(a[0]);

    fore(i1, 1, 7) fore(i2, i1 + 1, 7)
    {
        pt p1(a[i1]);
        pt p2(a[i2]);
        if (dist2(p0, p1) == 0 || dist2(p0, p1) != dist2(p0, p2)) continue;
        pt v01 = p1 - p0, v02 = p2 - p0;
        if (dot(v01, v02) != 0) continue;

        set<pt> s;
        fore(i3, 1, 7) if (i3 != i1 && i3 != i2) s.insert(pt(a[i3]));

        ld mustlen = sqrt(ld(dist2(p0, p1)));
        pt cr = Round(cross(normal(v01), normal(v02)), mustlen);
        pt p3 = p0 + cr;
        if (!s.count(p3)) p3 = p0 - cr;
        if (!s.count(p3)) continue;

        pt p4 = p3 + v01, p5 = p2 + v01;
        if (!s.count(p4) || !s.count(p5)) continue;

        pt p6 = p3 + v02, p7 = p4 + v02;
        if (!s.count(p6) || !s.count(p7)) continue;

        return true;
    }

    return false;
}

void go (int idx)
{
    if (idx == 8)
    {
        if (check())
        {
            puts("YES");
            forn(i, 8) {
                forn(j, 3) printf("%d ", a[i][j]);
                puts("");
            }
            exit(0);
        }
        return;
    }

    sort(a[idx], a[idx] + 3);
    do
    {
        go(idx + 1);
    } while (next_permutation(a[idx], a[idx] + 3));
}

inline void solve()
{
    go(0);
    puts("NO");
}

int main()
{
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    //cerr << round(-1.9999999999999999) << endl;

    assert(read());
    solve();
    clocks();

    return 0;
}