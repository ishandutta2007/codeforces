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

const int N = 100 * 1000 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
char s1[N], s2[N];
int d[N][4];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
        
    assert(scanf("%s%s", s1, s2) == 2);
    
    return true;
}

inline void solve()
{
    d[0][0] = 1;
    
    forn(i, n)
        forn(mask, 4)
        {
            const int& dv = d[i][mask];
            
            forn(d1, 10)
            forn(d2, 10)
            {
                if (s1[i] != '?' && s1[i] != '0' + d1) continue;
                if (s2[i] != '?' && s2[i] != '0' + d2) continue;
                
                int nmask = mask;
                if (d1 > d2) nmask |= 1; else if (d1 < d2) nmask |= 2;
                
                d[i + 1][nmask] += dv;
                if (d[i + 1][nmask] >= mod) d[i + 1][nmask] -= mod;
            }
        }
        
    cout << d[n][3] << endl;
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