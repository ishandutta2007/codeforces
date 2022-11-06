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

const int N = 100 * 1000 + 3;

int n;
vector<pt> g[N];
vector<int> order;
set<pt> bad;

inline bool read() {
    if (scanf("%d", &n) != 1) return false;
    forn(i, n - 1) {
        int a, b, dir;
        assert(scanf("%d%d%d", &a, &b, &dir) == 3);
        --a, --b;
        g[a].pb(mp(b, 1));
        g[b].pb(mp(a, 1 - dir));
        if (dir == 1) bad.insert(mp(b, a));
    }
    int m;
    assert(scanf("%d", &m) == 1);
    order.resize(m);
    forn(i, m) {
        assert(scanf("%d", &order[i]) == 1);
        order[i]--;
    }
	return true;
}

const int LOGN = 20;

int p[N][LOGN];
int Time;
int tin[N], tout[N];

void dfs (int v, int pr) {
    tin[v] = Time++;
    p[v][0] = pr;
    forl(i, LOGN - 1) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    forn(i, sz(g[v])) {
        int to = g[v][i].ft;
        if (to != pr) {
            dfs(to, v);
        }
    }
    tout[v] = Time++;
}

inline bool parent (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

inline int lca (int a, int b) {
    if (parent(a, b)) return a;
    if (parent(b, a)) return b;
    ford(i, LOGN) {
        if (!parent(p[a][i], b)) {
            a = p[a][i];
        }
    }
    assert(!parent(a, b) && parent(p[a][0], b));
    return p[a][0];
}

int cnt[2][N];

inline void prepare () {
    dfs(0, 0);
}

const int mod = 1000 * 1000 * 1000 + 7;
const int K = 1000 * 1000 + 13;

int ans;
int precnt[K];

inline int add(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

inline int calc(int cnt) {
    return precnt[cnt];
}

void go (int v, int pr) {
    forn(i, sz(g[v])) {
        int to = g[v][i].ft;
        if (to == pr) continue;
        go(to, v);
        forn(j, 2) cnt[j][v] += cnt[j][to];
    }
    if (bad.count(mp(v, pr))) {
        ans = add(ans, calc(cnt[0][v]));
    }
    if (bad.count(mp(pr, v))) {
        ans = add(ans, calc(cnt[1][v]));
    }
}

inline void solve() {
    int pw = 1;
    forl(i, K - 1) {
        precnt[i] = add(precnt[i - 1], pw);
        pw = add(pw, pw);
    }
    prepare();

    int curv = 0;
    forn(i, sz(order)) {
        int nextv = order[i];
        int vlca = lca(curv, nextv);
        //cerr << curv + 1 << ' ' << nextv + 1 << ' ' << vlca + 1 << endl;
        
        cnt[0][curv]++;
        cnt[0][vlca]--;

        cnt[1][nextv]++;
        cnt[1][vlca]--;
        curv = nextv;
    }
    go(0, 0);
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