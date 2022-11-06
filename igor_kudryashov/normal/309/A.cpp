#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for(int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2000 * 1000 + 13;

int n, len, t;
int a[N];

inline bool read()
{
    if (scanf("%d%d%d", &n, &len, &t) != 3)
        return false;

    forn(i, n)
    {
        assert(scanf("%d", &a[i]) == 1);
        a[n + i] = a[i] + len;
    }

    return true;
}

inline int calc (int x2, int x1)
{
    int x = x2 - x1;
    if (2 * t - x < 0) return 0;
    return (2 * t - x) / len + 1;
}

inline void solve()
{
    if (n == 1)
    {
        puts("0");
        return;
    }

    li res = 0;

    forn(i, n)
    {
        int c1 = calc(a[i + 1], a[i]);
        int c2 = calc(a[i + n - 1], a[i]);
        assert(c2 <= c1 && c1 - 1 <= c2);

        //cerr << c1 << endl;

        int lf = i + 1, rg = i + n - 1;
        while (lf != rg)
        {
            int mid = (lf + rg + 1) >> 1;
            int c3 = calc(a[mid], a[i]);
            if (c3 == c1) lf = mid;
            else rg = mid - 1;
        }

        /*cerr << c1 << ' ' << c2 << endl;
        cerr << lf << endl;*/
        res += c1 * 1LL * (lf - i) + c2 * 1LL * (i + n - 1 - lf);
    }

    //cerr << res << endl;

    cout << setprecision(10) << fixed;
    cout << ld(res) / 4.0 << endl;
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif

    assert(read());
    solve();

    return 0;
}