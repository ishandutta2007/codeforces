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

const int N = 300 * 1000 + 13;

int n;
int a[N];
int t[4 * N];
int perm[N];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n)
    {
        assert(scanf("%d", &perm[i]) == 1);
        --perm[i];
        a[perm[i]] = i;
    }
    
    return true;
}

void build (int idx, int lf, int rg)
{
    if (lf == rg)
    {
        t[idx] = 1;
        
    } else
    {
        int mid = (lf + rg) >> 1;
        
        build(2 * idx + 1, lf, mid);
        build(2 * idx + 2, mid + 1, rg);
        
        t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
        if (a[mid] < a[mid + 1]) t[idx]--;
        
        //cerr << lf << ' ' << rg << ' ' << t[idx] << endl;
    }
}

int sum (int idx, int lf, int rg, int l, int r)
{
    //cerr << lf << ' ' << rg << endl;
    
    if (lf == l && rg == r) return t[idx];
    
    int mid = (lf + rg) >> 1;
    
    if (r <= mid) return sum(2 * idx + 1, lf, mid, l, r);
    if (l > mid) return sum(2 * idx + 2, mid + 1, rg, l, r);
    
    int res = sum(2 * idx + 1, lf, mid, l, mid) + sum(2 * idx + 2, mid + 1, rg, mid + 1, r);
    if (a[mid] < a[mid + 1]) res--;
    
    return res;
}

void upd (int idx, int lf, int rg, int pos)
{
    if (lf == rg) return void(t[idx] = 1);
    
    int mid = (lf + rg) >> 1;
    if (pos <= mid) upd(2 * idx + 1, lf, mid, pos);
    else upd(2 * idx + 2, mid + 1, rg, pos);
    
    t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
    if (a[mid] < a[mid + 1]) t[idx]--;
}

inline void solve()
{
    build(0, 0, n - 1);
    
    int m;
    assert(scanf("%d", &m) == 1);
    
    forn(iter, m)
    {
        int type, lf, rg;
        assert(scanf("%d%d%d", &type, &lf, &rg) == 3);
        --lf, --rg;
        
        //cerr << type << ' ' << lf << ' ' << rg << endl;
        
        if (type == 1)
        {
            //cerr << lf << ' ' << rg << endl;
            
            printf("%d\n", sum(0, 0, n - 1, lf, rg));
            
        } else
        {
            swap(perm[lf], perm[rg]);
            swap(a[perm[lf]], a[perm[rg]]);
            upd(0, 0, n - 1, perm[lf]);
            upd(0, 0, n - 1, perm[rg]);
        }
    }
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}