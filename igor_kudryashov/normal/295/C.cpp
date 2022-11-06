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

const int mod = 1000 * 1000 * 1000 + 7;
const int N = 50 + 3;

int n, k;
int totc1, totc2;

inline bool read()
{
    if (scanf("%d%d", &n, &k) != 2)
        return false;
        
    k /= 50;
    
    forn(i, n)
    {
        int tmp;
        assert(scanf("%d", &tmp) == 1);
        //if (rand() & 1) tmp = 50; else tmp = 100;
        if (tmp == 50) totc1++; else totc2++;
    }
    
    return true;
}

int d[N][N];

int solve (int c1, int c2)
{
    if (c1 == 0 && c2 == 0) return 0;   
    
    int& ans = d[c1][c2];
    if (ans != -1) return ans;
    
    ans = INF;
    
    forn(gc1, c1 + 1)
    {
        if (gc1 > k) break;
        
        forn(gc2, c2 + 1)
        {
            if (gc1 + 2 * gc2 > k) break;
            
            if (gc1 == c1 && gc2 == c2) return ans = 1;
            
            if (gc1 + gc2 == 1)
            {
                if (gc1 == 1) continue;
                if (totc1 - c1 + gc1 > 0 && k > 0) ans = min(ans, solve(c1 + 1, c2 - 1) + 2);
                
            } else
            {
                if (totc1 - c1 + gc1 > 0 && k > 0) ans = min(ans, solve(c1 - gc1 + 1, c2 - gc2) + 2);
                else if (totc2 - c2 + gc2 > 0 && k > 1) ans = min(ans, solve(c1 - gc1, c2 - gc2 + 1) + 2);
            }
        }
    }
    
    return ans;     
}

int c[N][N];
int z[N][N];

int calc (int c1, int c2)
{
    if (c1 == 0 && c2 == 0) return 1;
    
    int& ans = z[c1][c2];
    if (ans != -1) return ans;
    
    ans = 0;
    
    int ansVal = solve(c1, c2);
    
    forn(gc1, c1 + 1)
    {
        if (gc1 > k) break;
        
        forn(gc2, c2 + 1)
        {
            if (gc1 + 2 * gc2 > k) break;
            
            forn(tc1, totc1 + 1)
            {
                if (tc1 > k) break;
                if (tc1 > totc1 - c1 + gc1) break;
                
                forn(tc2, totc2 + 1)
                {
                    if (tc1 + tc2 * 2 > k) break;
                    if (tc2 > totc2 - c2 + gc2) break;
                    
                    int nc1 = c1 - gc1 + tc1, nc2 = c2 - gc2 + tc2;

                    if (tc1 == 0 && tc2 == 0 && (nc1 > 0 || nc2 > 0)) continue;
                    
                    int cost = (tc1 == 0 && tc2 == 0 ? 1 : 2);
                    
                    int val = solve(nc1, nc2) + cost;
                    assert(val >= ansVal);
                    
                    if (val != ansVal) continue;
                    
                    int t = calc(nc1, nc2);
                    
                    /*cerr << nc1 << ' ' << nc2 << ' ' << t << endl;
                    cerr << c1 << ' ' << gc1 << endl;
                    cerr << c2 << ' ' << gc2 << endl;
                    cerr << totc1 - c1 + gc1 << ' ' << tc1 << endl;
                    cerr << totc2 - c2 + gc2 << ' ' << tc2 << endl;*/
                    
                    t = (t * 1LL * c[c1][gc1]) % mod;
                    t = (t * 1LL * c[c2][gc2]) % mod;
                    t = (t * 1LL * c[totc1 - c1 + gc1][tc1]) % mod;
                    t = (t * 1LL * c[totc2 - c2 + gc2][tc2]) % mod;
                    
                    ans += t;
                    if (ans >= mod) ans -= mod;
                }
            }
        }
    }
    
    return ans;     
}


inline void solve()
{
    memset(d, -1, sizeof(d));
    
    int ans = solve(totc1, totc2);
    
    if (ans > INF / 2)
    {
        puts("-1");
        puts("0");
        return;     
    }
    
    //cerr << ans << endl;
    
    c[0][0] = 1;
    forl(i, N - 1)
        forn(j, i + 1)
            c[i][j] = ((j == 0 ? 0 : c[i - 1][j - 1]) + c[i - 1][j]) % mod;
            
    memset(z, -1, sizeof(z));
    
    int cnt = calc(totc1, totc2);
    
    printf("%d\n%d\n", ans, cnt);   
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}