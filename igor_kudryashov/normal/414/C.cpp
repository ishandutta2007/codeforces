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

const int N = (1 << 20) + 13;

int n;
int a[N];
li res[23][2];

inline bool read()
{
    if (scanf("%d", &n) != 1) return false;
    
    forn(i, (1 << n)) assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

int b[2][N];

inline void prepare ()
{
    forn(i, n)
    {
        for (int start = 0; start < (1 << n); start += (1 << (i + 1)))
        {
            int len = (1 << i);
            
            int p = start;
            forn(it, 2)
                forn(j, len)
                    b[it][j] = a[p++];
                
            forn(it, 2)
            {
                p = 0;
                forn(j, len)
                {
                    while (p < len && b[it ^ 1][p] < b[it][j]) p++;
                    res[i][it] += p;
                }
            }
            
            inplace_merge(a + start, a + start + len, a + start + 2 * len);
        }
    }
}

inline void solve()
{
    prepare();
    
    int m;
    assert(scanf("%d", &m) == 1);
    
    int mask = 0;
    
    forn(i, m)
    {
        int pos;
        assert(scanf("%d", &pos) == 1);
        mask ^= (1 << pos) - 1;
        
        li ans = 0;
        forn(j, n) ans += res[j][bool(mask & (1 << j))];
        
        printf("%I64d\n", ans);
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