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

const int N = 100 * 1000 + 13;

int n;
int a[N];
vector <int> v;
int t[4 * N];
int ans[N];

void build (int idx, int lf, int rg)
{
    if (lf == rg)
        t[idx] = -INF;
    else
    {
        int mid = (lf + rg) >> 1;
        
        build(2 * idx + 1, lf, mid);
        build(2 * idx + 2, mid + 1, rg);
    }
}

int max (int idx, int lf, int rg, int l, int r)
{
    if (l > r)
        return -INF;

    if (lf == l && rg == r)
        return t[idx];
        
    int mid = (lf + rg) >> 1;
    int res = -INF;
    
    if (l <= mid)
        res = max(res, max(2 * idx + 1, lf, mid, l, min(mid, r)));
    
    if (r > mid)
        res = max(res, max(2 * idx + 2, mid + 1, rg, max(l, mid + 1), r));
        
    return res;
}

void upd (int idx, int lf, int rg, int pos, int val)
{
    if (lf == rg)
    {
        t[idx] = max(t[idx], val);
        return;
    }
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid)
        upd(2 * idx + 1, lf, mid, pos, val);
    else
        upd(2 * idx + 2, mid + 1, rg, pos, val);
        
    t[idx] = max(t[2 * idx + 1], t[2 * idx + 2]);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        scanf("%d", &a[i]);
        v.pb(a[i]);
    }
    
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    
    build(0, 0, sz(v) - 1);
    
    for (int i = n - 1; i >= 0; i--)
    {
        int pos = int(lower_bound(all(v), a[i]) - v.begin());
        
        int maxv = max(0, 0, sz(v) - 1, 0, pos - 1);
        
        if (maxv <= i)
            ans[i] = -1;
        else
            ans[i] = maxv - i - 1;
            
        upd(0, 0, sz(v) - 1, pos, i);
    }
    
    forn(i, n)
        printf("%d ", ans[i]);
        
    puts("");

    return 0;
}