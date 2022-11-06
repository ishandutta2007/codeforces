#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
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
#include <list>
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

const int N = 1000 + 13;
const int V = 100 + 13;

const string ALP = "ACGT";

struct node
{
    int next[4], go[4];
    int p, link, len;
    bool leaf;
    char pch;
    int maxPref;
    
    node (int p, char c) : p(p), pch(c), link(-1), len(-1), leaf(false), maxPref(-1)
    {
        memset(next, -1, sizeof(next));
        memset(go, -1, sizeof(go));
    }
    
    node (int p = -1, int link = -1, int len = -1, bool leaf = false, char pch = 0, int maxPref = -1) 
    : p(p), link(link), len(len), leaf(leaf), pch(pch), maxPref(maxPref)
    {
        memset(next, -1, sizeof(next));
        memset(go, -1, sizeof(go));
    }
};

int n, m;
node t[V];
int szt;

const int MOD = 1000 * 1000 * 1000 + 9;

void add (string s)
{
    int v = 0;

    forn(i, sz(s))
    {
        int c = ALP.find(s[i]);
        assert(c != string::npos);
        
        if (t[v].next[c] == -1)
        {
            t[v].next[c] = szt;
            t[szt++] = node(v, s[i]);
        }
        
        v = t[v].next[c];
    }
    
    t[v].leaf = true;
    t[v].len = sz(s);
    t[v].maxPref = sz(s);
}

int link (int);

int down (int v, char ch)
{
    int c = ALP.find(ch);
    
    if (t[v].go[c] == -1)
    {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            if (v == 0)
                t[v].go[c] = 0;
            else
                t[v].go[c] = down(link(v), ch);
    }
    
    return t[v].go[c];
}

int link (int v)
{
    if (t[v].link == -1)
    {
        if (t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = down(link(t[v].p), t[v].pch);
    }
    
    return t[v].link;
}

int getMaxPref (int v)
{
    if (t[v].maxPref == -1)
        t[v].maxPref = max(0, getMaxPref(link(v)));
        
    return t[v].maxPref;
}

int d[N][V][13];

int solve (int pos, int v, int notcov)
{
    if (notcov > 10)
        return 0;

    int& res = d[pos][v][notcov];
    
    if (res != -1)
        return res;

    if (pos == n)
        return res = (notcov == 0);
        
    res = 0;
    
    forn(i, 4)
    {
        int nv = down(v, ALP[i]);
        
        if (nv == 0)
            continue;
            
        int nnotcov = notcov + 1;
        
        if (t[nv].maxPref >= nnotcov)
            nnotcov = 0;
            
        res += solve(pos + 1, nv, nnotcov);
        
        while (res >= MOD)
            res -= MOD;
    }
    
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;

    t[szt++] = node(0, 0, 0, true, 0, 0);
    
    forn(i, m)
    {
        string s;
        cin >> s;
        
        add(s);
    }
    
    forn(i, szt)
        t[i].link = link(i);
        
    forn(i, szt)
        t[i].maxPref = getMaxPref(i);
        
    memset(d, -1, sizeof(d));
        
    cout << solve(0, 0, 0) << endl;
        
    return 0;
}