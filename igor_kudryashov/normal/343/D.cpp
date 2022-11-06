#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
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
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 500 * 1000 + 13;

int n;
vector <int> g[N];
int foc[N], loc[N];
int szt;
int cnt[N];
int pr[N];
vector <int> t;

int dfs (int v, int p)
{
    pr[v] = p;
    cnt[v] = 1;
    foc[v] = szt++;
    
    forn(i, sz(g[v]))
        if (g[v][i] != p)
            cnt[v] += dfs(g[v][i], v);
            
    loc[v] = szt++;
    return cnt[v];
}

inline bool heavy(int v, int to) { return cnt[to] > cnt[v] / 2; }

int idx[N];
vector< vector<int> > paths;

void dfs2(int v, int p)
{
    idx[v] = sz(paths);

    if (p != -1 && heavy(p, v))
        idx[v] = idx[p];
    else
        paths.pb(vector<int> ());

    paths[idx[v]].pb(v);

    forn(i, sz(g[v]))
        if (g[v][i] != p)
            dfs2(g[v][i], v);
}

int pos[N];
vector <int> ts[N];

inline void prepareHL()
{
    dfs(0, -1);
    dfs2(0, -1);
    
    forn(i, sz(paths))
    {
        forn(j, sz(paths[i]))
            pos[paths[i][j]] = j;
            
        ts[i] = vector <int> (4 * sz(paths[i]), -1);
    }
}

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    return true;
}

int q;
int type[N];

void upd (vector <int>& t, int idx, int lf, int rg, int pos, int val)
{
    if (lf == rg) return void(t[idx] = val);
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid) upd(t, 2 * idx + 1, lf, mid, pos, val);
    else upd(t, 2 * idx + 2, mid + 1, rg, pos, val);
    
    t[idx] = max(t[2 * idx + 1], t[2 * idx + 2]);
}

int max (const vector <int>& t, int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r) return t[idx];
    
    int mid = (lf + rg) >> 1;
    int res = -INF;
    
    if (l <= mid) res = max(res, max(t, 2 * idx + 1, lf, mid, l, min(r, mid)));
    if (r > mid) res = max(res, max(t, 2 * idx + 2, mid + 1, rg, max(l, mid + 1), r));
    
    return res;
}

int query (int v)
{
    int badVal = max(t, 0, 0, szt - 1, foc[v], loc[v]);
    int goodVal = -INF;
    
    while (true)
    {
        goodVal = max(goodVal, max(ts[idx[v]], 0, 0, sz(paths[idx[v]]) - 1, 0, pos[v]));
        v = pr[paths[idx[v]][0]];
        if (v == -1) break;
    }
    
    if (goodVal > badVal) return 1;
    return 0;
}

inline void solve()
{
    prepareHL();
    
    t = vector <int> (4 * szt, -1);
    
    /*forn(i, sz(paths))
    {
        forn(j, sz(paths[i])) cerr << paths[i][j] + 1 << ' ';
        cerr << endl;
    }
    cerr << endl;*/
    
    scanf("%d", &q);
    
    forn(iter, q)
    {
        int v;
        scanf("%d%d", &type[iter], &v);
        --v;
        
        //cerr << v + 1 << ' ' << idx[v] << ' ' << sz(paths[idx[v]]) << ' ' << pos[v] << ' ' << iter << endl;
        
        if (type[iter] == 1)
            upd(ts[idx[v]], 0, 0, sz(paths[idx[v]]) - 1, pos[v], iter);
        else if (type[iter] == 2)
            upd(t, 0, 0, szt - 1, foc[v], iter);
        else if (type[iter] == 3)
            printf("%d\n", query(v));
    }
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}