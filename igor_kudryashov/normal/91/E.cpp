//18:00

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

typedef double ld;
typedef pair<ld, ld> ptd;
typedef pair <ld, int> ptdi;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;
const li INF64 = li(1e18);

const int N = 100 * 1000 + 13;

int n, m;
int a[N], b[N];
vector <ptdi> t[4 * N];

inline ld High (int num, ld Time)
{
    return a[num] + b[num] * Time;
}

inline ld cross (int i, int j)
{
    if (b[i] == b[j])
        return -1;
        
    return ld(a[j] - a[i]) / ld(b[i] - b[j]);
}

vector <ptdi> merge (const vector <ptdi>& a, const vector <ptdi>& b)
{
    vector <ptdi> ans;
    assert(!a.empty() && !b.empty());
    
    ld lf = 0;
    int idxa = 0, idxb = 0;

    while (idxa < sz(a) - 1 && idxb < sz(b) - 1)
    {
        ld rg = min(a[idxa + 1].ft, b[idxb + 1].ft);
        ld x = cross(a[idxa].sc, b[idxb].sc);
        
        if (x > lf + EPS && x + EPS < rg)
        {
            ld x1 = (lf + x) / 2.0, x2 = (x + rg) / 2.0;
        
            if (High(a[idxa].sc, x1) > High(b[idxb].sc, x1))
                ans.pb(mp(lf, a[idxa].sc));
            else
                ans.pb(mp(lf, b[idxb].sc));
                
            if (High(a[idxa].sc, x2) > High(b[idxb].sc, x2))
                ans.pb(mp(x, a[idxa].sc));
            else
                ans.pb(mp(x, b[idxb].sc));
            
        } else
        {
            ld x1 = (lf + rg) / 2.0;
        
            if (High(a[idxa].sc, x1) > High(b[idxb].sc, x1))
                ans.pb(mp(lf, a[idxa].sc));
            else
                ans.pb(mp(lf, b[idxb].sc));
        }
        
        if (a[idxa + 1].ft < b[idxb + 1].ft)
            lf = a[++idxa].ft;
        else
            lf = b[++idxb].ft;
    }
    ans.pb(mp(INF, ans.back().sc));
        
    return ans;
}

void build (int idx, int lf, int rg)
{
    if (lf == rg)
    {
        t[idx].pb(mp(0, lf));
        t[idx].pb(mp(INF, lf));
        
    } else
    {
        int mid = (lf + rg) >> 1;
        build(2 * idx + 1, lf, mid);
        build(2 * idx + 2, mid + 1, rg);
        
        t[idx] = merge(t[2 * idx + 1], t[2 * idx + 2]);
    }
}

ptdi max (int idx, int lf, int rg, int l, int r, int Time)
{
    if (lf == l && rg == r)
    {
        int k = int(lower_bound(all(t[idx]), mp(ld(Time), -1)) - t[idx].begin());
        
        if (k == sz(t[idx]) || t[idx][k].ft > Time + EPS)
            k--;
            
        assert(t[idx][k].ft < Time + EPS);
        return mp(High(t[idx][k].sc, Time), t[idx][k].sc);
    }
    
    int mid = (lf + rg) >> 1;
    ptdi res = mp(-1, -1);
    
    if (l <= mid)
        res = max(res, max(2 * idx + 1, lf, mid, l, min(mid, r), Time));
        
    if (r > mid)
        res = max(res, max(2 * idx + 2, mid + 1, rg, max(l, mid + 1), r, Time));
        
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    
    forn(i, n)
        scanf("%d%d", &a[i], &b[i]);
        
    build(0, 0, n - 1);
    
    forn(i, m)
    {
        int lf, rg, tt;
        scanf("%d%d%d", &lf, &rg, &tt);
        --lf, --rg;
        ptdi ans = max(0, 0, n - 1, lf, rg, tt);
        assert(ans.sc != -1);
        printf("%d\n", ans.sc + 1);
    }

    return 0;
}