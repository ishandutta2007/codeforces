#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int mod = 1000000007;
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
inline int mul(i64 x, i64 y) { return x*y%mod; }

const int maxn = 202;
const int maxs = 1010;

int n;
int T;
int a[maxn];

int d[maxn][maxn][maxs+maxn];

void scan() {
    scanf("%d%d", &n, &T);
    forn(i, n) scanf("%d", &a[i]);
    sort(a, a+n);
}

void relax(int &x, int y) {
    x = add(x, y);
}

void solve() {
    memset(d, 0, sizeof d);
    d[0][0][0] = 1;
    forn(i, n) {
        int cost = i == n-1 ? 10000 : (a[i+1] - a[i]);
        for (int k = 0; k <= i; ++k) {
            forn(t, maxs + maxn) {
                if (!d[i][k][t]) continue;

                // join to any existing group or create its own and immediately close it
                if (t + k * cost < maxs + maxn) {
                    relax(d[i+1][k][t+k*cost], mul(d[i][k][t], k + 1));
                }

                // create new group
                if (t + (k + 1) * cost < maxs + maxn) {
                    relax(d[i+1][k+1][t+(k+1)*cost], d[i][k][t]);
                }

                // erase existing group
                if (k && t + (k - 1) * cost < maxs + maxn) {
                    relax(d[i+1][k-1][t+(k-1)*cost], mul(d[i][k][t], k));
                }
            }
        }
    }

    int res = 0;
    forn(i, T+1) {
        res = add(res, d[n][0][i]);
    }

    cout << res << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}