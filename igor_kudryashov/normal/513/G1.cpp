#undef NDEBUG
#ifdef SU2_PROJ
//#define _GLIBCXX_DEBUG
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

int n, k;
vector<int> perm;

inline bool read()
{
    if (scanf("%d%d", &n, &k) != 2) return false;
    perm.resize(n);
    forn(i, n) assert(scanf("%d", &perm[i]) == 1), perm[i]--;
    return true;
}

map<vector<int>, ld> p[N];

inline void solve()
{
    p[0][perm] = 1;
    
    const ld& denom = n * (n + 1) / 2;
    
    forn(iter, k)
    {
        for (map<vector<int>, ld>::iterator it = p[iter].begin(); it != p[iter].end(); it++)
        {
            vector<int> cur = it->ft;
            const ld& dv = it->sc;
            
            forn(i, n) forn(j, i + 1)
            {
                vector<int> nw = cur;
                reverse(nw.begin() + j, nw.begin() + i + 1);
                p[iter + 1][nw] += dv / denom;
            }
        }
    }
    
    ld ans = 0;
    
    for (map<vector<int>, ld>::iterator it = p[k].begin(); it != p[k].end(); it++)
    {
        vector<int> cur = it->ft;
        const ld& dv = it->sc;
        
        int cnt = 0;
        forn(i, n) forn(j, i) if (cur[j] > cur[i]) cnt++;
        
        ans += cnt * dv;
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