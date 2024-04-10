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

int a[N];
map <int, int> pos;
int n;
li s[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
        assert(scanf("%d", &a[i]) == 1);
        
    forn(i, n)
        pos[a[i]] = i;
        
    return true;
}

inline void solve()
{
    ford(i, n)
    {
        s[i] = s[i + 1];
        if (a[i] >= 0) s[i] += a[i];
    }
    
    li sum = -INF64;
    pt ans = mp(-1, -1);
    
    forn(i, n)
    {
        int lf = i, rg = pos[a[i]];
        if (rg == lf) continue;
        
        li cur = s[lf + 1] - s[rg];
        cur += 2 * a[i];
        
        if (cur > sum) sum = cur, ans = mp(lf, rg);
    }
    
    //cerr << ans.ft << ' ' << ans.sc << endl;
    
    vector <int> ansv;
    
    forn(i, n)
        if (i < ans.ft || i > ans.sc || (i != ans.ft && i != ans.sc && a[i] < 0))
            ansv.pb(i);
            
    cout << sum << ' ' << sz(ansv) << endl;
    
    forn(i, sz(ansv)) printf("%d ", ansv[i] + 1);
    puts("");
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