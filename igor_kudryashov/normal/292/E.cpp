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

int n, m;
int a[N], b[N];
int t[4 * N];

void push (int idx, int lf, int rg)
{
    if (t[idx] == -1) return;
    
    int mid = (lf + rg) >> 1;
    
    t[2 * idx + 1] = t[idx];
    t[2 * idx + 2] = t[idx] + (mid + 1 - lf);
    t[idx] = -1;
}

void upd (int idx, int lf, int rg, int l, int r, int val)
{
    if (lf == l && rg == r)
    {
        t[idx] = val;
        return;
    }
    
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (r <= mid) return upd(2 * idx + 1, lf, mid, l, r, val);
    if (l > mid) return upd(2 * idx + 2, mid + 1, rg, l, r, val);
    
    upd(2 * idx + 1, lf, mid, l, mid, val);
    upd(2 * idx + 2, mid + 1, rg, mid + 1, r, val + (mid + 1 - l));
}

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
        
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    forn(i, n) assert(scanf("%d", &b[i]) == 1);
    
    return true;
}

int get (int idx, int lf, int rg, int pos)
{
    if (lf == rg) return t[idx];
    
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid) return get(2 * idx + 1, lf, mid, pos);
    return get(2 * idx + 2, mid + 1, rg, pos);
}

inline void solve()
{
    memset(t, -1, sizeof(t));
    
    forn(i, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);
        
        if (type == 1)
        {
            int x, y, cnt;
            assert(scanf("%d%d%d", &x, &y, &cnt) == 3);
            --x, --y;
            
            upd(0, 0, n - 1, y, y + cnt - 1, x);
        
        } else if (type == 2)
        {
            int idx;
            assert(scanf("%d", &idx) == 1);
            --idx;
            
            int to = get(0, 0, n - 1, idx);
            if (to == -1) printf("%d\n", b[idx]);
            else printf("%d\n", a[to]);
            
        } else throw;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}