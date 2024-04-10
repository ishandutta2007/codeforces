#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
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
typedef double ld;
const int maxn = 200500;

int n, m, k;
vi e[maxn];
int q[maxn], d[maxn], deg[maxn], all[maxn], b[maxn];
vi bad;

void scan() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, k) {
        int x;
        scanf("%d", &x);
        bad.pb(x-1);
    }

    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
}

bool run(double t) {
    forn(i, n) {
        deg[i] = e[i].size();
        all[i] = ceil(deg[i] * t);
        b[i] = 0;
    }

//     forn(i, n) cout << all[i] << " "; cout << endl;

    int cnt = n;
    int lq = 0, rq = 0;
    for (auto v: bad) {
        b[v] = 1;
        q[rq++] = v;
        --cnt;
    }

    while (lq != rq) {
        int v = q[lq++];
//         cout << "v = " << v << endl;
        for (auto to: e[v]) if (!b[to]) {
            if (--deg[to] < all[to]) {
                q[rq++] = to;
                b[to] = 1;
                --cnt;
            }
//             cout << "new deg for " << to << " = " << deg[to] << endl;
        }
    }

//     forn(i, n) if (!b[i]) cout << i << " "; cout << endl;

    return cnt > 0;
}

void solve() {
    ld l = 0, r = 1, m;
    forn(i, 120) {
        m = (l+r)/2;
        if (run(m)) {
            l = m;
        } else {
            r = m;
        }
    }

//     assert(run(l));
    run(l);

    printf("%d\n", (int)count(b, b+n, 0));
    forn(i, n) if (!b[i]) {
        printf("%d ", i+1);
    }
    printf("\n");
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