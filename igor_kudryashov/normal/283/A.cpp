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

const int N = 200 * 1000 + 13;

int n, m;
li a[N];
li add[N];
li sum;

inline bool read()
{
    if (scanf("%d", &m) != 1)
        return false;

    return true;
}

inline void solve()
{
    a[n++] = 0;

    forn(i, m)
    {
        int type;
        assert(scanf("%d", &type) == 1);

        if (type == 1)
        {
            int cnt, x;
            assert(scanf("%d%d", &cnt, &x) == 2);
            sum += cnt * 1LL * x;
            add[cnt - 1] += x;
        } else if (type == 2)
        {
            int v;
            assert(scanf("%d", &v) == 1);
            add[n] = 0;
            a[n++] = v;
            sum += v;
        } else if (type == 3)
        {
            li val = a[n - 1] + add[n - 1];
            add[n - 2] += add[n - 1];
            n--;
            add[n] = 0;
            sum -= val;
        }

        printf("%.10lf\n", double(sum) / n);
    }
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