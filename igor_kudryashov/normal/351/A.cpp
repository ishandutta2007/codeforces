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
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 4000 + 13;

int n;
int a[N], b[N];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    n *= 2;
    
    forn(i, n) assert(scanf("%d.%d", &a[i], &b[i]) == 2);
    
    return true;
}

inline void solve()
{
    ld s1 = 0, s2 = 0;
    
    int c1 = 0, c2 = 0;
    
    forn(i, n)
    {
        s1 += a[i] + ld(b[i]) / 1000;
        s2 += a[i];
        if (b[i] != 0) c1++; else c2++;
    }
    
    ld ans = 1e18;
    
    forn(add, min(n / 2 + 1, c1 + 1))
        if (add + c2 >= n / 2)
            ans = min(ans, abs(s1 - (s2 + add)));
    
    cout << ans << endl;
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    cout << setprecision(3) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();

#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}