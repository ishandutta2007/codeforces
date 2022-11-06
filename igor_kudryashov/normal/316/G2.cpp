#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 1005 * 1000 + 13;

#define V first
#define L second

struct node
{
    int lf, rg, p, link;
    map <char, int> next;
    
    node (int lf = 0, int rg = 0, int p = -1, int link = -1) : lf(lf), rg(rg), p(p), link(link) {}
    
    int& operator [] (char c)
    {
        if (!next.count(c))
            next[c] = -1;
            
        return next[c];
    }
};

int n;
char s[N];
node t[N];
int szt;

inline int leng (int v)
{
    return t[v].rg - t[v].lf;
}

int addVertex (int p, int lf, int rg)
{
    t[szt] = node(lf, rg, p, -1);
    t[p][s[lf]] = szt;
    return szt++;
}

int split (pt ptr)
{
    int v = ptr.V, up = ptr.L, down = leng(v) - up;
    
    if (up == 0)
        return v;
        
    if (down == 0)
        return t[v].p;
        
    int mid = addVertex(t[v].p, t[v].lf, t[v].lf + down);
    t[v].lf += down, t[v].p = mid;
    t[mid][s[t[v].lf]] = v;
    
    return mid;
}

pt down (int v, int lf, int rg)
{
    if (lf == rg)
        return mp(v, 0);
        
    while (true)
    {
        v = t[v][s[lf]];

        if (leng(v) >= rg - lf)
            return mp(v, leng(v) - (rg - lf));
            
        lf += leng(v);
    }
    
    throw;
}

int link (int v)
{
    if (t[v].link == -1)
        return split(down(link(t[v].p), t[v].lf + (t[v].p == 0), t[v].rg));
        
    return t[v].link;
}

pt go (pt ptr, char c)
{
    int v = ptr.V, up = ptr.L;
    
    if (up != 0)
        return s[t[v].rg - up] == c ? mp(v, up - 1) : mp(-1, -1);
        
    v = t[v][c];
    
    return v == -1 ? mp(-1, -1) : mp(v, leng(v) - 1);
}

pt addChar (pt ptr, int pos)
{
    while (true)
    {
        pt nptr = go(ptr, s[pos]);
        if (nptr.V != -1)
            return nptr;
            
        int v = split(ptr);
        addVertex(v, pos, n);
        
        if (v == 0)
            return mp(0, 0);
            
        ptr = mp(link(v), 0);
    }
    
    throw;
}

void makeTree ()
{
    szt = 0;
    t[szt++] = node(0, 0, -1, 0);
    
    pt ptr = mp(0, 0);
    
    forn(i, n)
        ptr = addChar(ptr, i);
}

char buf[N];
int cnt;
pt bord[13];
pt occ[13];

inline bool read ()
{
    assert(scanf("%s", s) == 1);
    n = strlen(s);
    s[n++] = '0';
    
    assert(scanf("%d", &cnt) == 1);
    
    forn(i, cnt)
    {
        assert(scanf("%s", buf) == 1);
        assert(scanf("%d%d", &occ[i].ft, &occ[i].sc) == 2);
        
        bord[i].ft = n;
        
        int len = strlen(buf);
        
        forn(j, len) s[n++] = buf[j];
        s[n++] = char('1' + i);
        
        bord[i].sc = n - 2;
    }
    
    return true;
}

int pos[N];
int minpos[N];
int nextdig[N];
int cntleafs[N];

inline string getString (int v)
{
    string curs = "";
    while (v != 0)
    {
        string now = "";
        for (int j = t[v].lf; j < t[v].rg; j++) now.pb(s[j]);
        curs = now + curs;
        v = t[v].p;
    }
    return curs;
}

