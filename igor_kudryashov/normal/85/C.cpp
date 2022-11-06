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
const int INF = 1000 * 1000 * 1000 + 13;

const int N = 100 * 1000 + 13;

int n, m;
int p[N], lf[N], rg[N], val[N];
pt a[N];
ld ans[N];
int root;
li torg[N];
int cnt[N];
int mind[N], maxd[N];

void upd (int lf, int rg, int val)
{
    assert(lf < rg);
    
    int k1 = int(lower_bound(a, a + m, mp(lf, -1)) - a);
    int k2 = int(lower_bound(a, a + m, mp(rg, -1)) - a);
    
    torg[k1] += val;
    torg[k2] -= val;
    
    cnt[k1]++;
    cnt[k2]--;
}

void go (int v, int minv, int maxv)
{
    if (lf[v] == -1 && rg[v] == -1)
        return;
        
    {
        int lfmax = maxd[lf[v]];
        upd(val[v], maxv, lfmax);
    }
    
    {
        int rgmin = mind[rg[v]];
        upd(minv, val[v], rgmin);
    }
        
    go(lf[v], minv, val[v]);
    go(rg[v], val[v], maxv);
}

void dfs (int v)
{
    mind[v] = maxd[v] = val[v];
    
    if (lf[v] != -1)
    {
        dfs(lf[v]);
        
        mind[v] = min(mind[v], mind[lf[v]]);
        maxd[v] = max(maxd[v], maxd[lf[v]]);
    }
    
    if (rg[v] != -1)
    {
        dfs(rg[v]);
        
        mind[v] = min(mind[v], mind[rg[v]]);
        maxd[v] = max(maxd[v], maxd[rg[v]]);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    memset(lf, -1, sizeof(lf));
    memset(rg, -1, sizeof(rg));
    
    forn(i, n)
    {
        scanf("%d%d", &p[i], &val[i]);
        p[i]--;
        
        if (p[i] < 0)
        {
            root = i;
            continue;
        }
            
        int pr = p[i];
            
        if (lf[pr] == -1)
            lf[pr] = i;
        else
        {
            if (val[i] > val[lf[pr]])
                rg[pr] = i;
            else
            {
                rg[pr] = lf[pr];
                lf[pr] = i;
            }
        }
    }
    
    cin >> m;
    
    forn(i, m)
        scanf("%d", &a[i].ft), a[i].sc = i;
        
    sort(a, a + m);
    
    dfs(root);
    
    go(root, -INF, INF);
    
    ld curSum = 0.0;
    int curCnt = 0;
    
    forn(i, m)
    {
        curSum += torg[i];
        curCnt += cnt[i];
        
        assert(curCnt > 0);
        
        ans[a[i].sc] += curSum;
        ans[a[i].sc] /= curCnt;
    }
    
    forn(i, m)
        printf("%.10lf\n", double(ans[i]));

    return 0;
}