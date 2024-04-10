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

const int N = 1000 + 3;

int n, m;
char f[N][N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    forn(i, n) assert(scanf("%s", f[i]) == 1);
    return true;
}

pt topLeft;

int used[N][N];

inline bool down (const pt& cur, int w)
{
    forn(j, w) if (f[cur.x + 1][cur.y - j] != 'X') return false;
    return true;
}

inline bool right (const pt& cur, int h)
{
    forn(i, h) if (f[cur.x - i][cur.y + 1] != 'X') return false;
    return true;
}

inline bool check (int h, int w)
{
    cerr << topLeft << ' ' << h << ' ' << w << endl;
    
    if (h < 1 || topLeft.x + h > n) return false;
    if (w < 1 || topLeft.y + w > m) return false;
    
    memset(used, 0, sizeof(used));
    
    forn(i, h) forn(j, w) used[topLeft.x + i][topLeft.y + j] = true;
    
    pt cur(topLeft.x + h - 1, topLeft.y + w - 1);
    
    while (true)
    {
        //cerr << cur << ' ' << down(cur, w) << ' ' << right(cur, h) << endl;
        
        if (cur.x + 1 < n && down(cur, w))
        {
            cur.x++;
            forn(j, w) used[cur.x][cur.y - j] = true;
            continue;
        }
        
        if (cur.y + 1 < m && right(cur, h))
        {
            cur.y++;
            forn(i, h) used[cur.x - i][cur.y] = true;
            continue;
        }
        
        break;
    }
    
    forn(i, n) forn(j, m)
    {
        if (f[i][j] == '.' && used[i][j]) return false;
        if (f[i][j] == 'X' && !used[i][j]) return false;
    }
    
    return true;
}

inline void solve()
{
    topLeft = mp(-1, -1);
    forn(i, n) forn(j, m) if (f[i][j] == 'X')
    {
        topLeft = mp(i, j);
        goto done;
    }
    
    done:;
    
    int ans = INF;
    
    int w = 0;
    while (topLeft.y + w < m && f[topLeft.x][topLeft.y + w] == 'X') w++;
    
    int h = 0;
    while (topLeft.x + h < n && f[topLeft.x + h][topLeft.y] == 'X') h++;
    
    //cerr << w << ' ' << h << endl;
    
    {
        int w1 = w, h1 = 1;
        fore(i, topLeft.x, n - 1)
            if (f[i][topLeft.y + w] == 'X')
            {
                h1 = topLeft.x + h - i;
                break;
            }
        if (check(h1, w1))
            ans = min(ans, h1 * w1);
    }
    
    {
        int w1 = 1, h1 = h;
        fore(j, topLeft.y, m - 1)
            if (f[topLeft.x + h][j] == 'X')
            {
                w1 = topLeft.y + w - j;
                break;
            }
        if (check(h1, w1))
            ans = min(ans, h1 * w1);
    }
    
    if (ans > INF / 2) ans = -1;
    
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