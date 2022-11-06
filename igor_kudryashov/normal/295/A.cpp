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

int n, m, k;
pt a[N];
li b[N];
int cnt[N];
li x[N];
li add[N];

inline bool read()
{
    if (scanf("%d%d%d", &n, &m, &k) != 3)
        return false;
        
    forn(i, n) assert(scanf("%I64d", &x[i]) == 1);
        
    forn(i, m)
    {
        assert(scanf("%d%d", &a[i].x, &a[i].y) == 2);
        a[i].x--, a[i].y--;
        assert(scanf("%I64d", &b[i]) == 1);
    }
    
    return true;
}

inline void solve()
{
    forn(i, k)
    {
        int lf, rg;
        assert(scanf("%d%d", &lf, &rg) == 2);
        lf--, rg--;
        cnt[lf]++;
        cnt[rg + 1]--;
    }
    
    forl(i, N - 1) cnt[i] += cnt[i - 1];
    
    forn(i, m)
    {
        int lf = a[i].x, rg = a[i].y;
        li val = b[i] * cnt[i];
        add[lf] += val;
        add[rg + 1] -= val;
    }
    
    forn(i, n)
    {
        li cur = x[i];
        if (i > 0) add[i] += add[i - 1];
        cur += add[i];
        printf("%I64d ", cur);
    }
    puts("");
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