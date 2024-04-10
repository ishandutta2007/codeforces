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

const int N = 100 * 1000 + 3;

int n, dy, m;
int xs[N], ys[N];
vector <pair <pt, int> > p;
vector <int> yy;
int maxg[N];
vector <pair <pt, int> > qs[N];
int ans[N];
int t[4 * N];

void updSum (int idx, int lf, int rg, int pos, int val)
{
    if (lf == rg) return void(t[idx] += val);
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid)
        updSum(2 * idx + 1, lf, mid, pos, val);
    else
        updSum(2 * idx + 2, mid + 1, rg, pos, val);
    
    t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
}

int sum (int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r) return t[idx];
    
    int mid = (lf + rg) >> 1;
    int res = 0;
    
    if (l <= mid)
        res += sum(2 * idx + 1, lf, mid, l, min(mid, r));
        
    if (r > mid)
        res += sum(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r);
        
    return res;
}

void updMax (int idx, int lf, int rg, int pos, int val)
{
    if (lf == rg) return void(t[idx] = max(t[idx], val));
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid)
        updMax(2 * idx + 1, lf, mid, pos, val);
    else
        updMax(2 * idx + 2, mid + 1, rg, pos, val);
        
    t[idx] = max(t[2 * idx + 1], t[2 * idx + 2]);
}

int max (int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r) return t[idx];
    
    int mid = (lf + rg) >> 1;
    int res = -1;
    
    if (l <= mid)
        res = max(res, max(2 * idx + 1, lf, mid, l, min(r, mid)));
        
    if (r > mid)
        res = max(res, max(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r));
        
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> dy;
    
    forn(i, n)
        scanf("%d", &xs[i]);
        
    forn(i, n)
    {
        scanf("%d", &ys[i]);
        yy.pb(ys[i]);
    }
    
    sort(all(yy));
    yy.erase(unique(all(yy)), yy.end());
        
    forn(i, n)
        p.pb(mp(mp(xs[i], ys[i]), i));
        
    sort(all(p));
    
    forn(i, n)
    {
        int idx = int(lower_bound(all(yy), p[i].ft.sc) - yy.begin());
        updSum(0, 0, sz(yy) - 1, idx, 1);
        
        int lf = int(lower_bound(all(yy), p[i].ft.sc - dy) - yy.begin());
        int rg = int(lower_bound(all(yy), p[i].ft.sc + dy + 1) - yy.begin()) - 1;
        
        maxg[p[i].sc] = sum(0, 0, sz(yy) - 1, lf, rg);
    }
    
    cin >> m;
    
    memset(ans, -1, sizeof(ans));
    
    forn(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        
        if (abs(ys[a] - ys[b]) > 2 * dy)
            continue;
        
        if (xs[a] < xs[b]) swap(a, b);
        
        qs[a].pb(mp(mp(max(ys[a], ys[b]) - dy, min(ys[a], ys[b]) + dy), i));
        
        if (xs[a] == xs[b])
            qs[b].pb(mp(mp(max(ys[a], ys[b]) - dy, min(ys[a], ys[b]) + dy), i));
    }
    
    memset(t, -1, sizeof(t));
    
    ford(i, n)
    {
        int idx = int(lower_bound(all(yy), p[i].ft.sc) - yy.begin());
        updMax(0, 0, sz(yy) - 1, idx, maxg[p[i].sc]);
        
        forn(j, sz(qs[p[i].sc]))
        {
            pair <pt, int> curq = qs[p[i].sc][j];
            
            int lf = int(lower_bound(all(yy), curq.ft.ft) - yy.begin());
            int rg = int(lower_bound(all(yy), curq.ft.sc + 1) - yy.begin()) - 1;
            
            if (lf <= rg)
                ans[curq.sc] = max(ans[curq.sc], max(0, 0, sz(yy) - 1, lf, rg));
        }
    }
    
    forn(i, m)
        printf("%d\n", ans[i]);

    return 0;
}