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

struct node
{
    int lf, rg, p, link;
    int next[27];
    
    node (int lf = 0, int rg = 0, int p = -1, int link = -1) : lf(lf), rg(rg), p(p), link(link) { memset(next, -1, sizeof(next)); }
};

#define V first
#define L second

const int N = 2000 * 1000 + 13;

int n;
char s[N];
node t[N];
int szt;
char buf[N];
int cnt[N];

void dfs (int v)
{
    bool leaf = true;
    
    forn(i, 27)
    {
        int to = t[v].next[i];
        if (to != -1)
        {
            dfs(to);
            cnt[v] += cnt[to];
            leaf = false;
        }
    }
    
    if (leaf) cnt[v] = 1;
}

inline int leng (int v)
{
    return t[v].rg - t[v].lf;
}

int addVertex (int p, int lf, int rg)
{
    t[szt] = node(lf, rg, p, -1);
    t[p].next[s[lf] - 'a'] = szt;
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
    t[mid].next[s[t[v].lf] - 'a'] = v;
    
    return mid;
}

pt go (pt ptr, char c)
{
    int v = ptr.V, up = ptr.L;
    
    if (up != 0)
        return s[t[v].rg - up] == c ? mp(v, up - 1) : mp(-1, -1);
    
    v = t[v].next[c - 'a'];
    
    return v == -1 ? mp(-1, -1) : mp(v, leng(v) - 1);
}

pt down (int v, int lf, int rg)
{
    if (lf == rg)
        return mp(v, 0);
        
    while (true)
    {
        v = t[v].next[s[lf] - 'a'];
        
        if (leng(v) >= rg - lf)
            return mp(v, leng(v) - (rg - lf));
            
        lf += leng(v);
    }
    
    throw;
}

int link (int v)
{
    if (t[v].link == -1)
        t[v].link = split(down(link(t[v].p), t[v].lf + (t[v].p == 0), t[v].rg));
        
    return t[v].link;
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

int solve()
{
    int m = strlen(buf);
    forn(i, m) buf[m + i] = buf[i];

    set <pt> was;
    int res = 0;
    int lf = 0, rg = 0;
    pt ptr = mp(0, 0);
    
    /*forn(i, 2 * m)
        cerr << buf[i];
    cerr << endl;*/
    
    while (lf < m)
    {
        while (rg < lf + m)
        {
            pt nptr = go(ptr, buf[rg]);
            if (nptr.V == -1) break;
            ptr = nptr;
            rg++;           
        }
        
        //cerr << lf << ' ' << rg << endl;
        
        if (rg - lf == m && !was.count(ptr))
        {
            res += cnt[ptr.V];
            was.insert(ptr);
        }
        
        if (rg > lf)
            ptr = down(link(t[ptr.V].p), t[ptr.V].lf + (t[ptr.V].p == 0), t[ptr.V].rg - ptr.L);
        else
            rg++;
        
        lf++;
    }
    
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    n = strlen(s);
    s[n++] = char('z' + 1);

    makeTree();
    
    dfs(0);
    
    int q;
    scanf("%d\n", &q);
    
    forn(i, q)
    {
        gets(buf);
        printf("%d\n", solve());
    }

    return 0;
}