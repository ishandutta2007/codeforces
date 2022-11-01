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

const int maxn = 400500;

int n, m;

int c[maxn];

set<pii> cur;

pair<pii, int> q[maxn];
vector<pair<int, pii> >ev; // x, (type, id), 0=in, -1=out
int res[maxn];
int r[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", &q[i].fi.fi, &q[i].fi.se);
        q[i].se = i;
    }
    sort(q, q+n);
}

void solve() {
    scanf("%d", &m);
    forn(i, m) {
        int l, r;
        scanf("%d%d%d", &l, &r, &c[i]);
        ::r[i] = r;
        ev.pb(mp(l, mp(0, i)));
        ev.pb(mp(r+1, mp(1, i)));
    }

    sort(all(ev));

    int pos = 0;
    forn(i, n) {
        while (pos < 2 * m && ev[pos].fi <= q[i].fi.fi) {
            int id = ev[pos].se.se;
            if (ev[pos].se.fi == 0) {
//                 cout << "imsert " << id << endl;
                cur.insert(mp(r[id], id));
            } else {
//                 cout << "erase " << id << endl;
                cur.erase(mp(r[id], id)); // useless
            }
            ++pos;
        }
        int rb = q[i].fi.se;
        auto it = cur.lower_bound(mp(rb, -1));
//         cout << "q = " << q[i].fi.fi << " " << q[i].fi.se << endl;
        if (it == cur.end()) {
            printf("NO\n");
            return;
        }
        pii t = *it;
        res[q[i].se] = t.se;
//         cout << "ass " << " " << t.se << endl;

        if (!--c[t.se]) {
            cur.erase(it);
        }
    }
    printf("YES\n");
    forn(i, n) printf("%d ", res[i]+1);
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