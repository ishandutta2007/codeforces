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

struct tree
{
    int x, h, lf, rg;
};

struct mush
{
    int x, z;
};

inline bool operator < (const mush& a, const mush& b)
{
    return a.x < b.x;
}

const int N = 100 * 1000 + 13;

int n, m;
tree ts[N];
mush ms[N];

ld add[4 * N];
vector <int> poses;

void build (int idx, int lf, int rg)
{
    if (lf == rg)
    {
        add[idx] = 1.0;
        return;
    }
        
    int mid = (lf + rg) >> 1;
    
    build(2 * idx + 1, lf, mid);
    build(2 * idx + 2, mid + 1, rg);
    
    add[idx] = 1.0;
}

inline void push (int idx, int lf, int rg)
{
    add[2 * idx + 1] *= add[idx];
    add[2 * idx + 2] *= add[idx];
    add[idx] = 1.0;
}

void upd (int idx, int lf, int rg, int l, int r, ld pr)
{
    if (lf == l && rg == r)
        return void(add[idx] *= pr);
        
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (l <= mid)
        upd(2 * idx + 1, lf, mid, l, min(mid, r), pr);
        
    if (r > mid)
        upd(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r, pr);
}

void upd (int lf, int rg, ld pr)
{
    int lfpos = int(lower_bound(all(poses), lf) - poses.begin());
    
    if (!(lfpos >= 0 && lfpos < n)) return;
    
    int rgpos = int(lower_bound(all(poses), rg + 1) - poses.begin()) - 1;
    
    if (!(rgpos >= 0 && rgpos < n)) return;
    
    if (lfpos > rgpos) return;
    
    upd(0, 0, n - 1, lfpos, rgpos, pr);
}

ld get (int idx, int lf, int rg, int pos)
{
    if (lf == rg)
    {
        assert(lf == pos);
        return add[idx];
    }
    
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid)
        return get(2 * idx + 1, lf, mid, pos);
        
    return get(2 * idx + 2, mid + 1, rg, pos);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> m >> n;
    
    forn(i, m)
        scanf("%d%d%d%d", &ts[i].x, &ts[i].h, &ts[i].lf, &ts[i].rg);
        
    forn(i, n)
    {
        scanf("%d%d", &ms[i].x, &ms[i].z);
        poses.pb(ms[i].x);
    }
        
    sort(ms, ms + n);
    sort(all(poses));
    
    build(0, 0, n - 1);
    
    forn(i, m)
    {
        int lf = ts[i].x - ts[i].h, rg = ts[i].x - 1;
        upd(lf, rg, 1.0 - ts[i].lf / 100.0);
        
        lf = ts[i].x + 1, rg = ts[i].x + ts[i].h;
        upd(lf, rg, 1.0 - ts[i].rg / 100.0);
    }
    
    ld ans = 0.0;
    
    forn(i, n)
        ans += ms[i].z * get(0, 0, n - 1, i);
        
    cout << setprecision(10) << fixed;
    cout << ans << endl;

    return 0;
}