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

const int N = 100 * 1000 + 3;

int n, a[N];
int next[N][20];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;

    forn(i, n) assert(scanf("%d", &a[i]) == 1);

    return true;
}

void prepare ()
{
    forn(i, 20) next[n][i] = INF;

    ford(i, n)
    {
        forn(j, 20)
            if (a[i] & (1 << j))
                next[i][j] = i;
            else
                next[i][j] = next[i + 1][j];
    }
}

int used[(1 << 20) + 13];

inline void solve()
{
    prepare();

    forn(i, n)
    {
        vector <int> v;
        forn(j, 20) if (next[i][j] != INF) v.pb(next[i][j]);
        sort(all(v));

        used[a[i]] = true;

        int curmask = 0;
        forn(j, sz(v))
        {
            curmask |= a[v[j]];
            used[curmask] = true;
        }
    }

    int ans = 0;
    forn(i, (1 << 20)) ans += used[i];

    cout << ans << endl;
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