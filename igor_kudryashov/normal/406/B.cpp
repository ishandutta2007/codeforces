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

const int N = 1000 * 1000 + 13;

int n = 1000 * 1000;
int m;
int used[N];

inline bool read()
{
    if (scanf("%d", &m) != 1) return false;
    
    forn(i, m)
    {
        int a;
        assert(scanf("%d", &a) == 1);
        used[a] = 1;
    }
    
    return true;
}

inline void solve()
{
    int cnt = 0;
    
    forl(i, n)
    {
        if (used[i] == 1 && used[n + 1 - i] == 1)
        {
            if (i < n + 1 - i) cnt++;
        }
        else if (used[i] == 1)
            used[n + 1 - i] = 2;
    }
    
    forl(i, n)
        if (used[i] == 0 && used[n + 1 - i] == 0 && cnt > 0)
        {
            used[i] = used[n + 1 - i] = 2;
            cnt--;
        }
        
    assert(cnt == 0);
        
    vector <int> ans;
    forl(i, n) if (used[i] == 2) ans.pb(i);
    
    cout << sz(ans) << endl;
    forn(i, sz(ans)) printf("%d ", ans[i]);
    puts("");
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