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
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 5000 + 3;

int n;
int a[N];
int d[N][N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;

    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    
    return true;
}

inline void solve()
{
    memset(d, 63, sizeof(d));
    
    forn(lf, n)
    {
        int sumRg = a[lf];
        int prev = lf - 1;
        int sumLf = (prev < 0 ? 0 : a[prev]);
        int minv = (prev < 0 ? 0 : d[prev][lf]);
        
        fore(rg, lf + 1, n)
        {
            while (prev > 0 && sumLf + a[prev - 1] <= sumRg) sumLf += a[prev - 1], minv = min(minv, d[prev - 1][lf]), prev--;
            if (sumLf <= sumRg) d[lf][rg] = min(d[lf][rg], minv + (rg - lf - 1));
            sumRg += a[rg];
            //cerr << lf << ' ' << rg << ' ' << sumLf << ' ' << sumRg << endl;
        }
    }
    
    /*forn(i, n)
    {
        fore(j, i + 1, n)
            cerr << d[i][j] << ' ';
        cerr << endl;
    }*/
    
    int ans = INF;
    
    forn(i, n) ans = min(ans, d[i][n]);
    
    cout << ans << endl;
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