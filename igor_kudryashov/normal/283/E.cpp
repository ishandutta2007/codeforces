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

int n, k;
int a[N];
vector < pair <int, pt> > ev;

inline bool read()
{
    if (scanf("%d%d", &n, &k) != 2)
        return false;
        
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    sort(a, a + n);
    
    forn(i, k)
    {
        int lf, rg;
        assert(scanf("%d%d", &lf, &rg) == 2);
        
        int lfidx = int(lower_bound(a, a + n, lf) - a);
        int rgidx = int(lower_bound(a, a + n, rg + 1) - a) - 1;
        
        if (lfidx > rgidx) continue;
        
        ev.pb(mp(lfidx, mp(lfidx, rgidx)));
        ev.pb(mp(rgidx + 1, mp(lfidx, rgidx)));
    }
    
    return true;
}

int t[4 * N], add[4 * N];

inline void push (int idx, int lf, int rg)
{
    if (add[idx] == 0) return;
    
    int mid = (lf + rg) >> 1;
    
    t[2 * idx + 1] = (mid - lf + 1) - t[2 * idx + 1];
    t[2 * idx + 2] = (rg - mid) - t[2 * idx + 2];
    add[2 * idx + 1] ^= 1;
    add[2 * idx + 2] ^= 1;
    
    add[idx] = 0;
}

void upd (int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r)
    {
        add[idx] ^= 1;
        t[idx] = (rg - lf + 1) - t[idx];
        return;
    }
    
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    if (l <= mid) upd(2 * idx + 1, lf, mid, l, min(mid, r));
    if (r > mid) upd(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r);
    
    t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
}

int sum (int idx, int lf, int rg, int l, int r)
{
    if (lf == l && rg == r) return t[idx];
    
    push(idx, lf, rg);
    
    int mid = (lf + rg) >> 1;
    
    int res = 0;
    
    if (l <= mid) res += sum(2 * idx + 1, lf, mid, l, min(mid, r));
    if (r > mid) res += sum(2 * idx + 2, mid + 1, rg, max(mid + 1, l), r);
    
    return res;
}

inline void solve()
{
    sort(all(ev));
    
    int ptr = 0;
    
    li total = n * 1LL * (n - 1) * (n - 2) / 6;
    upd(0, 0, n - 1, 0, n - 1);
    
    forn(i, n)
    {
        //forn(j, n) cerr << sum(0, 0, n - 1, j, j) << ' '; cerr << endl;
        upd(0, 0, n - 1, i, i);
        //forn(j, n) cerr << sum(0, 0, n - 1, j, j) << ' '; cerr << endl;
        
        while (ptr < sz(ev) && ev[ptr].ft == i)
        {
            //cerr << ev[ptr].ft << ' ' << ev[ptr].sc.ft << ' ' << ev[ptr].sc.sc << endl;
            upd(0, 0, n - 1, ev[ptr].sc.ft, ev[ptr].sc.sc);
            ptr++;
        }
        //forn(j, n) cerr << sum(0, 0, n - 1, j, j) << ' '; cerr << endl;
        //cerr << endl;
        
        //forn(j, n) cerr << sum(0, 0, n - 1, j, j) << ' '; cerr << endl;
        
        int cnt = t[0] - sum(0, 0, n - 1, i, i);
        
        //cerr << cnt << endl << endl;
        
        total -= cnt * 1LL * (cnt - 1) / 2;
    }
    
    assert(total >= 0);
    
    cout << total << endl;
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