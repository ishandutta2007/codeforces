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

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 5000 + 3;

int n, start;
int lf[N], rg[N];
vector<int> pos;

inline bool read() {
    if (scanf("%d%d", &n, &start) != 2) return false;
    lf[0] = rg[0] = start;
    forl(i, n) {
        assert(scanf("%d%d", &lf[i], &rg[i]) == 2);
        pos.pb(lf[i]);
        pos.pb(rg[i]);
    }
    n++;
    pos.pb(start);
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
	return true;
}

inline int dist (int ptIdx, int segIdx) {
    if (lf[segIdx] <= pos[ptIdx] && pos[ptIdx] <= rg[segIdx]) return 0;
    return min(abs(lf[segIdx] - pos[ptIdx]), abs(rg[segIdx] - pos[ptIdx]));
}

li d[2][2 * N];

inline void solve() {
    forn(i, 2) forn(j, sz(pos)) d[i][j] = INF64;
    forn(j, sz(pos)) if (pos[j] == start) d[0][j] = 0;

    forn(idx, n - 1) {
        const int iter = idx & 1;
        forl(j, sz(pos) - 1) d[iter][j] = min(d[iter][j], d[iter][j - 1] + pos[j] - pos[j - 1]);
        for (int j = sz(pos) - 2; j >= 0; j--) d[iter][j] = min(d[iter][j], d[iter][j + 1] + pos[j + 1] - pos[j]);
        forn(j, sz(pos)) {
            d[iter ^ 1][j] = min(d[iter ^ 1][j], d[iter][j] + dist(j, idx + 1));
            d[iter][j] = INF64;
        }
    }
    li ans = INF64;
    forn(i, sz(pos)) ans = min(ans, d[(n - 1) & 1][i]);
    cout << ans << endl;
}

int main() {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

    assert(read());
    solve();
	
#ifdef SU2_PROJ
	cerr << "=== TOTAL TIME: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif

	return 0;
}