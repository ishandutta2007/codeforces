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

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000 + 13;

const int N = 500 * 1000 + 13;

int n;
int perm[N];
int x[N], y[N], z[N];
int xs[N], ys[N], zs[N];
int szxs, szys, szzs;
int t[4 * N], szt;

inline bool cmp (const int& i, const int& j)
{
    if (x[i] != x[j])
        return x[i] > x[j];
        
    if (y[i] != y[j])
        return y[i] > y[j];
        
    return z[i] > z[j];
}

int min (int idx, int lf, int rg, int l, int r)
{
    if (l > r)
        return INF;
        
    if (lf == l && rg == r)
        return t[idx];
        
    int mid = (lf + rg) >> 1;
    int res = INF;
    
    if (l <= mid)
        res = min(res, min(2 * idx + 1, lf, mid, l, min(r, mid)));
    
    if (r > mid)
        res = min(res, min(2 * idx + 2, mid + 1, rg, max(l, mid + 1), r));
        
    return res;
}

void upd (int idx, int lf, int rg, int pos, int val)
{
    if (lf == rg)
        return void(t[idx] = min(t[idx], val));
        
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid)
        upd(2 * idx + 1, lf, mid, pos, val);
    else
        upd(2 * idx + 2, mid + 1, rg, pos, val);
        
    t[idx] = min(t[2 * idx + 1], t[2 * idx + 2]);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
        scanf("%d", &x[i]), xs[szxs++] = x[i], perm[i] = i;
        
    forn(i, n)
        scanf("%d", &y[i]), ys[szys++] = y[i];
        
    forn(i, n)
        scanf("%d", &z[i]), zs[szzs++] = z[i];
        
    sort(perm, perm + n, cmp);
    
    sort(ys, ys + szys);
    szys = int(unique(ys, ys + szys) - ys);
    
    /*forn(i, szys)
        cerr << ys[i] << ' ';
    cerr << endl;*/
    
    sort(zs, zs + szzs);
    szzs = int(unique(zs, zs + szzs) - zs);
    
    szt = szys;
    memset(t, 63, sizeof(t));
    
    int ans = 0;
    
    for (int idx = 0; idx < n; )
    {
        int st = idx;
        while (idx < n && x[perm[idx]] == x[perm[st]])
            idx++;
            
        for (int j = st; j < idx; j++)
        {
            int i = perm[j];
            
            int posy = szys - 1 - int(lower_bound(ys, ys + szys, y[i]) - ys);
            int posz = szzs - 1 - int(lower_bound(zs, zs + szzs, z[i]) - zs);
            
            int minv = min(0, 0, szt - 1, 0, posy - 1);
        
            if (minv < posz)
                ans++;
        }
    
        for (int j = st; j < idx; j++)
        {
            int i = perm[j];
            
            int posy = szys - 1 - int(lower_bound(ys, ys + szys, y[i]) - ys);
            int posz = szzs - 1 - int(lower_bound(zs, zs + szzs, z[i]) - zs);
            
            upd(0, 0, szt - 1, posy, posz);
        }
    }
    
    cout << ans << endl;

    return 0;
}