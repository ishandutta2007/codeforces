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

const int N = 500 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

int n1, n2;
int c[N][N], f[N];

inline bool read()
{
    int n;
    if (scanf("%d", &n) != 1)
        return false;
        
    forn(i, n)
    {   
        int tmp;
        assert(scanf("%d", &tmp) == 1);
        if (tmp == 1) n1++; else n2++;
    }
    
    return true;
}

int d[N][N];

int solve (int n1, int n2)
{
    int& ans = d[n1][n2];
    if (ans != -1) return ans;
    
    if (n1 == 0) return ans = f[n2];
    
    ans = 0;
    
    forn(c2, n2 + 1)
    {
        int t = (c[n2][c2] * 1LL * f[c2]) % mod;
        ans = (ans + solve(n1 - 1, n2 - c2) * 1LL * t) % mod;
    
        t = (c[n2][c2] * 1LL * (n1 - 1)) % mod;
        t = (t * 1LL * f[c2 + 1]) % mod;
        
        ans = (ans + t * 1LL * solve(n1 - 2, n2 - c2)) % mod;
        
        //cerr << n1 << ' ' << n2 << ' ' << c2 << ' ' << ans << endl;
    }
    
    //cerr << n1 << ' ' << n2 << ' ' << ans << endl;
    
    return ans;
}

int cnt[N];
vector <int> perm;
set < vector <int> > s;

void go ()
{
    s.insert(perm);
    
    forn(i, sz(perm))
        forn(j, i)
            if (cnt[i] > 0 && cnt[j] > 0)
            {
                cnt[i]--, cnt[j]--;
                swap(perm[i], perm[j]);
                go();
                swap(perm[i], perm[j]);
                cnt[i]++, cnt[j]++;             
            }
}

inline int naive (int n1, int n2)
{
    forn(i, n1 + n2)
    {
        perm.pb(i);
        if (i < n1) cnt[i] = 1; else cnt[i] = 2;
    }
    
    go();
    
    return sz(s);
}

inline void solve()
{
    c[0][0] = 1;
    forl(i, N - 1)
        forn(j, i + 1)
            c[i][j] = ((j == 0 ? 0 : c[i - 1][j - 1]) + c[i - 1][j]) % mod;
            
    f[0] = 1;
    forl(i, N - 1) f[i] = (f[i - 1] * 1LL * i) % mod;
    
    memset(d, -1, sizeof(d));
    
    cout << solve(n1, n2) << endl;
    //cerr << naive(n1, n2) << endl;
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