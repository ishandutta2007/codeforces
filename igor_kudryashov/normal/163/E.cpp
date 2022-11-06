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
#include <bitset>
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
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
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

const int N = 1000 * 1000 + 13;
const int M = 100 * 1000 + 13;

struct node
{
    int next[26];
    int link, par, pch;
    bool term;
    
    node ()
    {
        memset(next, -1, sizeof(next));
        link = par = pch = -1;
        term = false;
    }
};

int q, cnts;
char buf[N];
node t[N];
int szt = 1;
int vterm[M];
vector <int> g[N];
int sumt[2 * N];
pt occ[N];
int szsumt;
bool inced[N];

void inc (int v, int val)
{
    if (inced[v] && val == 1) return;
    if (!inced[v] && val == -1) return;
    if (val == 1) inced[v] = true; else inced[v] = false;
    
    for (int i = occ[v].ft; i < szsumt; i = (i | (i + 1)))
        sumt[i] += val;
        
    val *= -1;
    
    for (int i = occ[v].sc; i < szsumt; i = (i | (i + 1)))
        sumt[i] += val;
}

int sum (int v)
{
    int res = 0;
    
    for (int idx = occ[v].ft; idx >= 0; idx = (idx & (idx + 1)) - 1)
        res += sumt[idx];
        
    return res;
}

void dfs (int v)
{
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        occ[to].ft = szsumt++;
        dfs(to);
        occ[to].sc = szsumt++;
    }   
}

int link (int);

int go (int v, int c)
{
    int& ans = t[v].next[c];
    if (ans != -1) return ans;
    if (v == 0) return ans = 0;
    return ans = go(link(v), c);
}

int link (int v)
{
    int& ans = t[v].link;
    if (ans != -1) return ans;
    if (t[v].par == 0) return ans = 0;
    return ans = go(link(t[v].par), t[v].pch);
}

void add (int idx)
{
    int len = strlen(buf);
    int v = 0;
    
    forn(i, len)
    {
        if (t[v].next[buf[i] - 'a'] == -1)
        {
            t[v].next[buf[i] - 'a'] = szt;
            t[szt].par = v;
            t[szt].pch = buf[i] - 'a';
            szt++;
        }
            
        v = t[v].next[buf[i] - 'a'];
    }
    t[v].term = true;
    vterm[idx] = v;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d %d\n", &q, &cnts);
    
    forn(i, cnts)
    {
        gets(buf);
        add(i);
    }
    
    t[0].link = t[0].par = 0;
    for1(i, szt - 1)
        t[i].link = link(i);
        
    //forn(i, szt)
    //  cerr << i << ' ' << t[i].par << ' ' << char(t[i].pch + 'a') << ' ' << t[i].link << endl;
    
    for1(i, szt - 1)
        g[t[i].link].pb(i);
        
    memset(occ, -1, sizeof(occ));
    dfs(0);
    
    forn(i, cnts)
        inc(vterm[i], 1);
        
    forn(i, q)
    {
        char type;
        scanf("%c", &type);
        
        if (type == '-' || type == '+')
        {
            int idx;
            scanf("%d\n", &idx);
            --idx;
            inc(vterm[idx], type == '+' ? 1 : -1);
            
        } else
        {
            gets(buf);
            int len = strlen(buf);
            
            li ans = 0;
            int v = 0;
            
            forn(j, len)
            {
                v = go(v, buf[j] - 'a');
                ans += sum(v);
            }
            
            printf("%I64d\n", ans);
        }
    }

    return 0;
}