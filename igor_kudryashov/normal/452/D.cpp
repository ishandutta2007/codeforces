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

int k, n[3], t[3];
priority_queue <int> q[3];

inline bool read()
{
    if (scanf("%d", &k) != 1) return false;
    forn(i, 3) assert(scanf("%d", &n[i]) == 1);
    forn(i, 3) assert(scanf("%d", &t[i]) == 1);
    return true;
}

inline void solve()
{
    forn(i, 3) forn(j, n[i]) q[i].push(0);

    int ans = 0;

    forn(iter, k)
    {
        int cur[3];
        forn(i, 3)
        {
            cur[i] = q[i].top();
            q[i].pop();
            //if (!q[i].empty()) assert(cur[i] >= q[i].top());
            cur[i] = abs(cur[i]);
        }

        int start = cur[0];
        start = max(start, cur[1] - t[0]);
        start = max(start, cur[2] - t[0] - t[1]);

        q[0].push(-(start + t[0]));
        q[1].push(-(start + t[0] + t[1]));
        q[2].push(-(start + t[0] + t[1] + t[2]));

        ans = max(ans, start + t[0] + t[1] + t[2]);
    }

    cout << ans << endl;
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