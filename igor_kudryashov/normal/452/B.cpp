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
typedef pair<int, int> pt;

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

int n, m;
vector <pt> p;

inline bool read()
{
    return cin >> n >> m;
}

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int idxs[4];
ld ans;
vector <int> used;
int anss[4];

inline ld dist (const pt& a, const pt& b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }

void go (int idx)
{
    if (idx == 4)
    {
        ld cur = 0;
        forn(i, 3) cur += dist(p[idxs[i]], p[idxs[i + 1]]);
        if (ans + EPS < cur)
        {
            ans = cur;
            forn(i, 4) anss[i] = idxs[i];
        }
        return;
    }

    forn(i, sz(p))
    {
        if (used[i]) continue;

        idxs[idx] = i;
        used[i] = true;

        go(idx + 1);

        used[i] = false;
    }
}

inline void solve()
{
    vector <pt> vv;
    vv.pb(mp(0, 0));
    vv.pb(mp(0, m));
    vv.pb(mp(n, 0));
    vv.pb(mp(n, m));

    forn(i, sz(vv))
    {
        p.pb(vv[i]);

        forn(k, 8)
        {
            int tx = vv[i].x + dx[k], ty = vv[i].y + dy[k];
            if (!correct(tx, ty, n + 1, m + 1)) continue;
            p.pb(mp(tx, ty));
        }
    }

    sort(all(p));
    p.erase(unique(all(p)), p.end());

    forn(i, sz(p)) used.pb(0);

    go(0);

    forn(i, 4) printf("%d %d\n", p[anss[i]].x, p[anss[i]].y);
}

int main()
{
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();
    clocks();

    return 0;
}