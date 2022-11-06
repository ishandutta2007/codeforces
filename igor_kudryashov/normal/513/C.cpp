#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 13 + 3;

int n;
int lf[N], rg[N];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    forn(i, n) assert(scanf("%d%d", &lf[i], &rg[i]) == 2);
    return true;
}

ld d[N][N][N];

inline void solve()
{
    ld ans = 0;
    
    forl(x, 10 * 1000)
    //forl(x, 10)
    //fore(x, 5, 5)
    {
        forn(i, n + 1) forn(j, n + 1) forn(k, n + 1) d[i][j][k] = 0;
        d[0][0][0] = 1;
        
        forn(pos, n) forn(cnteq, pos + 1) forn(cntgr, pos + 1)
        {
            const ld& dv = d[pos][cnteq][cntgr];
            const ld denom = rg[pos] - lf[pos] + 1;
            
            //cerr << denom << endl;
            //cerr << pos << ' ' << cnteq << ' ' << cntgr << ' ' << dv << endl;
            
            if (lf[pos] < x)
                d[pos + 1][cnteq][cntgr] += dv * ld(min(x, rg[pos] + 1) - lf[pos]) / denom;
                
            if (lf[pos] <= x && x <= rg[pos])
                d[pos + 1][cnteq + 1][cntgr] += dv * 1.0 / denom;
                
            if (x < rg[pos])
                d[pos + 1][cnteq][cntgr + 1] += dv * ld(rg[pos] - max(lf[pos] - 1, x)) / denom;
        }
        
        forl(cnteq, n)
        {
            ans += x * d[n][cnteq][1];
            //cerr << d[n][cnteq][1] << ' ';
        }
        //cerr << endl;
        fore(cnteq, 2, n)
        {
            ans += x * d[n][cnteq][0];
            //cerr << d[n][cnteq][0] << ' ';
        }
        //cerr << endl << endl;
    }
    
    cout << ans << endl;
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
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}