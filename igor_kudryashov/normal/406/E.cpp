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

const int N = 100 * 1000 + 13;

int n, m;
vector <int> pos[2];
li ans = -1, cntans = 0;

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, m)
    {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        --b;
        pos[a].pb(b);       
    }
    
    return true;
}

inline li C (int n, int k)
{
    if (k < 0 || k > n) return 0;
    li res = 1;
    forn(i, k)
    {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

inline void solve2 ()
{
    int cmin = 0, cmax = 0;
    forn(i, sz(pos[0]))
    {
        if (pos[0][i] == pos[0][0]) cmin++;
        if (pos[0][i] == pos[0].back()) cmax++;
    }
    
    if (sz(pos[0]) >= 3)
    {
        li cur = pos[0].back() - pos[0][0];
        if (cur > ans) ans = cur, cntans = 0;
        if (cur == ans)
        {
            if (pos[0][0] == pos[0].back())
                cntans += sz(pos[0]) * 1LL * (sz(pos[0]) - 1) * (sz(pos[0]) - 2) / 6;
            else
            {
                int kk[] = {1, 0, 1};
                int nn[] = {cmin, sz(pos[0]) - cmin - cmax, cmax};
                
                forn(i, 3)
                {
                    kk[i]++;
                    li val = 1;
                    forn(j, 3) val *= C(nn[j], kk[j]);
                    cntans += val;
                    kk[i]--;
                }
            }
        }
    }
    
    if (sz(pos[0]) < 2) return;
    
    int fe = 0, fg = 0;
    
    forn(i, sz(pos[1]))
    {
        while (fe < sz(pos[0]) && pos[0][fe] < pos[1][i]) fe++;
        while (fg < sz(pos[0]) && pos[0][fg] <= pos[1][i]) fg++;
        
        if (pos[0][0] > pos[1][i])
        {
            li cur = n - (pos[0][0] - pos[1][i]);
            if (cur > ans) ans = cur, cntans = 0;
            if (cur == ans) cntans += C(sz(pos[0]), 2) - C(sz(pos[0]) - cmin, 2);
        }
        else if (pos[0].back() < pos[1][i])
        {
            li cur = n - (pos[1][i] - pos[0].back());
            if (cur > ans) ans = cur, cntans = 0;
            if (cur == ans) cntans += C(sz(pos[0]), 2) - C(sz(pos[0]) - cmax, 2);
        } else
        {
            li cur = n;
            if (cur > ans) ans = cur, cntans = 0;
            if (cur == ans) cntans += C(sz(pos[0]), 2) - C(fe, 2) - C(sz(pos[0]) - fg, 2);
        }
    }
}

inline void solve()
{
    forn(i, 2) sort(all(pos[i]));
    
    forn(iter, 2)
    {
        solve2();
        swap(pos[0], pos[1]);
    }
    
    cout << cntans << endl;
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