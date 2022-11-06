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
    li sum, vsum;
    int cnt;
    int prior;
    node *lf, *rg;
    
    node (int x) : x(x) { sum = x, vsum = 0, cnt = 1, prior = myRand(), lf = rg = NULL; }
};

typedef node* tree;

inline int cnt (const tree& t) { return t ? t->cnt : 0; }
inline li sum (const tree& t) { return t ? t->sum : 0; }
inline li vsum (const tree& t) { return t ? t->vsum : 0; }

inline void lift (tree& t)
{
    if (!t) return;
    
    t->cnt = cnt(t->lf) + 1 + cnt(t->rg);
    t->sum = sum(t->lf) + t->x + sum(t->rg);
    t->vsum = vsum(t->lf) + t->x * 1LL * cnt(t->lf) + (vsum(t->rg) + sum(t->rg) * (cnt(t->lf) + 1));
}

void split (tree t, int x, tree& t1, tree& t2)
{
    if (!t) return void(t1 = t2 = NULL);
    
    lift(t);
    
    if (t->x < x)
    {
        t1 = t;
        split(t1->rg, x, t1->rg, t2);
        
    } else
    {
        t2 = t;
        split(t2->lf, x, t1, t2->lf);
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

inline void insert (int x, tree& root)
{
    tree t1, t2;
    split(root, x, t1, t2);
    tree t3 = new node(x);
    root = merge(t1, merge(t3, t2));
}

inline void erase (int x, tree& root)
{
    tree t1, t2;
    split(root, x, t1, t2);
    tree t3, t4;
    split(t2, x + 1, t3, t4);
    assert(t3->cnt == 1 && t3->x == x);
    root = merge(t1, t4);
}

const int N = 100 * 1000 + 13;

int n;
int x[N];
tree root;

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
    {
        assert(scanf("%d", &x[i]) == 1);
        insert(x[i], root);
    }
    
    return true;
}

inline li calc (int lf, int rg)
{
    tree t1, t2;
    split(root, lf, t1, t2);
    
    tree t3, t4;
    split(t2, rg + 1, t3, t4);
    
    // all data in t3, need merge t1, t3, t4
    
    li ans = vsum(t3) * 2 - sum(t3) * (cnt(t3) - 1);
    root = merge(t1, merge(t3, t4));
    
    return ans; 
}

inline void solve()
{
    int m;
    assert(scanf("%d", &m) == 1);
    
    forn(iter, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        
        if (type == 1)
        {
            int idx, dx;
            assert(scanf("%d%d", &idx, &dx) == 2);
            --idx;
            
            erase(x[idx], root);
            x[idx] += dx;
            insert(x[idx], root);
            
        } else
        {
            int lf, rg;
            assert(scanf("%d%d", &lf, &rg) == 2);
            printf("%I64d\n", calc(lf, rg));
        }
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