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

struct node
{
    ld sum, maxp, maxs, maxv;
};

const int N = 200 * 1000 + 13;

int n, m, c;
int x[N];
ld val[N];
node t[4 * N];

node merge (node a, node b)
{
    node res;
    res.sum = a.sum + b.sum;
    res.maxp = max(a.maxp, a.sum + b.maxp);
    res.maxs = max(b.maxs, b.sum + a.maxs);
    res.maxv = max(max(a.maxv, b.maxv), a.maxs + b.maxp);
    return res;
}

void build (int idx, int lf, int rg)
{
    if (lf == rg)
    {   
        t[idx].sum = val[lf];
        if (val[lf] > EPS)
        {
            t[idx].maxp = val[lf];
            t[idx].maxs = val[lf];
            t[idx].maxv = val[lf];
        }
        return;
    }
    
    int mid = (lf + rg) >> 1;
    
    build(2 * idx + 1, lf, mid);
    build(2 * idx + 2, mid + 1, rg);
    
    t[idx] = merge(t[2 * idx + 1], t[2 * idx + 2]);
}

node getMax (int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r)
        return t[idx];
        
    int mid = (lf + rg) >> 1;
    
    if (r <= mid)
        return getMax(2 * idx + 1, lf, mid, l, r);
        
    if (l > mid)
        return getMax(2 * idx + 2, mid + 1, rg, l, r);
        
    return merge(getMax(2 * idx + 1, lf, mid, l, mid), getMax(2 * idx + 2, mid + 1, rg, mid + 1, r));
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> c;
    
    forn(i, n)
        scanf("%d", &x[i]);
        
    forn(i, n - 1)
    {
        int p;
        scanf("%d", &p);
        ld pr = ld(p) / 100.0;
        
        val[i] = ld(x[i + 1] - x[i]) / 2.0 - pr * c;
    }
    
    build(0, 0, n - 2);
        
    ld ans = 0.0;
    
    forn(i, m)
    {
        int lf, rg;
        scanf("%d%d", &lf, &rg);
        --lf, --rg;
        --rg;
        
        node t = getMax(0, 0, n - 2, lf, rg);
        
        ans += t.maxv;
    }
    
    cout << setprecision(10) << fixed;
    cout << ans << endl;

    return 0;
}