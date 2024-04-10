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

const int N = 100 + 13;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char c[] = { 'U', 'D', 'R', 'L' };

int x, y;
char s[N];
int n;

inline bool read()
{
    if (scanf("%d%d", &x, &y) != 2)
        return false;
        
    assert(scanf("%s", s) == 1);
    n = strlen(s);
    
    return true;
}

inline void solve()
{
    int curx = 0, cury = 0;
    
    forn(i, n)
    {
        forn(j, 4)
            if (s[i] == c[j])
                curx += dx[j], cury += dy[j];
    }
    
    int t = 0;
    if (curx != 0) t = max(t, x / curx);
    if (cury != 0) t = max(t, y / cury);
    t = max(0, t - 100);
    
    li xx = curx * 1LL * t;
    li yy = cury * 1LL * t;
    
    if (xx == x && yy == y)
    {
        puts("Yes");
        return;
    }

    const int M = 100 * 1000;
    
    forn(iter, M)
    {
        forn(i, n)
        {
            forn(j, 4)
                if (s[i] == c[j])
                    xx += dx[j], yy += dy[j];
                    
            if (xx == x && yy == y)
            {
                puts("Yes");
                return;
            }
        }
    }
    
    puts("No");
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