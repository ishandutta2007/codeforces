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

const int N = 2000 * 1000 + 13;

int n;
char s1[N], s2[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;
    n *= 2;
    
    assert(scanf("%s", s1) == 1);
    assert(scanf("%s", s2) == 1);
    
    return true;
}

inline void solve()
{
    int cntSame = 0;
    forn(i, n) cntSame += (s1[i] == '1' && s2[i] == '1');
    int d1 = 0, d2 = 0;
    forn(i, n)
        if (s1[i] > s2[i])
            d1++;
        else if (s1[i] < s2[i])
            d2++;
            
    int c1 = 0, c2 = 0;
    
    if (cntSame % 2 == 0) c1 = c2 = cntSame / 2;
    else
    {
        c1 = (cntSame + 1) / 2;
        c2 = (cntSame - c1);
        if (d2 > 0) c2++, d2--;
        else if (d1 > 0) d1--;
    }
    
    int d = min(d1, d2);
    c1 += d, c2 += d;
    d1 -= d, d2 -= d;
    
    if (d1 > 0) c1 += (d1 + 1) / 2;
    else if (d2 > 0)
    {
        int tmp = (d2 + 1) / 2;
        c2 += d2 - tmp;
    }
    
    if (c1 > c2)
        puts("First");
    else if (c1 < c2)
        puts("Second");
    else
        puts("Draw");
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