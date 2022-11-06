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

const int N = 4 * 100 * 1000 + 13;

#define V first
#define L second

struct node
{
    map <char, int> next;
    int lf, rg, link;
    int p;
    
    node (int lf = 0, int rg = 0, int link = -1, int p = -1) : lf(lf), rg(rg), link(link), p(p) {}
    
    int& operator [] (char c)
    {
        if (next.count(c))
            return next[c];
            
        return next[c] = -1;
    }
};

int n;
char s[N];
node t[N];
int szt;
int cnt[N];

inline int leng (int v)
{
    return t[v].rg - t[v].lf;
}

pt go (pt ptr, char c)
{
    int v = ptr.V, up = ptr.L;
    
    if (up != 0)
        return s[t[v].rg - up] == c ? mp(v, up - 1) : mp(-1, -1);
        
    v = t[v][c];
    
    return v == -1 ? mp(-1, -1) : mp(v, leng(v) - 1);
}

int addVertex (int v, int lf, int rg)
{
    t[szt] = node(lf, rg, -1, v);
    t[v][s[lf]] = szt;
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
    
    t[v].lf += down;
    t[v].p = mid;
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
}

int link (int v)
{
    if (t[v].link == -1)
        t[v].link = split(down(link(t[v].p), t[v].lf + int(t[v].p == 0), t[v].rg));
        
    return t[v].link;
}

pt addChar (pt ptr, int i)
{
    while (true)
    {
        pt nptr = go(ptr, s[i]);
        if (nptr.V != -1)
            return nptr;
            
        int v = split(ptr);
        addVertex(v, i, n);
        
        ptr = mp(link(v), 0);
        
        if (v == 0)
            return ptr;
    }
}

void makeTree ()
{
    szt = 0;
    t[szt++] = node(0, 0, 0, -1);
    
    pt ptr = mp(0, 0);
    
    forn(i, n)
        ptr = addChar(ptr, i);
}

void dfs (int v)
{
    if (t[v].next.empty())
        cnt[v] = 1;

    for (map <char, int> :: iterator it = t[v].next.begin(); it != t[v].next.end(); it++)
    {
        dfs(it->sc);
        cnt[v] += cnt[it->sc];
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    n = strlen(s);
    s[n++] = '$';
    
    makeTree();
    
    dfs(0);
    
    li ans = 0;
    
    for1(i, szt - 1)
        ans += (leng(i) - (t[i].next.empty())) * 1LL * cnt[i] * 1LL * (cnt[i] + 1) / 2LL;
        
    cout << ans << endl;

    return 0;
}