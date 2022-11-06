#pragma comment(linker, "/stack:64000000")
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

const int N = 100 * 1000 + 13;

int n;
int type[N];
vector <int> g[N], tg[N];
int ansVal = 0, ansBG = 0;
vector <pt> ans;
vector <int> cyc;
int used[N], U = 1;
int calced[N];
int V, PV;
pt d[N][2][2];
int bestTo[N][2][2];

inline pt operator + (const pt& a, const pt& b)
{
    return mp(a.ft + b.ft, a.sc + b.sc);
}

inline pt operator - (const pt& a, const pt& b)
{
    return mp(a.ft - b.ft, a.sc - b.sc);
}

pt solve (int v, int may, int takeLast)
{
    pt& res = d[v][may][takeLast];
    
    if (res.ft != -1)
        return res;
    
    pt sumNext = mp(0, 0);
    
    forn(i, sz(tg[v]))
    {
        int to = tg[v][i];
        
        if (to != V)
            sumNext = sumNext + solve(to, 1, takeLast);
    }
    
    res = sumNext;
    
    if (may == 0 || (v == V && takeLast))
        return res;
        
    if (v == PV && takeLast)
    {
        pt nw = sumNext + mp(1, type[v] != type[V]);
        if (nw > res)
            res = nw, bestTo[v][may][takeLast] = V;
        return res;
    }
        
    forn(i, sz(tg[v]))
    {
        int to = tg[v][i];
        
        if ((v == PV && to == V) || (to == PV && takeLast))
            continue;
        
        pt nw = sumNext - solve(to, 1, takeLast) + solve(to, 0, takeLast) + mp(1, type[v] != type[to]);

        if (nw > res)
            res = nw, bestTo[v][may][takeLast] = to;
    }
    
    return res;
}

void restore (int v, int may, int takeLast)
{
    int& To = bestTo[v][may][takeLast];
    if (To != -1)
    {
        ans.pb(mp(v, To));
        
        if (To != V)
            restore(To, 0, takeLast);
    }
    
    forn(i, sz(tg[v]))
    {
        int to = tg[v][i];
        
        if (to != To && to != V)
            restore(to, 1, takeLast);
    }
}

void dfs (int v)
{
    calced[v] = true;
    
    forn(i, sz(tg[v]))
    {
        int to = tg[v][i];
        
        if (!calced[to])
            dfs(to);
    }
}

void solveComp (int v)
{
    cyc.clear();    
    while (used[v] != U)
    {
        cyc.pb(v);
        used[v] = U;
        v = g[v][0];
    }
    cyc.pb(v);
    
    reverse(all(cyc));
    while (cyc.back() != cyc[0])
        cyc.pop_back();
    reverse(all(cyc));
    
    dfs(cyc[0]);

    V = cyc[0];
    PV = cyc[1];
    pt ans1 = solve(cyc[0], 0, 1);
    pt ans2 = solve(cyc[0], 1, 0);
    
    if (ans1 > ans2)
    {
        ansVal += ans1.ft, ansBG += ans1.sc;
        restore(cyc[0], 0, 1);
    } else
    {
        ansVal += ans2.ft, ansBG += ans2.sc;
        restore(cyc[0], 1, 0);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    memset(d, -1, sizeof(d));
    memset(bestTo, -1, sizeof(bestTo));
    
    cin >> n;
    
    forn(i, n)
    {
        int to;
        scanf("%d%d", &to, &type[i]);
        --to, --type[i];
        
        g[i].pb(to);
        tg[to].pb(i);
    }
    
    forn(i, n)
        if (!calced[i])
            solveComp(i);
            
    printf("%d %d\n", ansVal, ansBG);
    assert(sz(ans) == ansVal);
    int cntBG = 0;
    forn(i, sz(ans))
    {
        cntBG += (type[ans[i].ft] != type[ans[i].sc]);
        printf("%d %d\n", ans[i].ft + 1, ans[i].sc + 1);
    }
    assert(cntBG == ansBG);

    return 0;
}