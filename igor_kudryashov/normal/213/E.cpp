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

inline int myRand () { return rand() ^ (rand() << 16); }

struct node
{
    int x;
    li h;
    int cnt, prior;
    node *lf, *rg;
    
    node (int x) : x(x) { h = x, cnt = 1, prior = myRand(), lf = rg = NULL; }
};

typedef node* tree;

const int N = 200 * 1000 + 13;

li deg[N];

inline int cnt (const tree& t) { return t ? t->cnt : 0; }
inline li hash (const tree& t) { return t ? t->h : 0; }

inline void lift (tree& t)
{
    if (!t) return;
    
    t->cnt = cnt(t->lf) + 1 + cnt(t->rg);
    t->h = hash(t->lf) + t->x * deg[cnt(t->lf)] + hash(t->rg) * deg[cnt(t->lf) + 1];
}

void split (tree t, int Cnt, tree& t1, tree& t2)
{
    if (!t) return void(t1 = t2 = NULL);
    
    lift(t);
    
    if (cnt(t->lf) >= Cnt)
    {
        t2 = t;
        split(t2->lf, Cnt, t1, t2->lf);
    } else
    {
        t1 = t;
        split(t1->rg, Cnt - cnt(t->lf) - 1, t1->rg, t2);
    }
    
    lift(t1);
    lift(t2);
}

tree merge (tree t1, tree t2)
{
    if (!t1) return t2;
    if (!t2) return t1;
    
    if (t1->prior > t2->prior)
    {
        t1->rg = merge(t1->rg, t2);
        lift(t1);
        return t1;
    }
    
    t2->lf = merge(t1, t2->lf);
    lift(t2);
    return t2;
}

inline void insert (int val, int pos, tree& root)
{
    tree t1, t2;
    split(root, pos, t1, t2);
    tree t3 = new node(val);
    root = merge(t1, merge(t3, t2));
}

inline void erase (int val, int pos, tree& root)
{
    tree t1, t2;
    split(root, pos, t1, t2);

    tree t3, t4;
    split(t2, 1, t3, t4);
    
    assert(cnt(t3) == 1 && t3->x == val);
    root = merge(t1, t4);
}

int sza, n;
int posb[N], b[N];
li HA;
int t[N];
tree root;

inline void inc (int i, int val)
{
    for (; i < n; i = (i | (i + 1)))
        t[i] += val;
}

inline int sum (int i)
{
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        ans += t[i];
    return ans;
}

inline bool read()
{
    assert(scanf("%d", &sza) == 1);
    assert(scanf("%d", &n) == 1);
    
    forn(i, sza)
    {
        int tmp;
        assert(scanf("%d", &tmp) == 1);
        --tmp;
        HA += deg[i] * tmp;
    }
    
    forn(i, n)
    {
        int tmp;
        assert(scanf("%d", &tmp) == 1);
        --tmp;
        posb[tmp] = i;
        b[i] = tmp;
    }
    
    return true;
}

inline void solve()
{
    li add = 0;
    forn(i, sza) add += deg[i];
    
    int ans = 0;
    int curpos = 0;

    forn(i, n)
        if (b[i] < sza)
        {
            insert(b[i], curpos++, root);
            inc(i, 1);
        }
        
    if (root->h == HA) ans++;
    
    fore(i, sza, n - 1)
    {
        inc(posb[i - sza], -1);
        int idx = sum(posb[i - sza]);
        erase(i - sza, idx, root);
        
        idx = sum(posb[i]);
        insert(i, idx, root);
        inc(posb[i], 1);
        
        HA += add;
        if (root->h == HA) ans++;
    }
    
    cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    deg[0] = 1;
    forl(i, N - 1) deg[i] = deg[i - 1] * 1009LL;
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}