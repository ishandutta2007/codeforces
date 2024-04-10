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

const int N = 2000 + 13;

int k;

inline bool read()
{
    return cin >> k;
}

int g[N][N];
int n = 2;
vector <int> vs[50];
vector <int> fir[50];

inline void solve()
{
    vector <int> bits;
    forn(i, 32) if (k & (1 << i)) bits.pb(i);
    reverse(all(bits));
    
    int len = bits[0];
    
    forn(i, len + 2) fir[i].clear();
    fir[0].pb(0);
    fir[len + 1].pb(1);
    
    forl(i, len)
    {
        fir[i].pb(n++);
        fir[i].pb(n++);
    }
    
    forn(i, len + 1)
        forn(j1, sz(fir[i]))
            forn(j2, sz(fir[i + 1]))
                g[fir[i][j1]][fir[i + 1][j2]] = g[fir[i + 1][j2]][fir[i][j1]] = true;

    forn(it, sz(bits))
    {
        forn(i, len + 2) vs[i].clear();
        vs[0].pb(0);
        vs[len + 1].pb(1);
        
        forl(i, len)
        {
            if (i <= bits[it])
            {
                vs[i].pb(fir[i][0]);
                vs[i].pb(fir[i][1]);
                
            } else
            {
                vs[i].pb(n++);
            }
        }
        
        forn(i, len + 1)
            forn(j1, sz(vs[i]))
                forn(j2, sz(vs[i + 1]))
                    g[vs[i][j1]][vs[i + 1][j2]] = g[vs[i + 1][j2]][vs[i][j1]] = true;
    }
    
    printf("%d\n", n);
    
    forn(i, n)
    {
        forn(j, n) if (g[i][j]) putchar('Y'); else putchar('N');
        puts("");
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
    
#ifdef SU2_PROJ
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}