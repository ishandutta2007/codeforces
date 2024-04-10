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

const int N = 300 + 13;

int n;
pt p[N];
li ansVal;

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, n) assert(scanf("%d%d", &p[i].x, &p[i].y) == 2);
    
    return true;
}

inline li cross (const pt& a, const pt& b) { return a.x * b.y - a.y * b.x; }

inline pt operator - (const pt& a, const pt& b) { return mp(a.x - b.x, a.y - b.y); }

inline void solve()
{
    forn(i, n)
        forn(j, i)
        {
            li maxLf = -1, maxRg = -1;
            
            li A = p[j].y - p[i].y, B = p[i].x - p[j].x, C = -(A * p[i].x + B * p[i].y);
            
            forn(k, n)
            {
                li s = p[k].x * A + p[k].y * B + C;
                if (s > 0) maxLf = max(maxLf, abs(cross(p[i] - p[j], p[k] - p[j])));
                else if (s < 0) maxRg = max(maxRg, abs(cross(p[i] - p[j], p[k] - p[j])));
            }
            
            if (maxLf != -1 && maxRg != -1) ansVal = max(ansVal, maxLf + maxRg);
        }
        
    cout << ld(ansVal) / 2.0 << endl;
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