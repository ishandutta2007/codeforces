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

const int N = 2000 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m;
int d[N][N][2];
int sums[N][N], sumd[N][N];
int prefs[N][N][2];

void prepare ()
{
    forl(h, N - 1)
        fore(len, 2, N - 1)
            forn(flag, 2)
            {
                if (h == 1) d[h][len][flag] = 1;
                else
                {
                    d[h][len][flag] = (sums[h - 1][len - 1] * 1LL * len) % mod;
                    d[h][len][flag] -= sumd[h - 1][len - 1];
                    if (d[h][len][flag] < 0) d[h][len][flag] += mod;

                    if (!flag)
                    {
                        d[h][len][flag] += d[h - 1][len][0];
                        if (d[h][len][flag] >= mod) d[h][len][flag] -= mod;
                    }
                }
                
                sums[h][len] = sums[h][len - 1] + d[h][len][0];
                if (sums[h][len] >= mod) sums[h][len] -= mod;
                
                sumd[h][len] = (sumd[h][len - 1] + d[h][len][0] * 1LL * (len - 1)) % mod;
            }
    
    fore(len, 2, N - 1)
        forl(h, N - 1)
            forn(flag, 2)
                prefs[len][h][flag] = (prefs[len][h - 1][flag] + d[h][len][flag]) % mod;
}

inline bool read()
{
    return cin >> n >> m;
}

inline void solve()
{
    int ans = 0;
    
    forn(i, n)
        fore(len, 2, m)
        {
            int v1 = prefs[len][i + 1][0];
            int v2 = prefs[len][n - i][1];
            int cur = (v1 * 1LL * v2) % mod;
            cur = (cur * 1LL * (m - len + 1)) % mod;
            ans += cur;
            if (ans >= mod) ans -= mod;
        }
        
    cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    prepare();  
    assert(read());
    solve();
    
    return 0;
}