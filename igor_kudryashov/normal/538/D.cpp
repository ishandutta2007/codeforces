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

const int N = 50 + 3;

int n;
char f[N][N];

inline bool read() {
    if (scanf("%d", &n) != 1) return false;
    forn(i, n) assert(scanf("%s", f[i]) == 1);
	return true;
}

char ans[2 * N][2 * N];
int used[N][N];

inline bool check (int dx, int dy) {
    forn(i, n) forn(j, n) if (f[i][j] == 'o') {
        if (correct(i + dx, j + dy, n, n) && f[i + dx][j + dy] == '.') return false;
    }
    forn(i, n) forn(j, n) if (f[i][j] == 'o') {
        if (correct(i + dx, j + dy, n, n)) used[i + dx][j + dy] = true;
    }
    return true;
}

inline void solve() {
    forn(i, 2 * n - 1) forn(j, 2 * n - 1) ans[i][j] = '.';
    forn(i, 2 * n - 1) forn(j, 2 * n - 1) {
        int dx = i - n + 1, dy = j - n + 1;
        if (check(dx, dy)) {
            ans[i][j] = 'x';
        }
    }
    ans[n - 1][n - 1] = 'o';
    forn(i, n) forn(j, n) if (f[i][j] == 'x' && !used[i][j]) {
        puts("NO");
        return;
    }
    puts("YES");
    forn(i, 2 * n - 1) printf("%s\n", ans[i]);
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