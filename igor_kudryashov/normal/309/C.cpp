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

const int N = 1000 * 1000 + 13;

int n, m;
int a[N];
int cnt[40];
int curcnt[40];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;

    forn(i, n) assert(scanf("%d", &a[i]) == 1);

    forn(i, m)
    {
        int tmp;
        assert(scanf("%d", &tmp) == 1);
        cnt[tmp]++;
    }

    return true;
}

bool can (int mid)
{
    int total = 0;

    forn(i, 30)
    {
        int now = min(cnt[i], mid - total);
        curcnt[i] = now;
        total += now;
    }

    forn(i, n)
    {
        int tmp = a[i];

        ford(j, 30)
        {
            while (curcnt[j] > 0 && tmp >= (1 << j)) tmp -= (1 << j), curcnt[j]--;
            if (tmp == 0) break;
        }
    }

    forn(i, 30) if (curcnt[i] > 0) return false;
    return true;
}

inline void solve()
{
    sort(a, a + n);

    int lf = 0, rg = m;
    while (lf != rg)
    {
        int mid = (lf + rg + 1) >> 1;
        if (can(mid))
            lf = mid;
        else
            rg = mid - 1;
    }
    printf("%d\n", lf);
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