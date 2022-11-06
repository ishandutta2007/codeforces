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

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 200 * 1000 + 13;
const int LOGN = 20;
const int MAX = 2 * N * LOGN + 13;

struct node
{
    int val;
    node *lf, *rg;
    node() { val = 0, lf = rg = NULL; }
};

typedef node* tree;

int heappos;
node heap[MAX];

inline tree copy(tree t)
{
    assert(heappos < MAX);
    tree res = &heap[heappos++];
    if (t) res->val = t->val, res->lf = t->lf, res->rg = t->rg;
    return res;
}

inline int getVal(tree t) { return t ? t->val : 0; }

tree inc(tree root, int lf, int rg, int pos, int val)
{
    tree t = copy(root);
    
    if (lf == rg)
    {
        t->val += val;
        return t;
    }
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid) t->lf = inc(t->lf, lf, mid, pos, val);
    else t->rg = inc(t->rg, mid + 1, rg, pos, val);
    
    t->val = getVal(t->lf) + getVal(t->rg);
    
    return t;
}

int sum(tree t, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r) return t->val;
    
    int mid = (lf + rg) >> 1;
    int res = 0;
    if (l <= mid) res += sum(t->lf, lf, mid, l, min(mid, r));
    if (mid < r) res += sum(t->rg, mid + 1, rg, max(mid + 1, l), r);
    return res;
}

tree build (int lf, int rg)
{
    if (lf == rg) return &heap[heappos++];
    int mid = (lf + rg) >> 1;
    tree res = &heap[heappos++];
    res->lf = build(lf, mid);
    res->rg = build(mid + 1, rg);
    return res;
}

int n, rootv;
vector <int> g[N];
int fir[N], last[N];
int p[N][LOGN];
int tin[N], tout[N], T;
int szt;
tree t[N];
int dep[N];

inline bool parent (int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }

inline int lca (int a, int b)
{
    if (parent(a, b)) return a;
    if (parent(b, a)) return b;
    ford(i, LOGN)
        if (!parent(p[a][i], b))
            a = p[a][i];
    assert(!parent(a, b) && parent(p[a][0], b));
    return p[a][0];
}

inline int pred (int a, int b)
{
    assert(parent(b, a));
    ford(i, LOGN)
        if (!parent(p[a][i], b))
            a = p[a][i];
    assert(a != b && p[a][0] == b);
    return a;
}

inline int getSum (int a, int b, int ver)
{
    assert(parent(b, a));
    int lf = fir[b], rg = fir[a];
    assert(lf <= rg);
    return sum(t[ver], 0, szt - 1, lf, rg);
}

inline int getCnt (int a, int b, int start, int fin) // a - exclusive, b - inclusive
{
    assert(parent(b, a));
    if (a == b) return 0;
    
    int total = dep[a] - dep[b];
    int delta = getSum(p[a][0], b, fin) - getSum(p[a][0], b, start);
    
    assert(total >= delta);
    
    return total - delta;
}

int getAbove (int a, int b, int k, int start, int fin) // a - exclusive, b - inclusive
{
    assert(parent(b, a));
    assert(getCnt(a, b, start, fin) > k);
    
    ford(i, LOGN)
    {
        if (!parent(b, p[a][i])) continue;
        
        int curcnt = getCnt(a, p[a][i], start, fin);
        if (curcnt <= k) k -= curcnt, a = p[a][i];
    }
    
    assert(k == 0 && parent(b, p[a][0]) && getCnt(a, p[a][0], start, fin) == 1);
    return p[a][0];
}

inline int calc (int a, int b, int k, int start, int fin)
{
    int c = lca(a, b);
    
    if (c == a)
    {
        int cnt = getCnt(b, pred(b, a), start, fin);
        if (cnt <= k) return -1;
        return getAbove(b, pred(b, a), cnt - 1 - k, start, fin);
    }
    
    if (c == b)
    {
        int cnt = getCnt(a, pred(a, b), start, fin);
        if (cnt <= k) return -1;
        return getAbove(a, pred(a, b), k, start, fin);
    }
    
    int cnt1 = getCnt(a, c, start, fin);
    if (cnt1 > k) return getAbove(a, c, k, start, fin);
    
    k -= cnt1;
    
    int cnt2 = getCnt(b, pred(b, c), start, fin);
    if (cnt2 <= k) return -1;
    
    return getAbove(b, pred(b, c), cnt2 - 1 - k, start, fin);
}

void dfs (int v, int pr, int curdep = 0)
{
    dep[v] = curdep;
    tin[v] = T++;
    fir[v] = szt++;
    
    p[v][0] = pr;   
    forl(i, LOGN - 1) p[v][i] = p[p[v][i - 1]][i - 1];
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        dfs(to, v, curdep + 1);
    }
    
    tout[v] = T++;
    last[v] = szt++;
}

inline void prepare()
{
    dfs(rootv, rootv);
    t[0] = build(0, szt - 1);
}

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
    {
        int pr;
        assert(scanf("%d", &pr) == 1);
        --pr;
        if (pr >= 0) g[pr].pb(i); else rootv = i;
    }
    
    return true;
}

inline void solve()
{
    prepare();
    
    /*vector <int> trav(szt, -1);
    forn(i, n) trav[fir[i]] = trav[last[i]] = i;
    forn(i, sz(trav)) cerr << trav[i] << ' '; cerr << endl;*/
    
    int m;
    assert(scanf("%d", &m) == 1);
    
    forl(iter, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        
        t[iter] = t[iter - 1];
        
        //forn(i, szt) cerr << sum(t[iter], 0, szt - 1, i, i) << ' '; cerr << endl;
            
        if (type == 1)
        {
            int v;
            assert(scanf("%d", &v) == 1);
            --v;
            
            t[iter] = inc(t[iter], 0, szt - 1, fir[v], 1);
            t[iter] = inc(t[iter], 0, szt - 1, last[v], -1);
            
        } else if (type == 2)
        {
            int a, b, k, y;
            assert(scanf("%d%d%d%d", &a, &b, &k, &y) == 4);
            --a, --b, --k;
            int ans = calc(a, b, k, y, iter);
            if (ans != -1) ans++;
            printf("%d\n", ans);
        
        } else throw;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}