int dfs1 (int v, int dep)
{
    if (t[v].next.empty())
    {
        cntleafs[v] = 1;
        minpos[v] = pos[v] = n - dep;
        return minpos[v];
    }
    
    minpos[v] = INF;
    
    for (map <char, int> :: iterator it = t[v].next.begin(); it != t[v].next.end(); it++)
    {
        int t = dfs1(it->sc, dep + leng(it->sc));
        cntleafs[v] += cntleafs[it->sc];
        minpos[v] = min(minpos[v], t);
    }
    
    return minpos[v];
}

inline int myRand () { return rand() ^ (rand() << 16); }

struct dnode
{
    int val;
    int cnt, prior;
    dnode *lf, *rg;
    
    dnode (int val) : val(val) { cnt = 1, prior = myRand(), lf = rg = NULL; }
};

typedef dnode* tree;

inline int dcnt (const tree& t) { return t ? t->cnt : 0; }

inline void lift (tree& t)
{
    if (!t) return;
    t->cnt = dcnt(t->lf) + 1 + dcnt(t->rg);
}

void split (tree t, int val, tree& t1, tree& t2)
{
    if (!t) return void(t1 = t2 = NULL);
    
    lift(t);
    
    if (t->val < val)
    {
        t1 = t;
        split(t1->rg, val, t1->rg, t2);
    } else
    {
        t2 = t;
        split(t2->lf, val, t1, t2->lf);
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

void insert (tree& root, tree t)
{
    tree t1, t2;
    split(root, t->val, t1, t2);
    root = merge(t1, merge(t, t2));
}

void goInsert (tree root, tree& t)
{
    if (!root) return;
    
    goInsert(root->lf, t);
    goInsert(root->rg, t);
    root->lf = root->rg = NULL;
    root->cnt = 1;
    insert(t, root);
}

tree tt[N];

li ans;

inline bool checkOcc (tree t)
{
    forn(i, cnt)
    {
        tree t1, t2;
        split(t, bord[i].ft, t1, t2);
        tree t3, t4;
        split(t2, bord[i].sc + 1, t3, t4);
        
        int cntocc = dcnt(t3);
        
        t = merge(t1, merge(t3, t4));
        
        if (cntocc < occ[i].ft || cntocc > occ[i].sc) return false;
    }
    return true;
}

void print (tree t)
{
    if (!t) return;
    print(t->lf);
    cerr << t->val << ' ';
    print(t->rg);
}

tree dfs2 (int v)
{
    if (t[v].next.empty()) tt[v] = new dnode(pos[v]);
    
    int bestto = -1;
    
    for (map <char, int> :: iterator it = t[v].next.begin(); it != t[v].next.end(); it++)
        if (bestto == -1 || cntleafs[it->sc] > cntleafs[bestto])
            bestto = it->sc;
            
    if (bestto != -1)
        tt[v] = dfs2(bestto);
        
    for (map <char, int> :: iterator it = t[v].next.begin(); it != t[v].next.end(); it++)
        if (it->sc != bestto)
        {
            tree tmp = dfs2(it->sc);
            goInsert(tmp, tt[v]);
        }
        
    if (minpos[v] < nextdig[0] && checkOcc(tt[v]))
    {
        int lf = t[v].lf, rg = min(t[v].rg, nextdig[lf]);
        ans += rg - lf;
    }
    
    return tt[v];
}

inline void solve ()
{
    for (int i = n - 1; i >= 0; i--)
        if (isdigit(s[i]))
            nextdig[i] = i;
        else
            nextdig[i] = nextdig[i + 1];
            
    makeTree();
    
    //cerr << s << endl;
    
    memset(pos, -1, sizeof(pos));
    
    dfs1(0, 0);
    
    dfs2(0);
    
    /*forn(i, szt)
    {
        string curs = "";
        int v = i;
        while (v != 0)
        {
            string now = "";
            for (int j = t[v].lf; j < t[v].rg; j++) now.pb(s[j]);
            curs = now + curs;
            v = t[v].p;
        }
        
        cerr << curs << ' ' << minpos[i] << endl;
    }*/
    
    cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    assert(read());
    solve();

    return 0;
}