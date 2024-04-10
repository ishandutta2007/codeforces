#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;
const int mod = 95542721;
const int C = 48;

inline int binPow (int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (res * 1LL * a) % mod;
        b >>= 1;
        a = (a * 1LL * a) % mod;
    }
    return res;
}

inline int myRand() { return rand() ^ (rand() << 16); }

int n, a[N];
vector <int> t[4 * N];
int sh[4 * N];
int add[4 * N];

//#define TEST

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
#ifndef TEST
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
#else
    forn(i, n) a[i] = myRand() % mod;
#endif
    
    return true;
}

void build (int idx, int lf, int rg)
{
    t[idx].resize(C);
        
    if (lf == rg)
    {
        int cura = a[lf];
        
        forn(iter, C)
        {
            t[idx][iter] = cura;
            int now = cura;
            cura = (cura * 1LL * now) % mod;
            cura = (cura * 1LL * now) % mod;
        }
        
    } else
    {
        int mid = (lf + rg) >> 1;
        build(2 * idx + 1, lf, mid);
        build(2 * idx + 2, mid + 1, rg);
        
        forn(iter, C)
        {
            t[idx][iter] = t[2 * idx + 1][iter] + t[2 * idx + 2][iter];
            while (t[idx][iter] >= mod) t[idx][iter] -= mod;
        }
    }
}

inline void push (int idx)
{
    if (add[idx] >= C) add[idx] %= C;
    
    forl(i, 2)
    {
        sh[2 * idx + i] += add[idx];
        while (sh[2 * idx + i] >= C) sh[2 * idx + i] -= C;
        
        add[2 * idx + i] += add[idx];
    }
    add[idx] = 0;
}

void upd (int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r)
    {
        if (++sh[idx] >= C) sh[idx] -= C;
        add[idx]++;
        return;
    }
    
    push(idx);
    
    int mid = (lf + rg) >> 1;
    
    if (l <= mid)
        upd(2 * idx + 1, lf, mid, l, min(mid, r));
        
    if (r > mid)
        upd(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r);
        
    forn(it, C)
    {
        int i = (sh[idx] + it >= C ? sh[idx] + it - C : sh[idx] + it);
        int i1 = (sh[2 * idx + 1] + it >= C ? sh[2 * idx + 1] + it - C : sh[2 * idx + 1] + it);
        int i2 = (sh[2 * idx + 2] + it >= C ? sh[2 * idx + 2] + it - C : sh[2 * idx + 2] + it);
        t[idx][i] = t[2 * idx + 1][i1] + t[2 * idx + 2][i2];
        while (t[idx][i] >= mod) t[idx][i] -= mod;
    }
}

int sum (int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r) return t[idx][sh[idx]];
    
    push(idx);
    
    int mid = (lf + rg) >> 1;
    int res = 0;
    
    if (l <= mid) res += sum(2 * idx + 1, lf, mid, l, min(mid, r));
    if (r > mid) res += sum(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r);
    
    while (res >= mod) res -= mod;
    
    return res;
}

inline void solve()
{
    build(0, 0, n - 1);
    
    cerr << "build = " << clock() << endl;
    
    int m;
    assert(scanf("%d", &m) == 1);
    
    forn(iter, m)
    {
        int type, lf, rg;
#ifndef TEST
        assert(scanf("%d%d%d", &type, &lf, &rg) == 3);
#else
        type = (rand() & 1) + 1, lf = myRand() % n + 1, rg = myRand() % n + 1;
        if (lf > rg) swap(lf, rg);
#endif
        --lf, --rg;
        
        if (type == 1)
            printf("%d\n", sum(0, 0, n - 1, lf, rg));
        else
            upd(0, 0, n - 1, lf, rg);
    }
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    cerr << clock() << endl;
    
    return 0;
}