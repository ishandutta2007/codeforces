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

const int N = 100 * 1000 + 13;

int n;
int a[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    a[n++] = 0;
        
    sort(a, a + n);
    
    return true;
}

li gcd (li a, li b) { return a == 0 ? b : gcd(b % a, a); }

li c[N];

inline void solve()
{
    int lf = (n - 1) / 2, rg = lf;
    int cur = n % 2;
    c[lf] = li(n) * li(n - 1) / 2;
    int step = 1;
    li val = c[lf];
    
    while (true)
    {
        val -= step;
        step++;
        
        if (cur)
        {
            if (--lf < 0) break;
            c[lf] = val;
            
        } else
        {
            if (++rg >= n - 1) break;
            c[rg] = val;
        }
        
        cur ^= 1;
    }
    
    //forn(i, n - 1) cerr << c[i] << ' '; cerr << endl;
    
    li numer = 0, denom = n - 1;
    
    forn(i, n - 1) numer += li(a[i + 1] - a[i]) * c[i];
    
    li g = gcd(numer, denom);
    numer /= g, denom /= g;
    
    cout << numer << ' ' << denom << endl;
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
    
#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}