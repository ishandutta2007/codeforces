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

const int maxn = 200500;

int n, mx, d;
pii a[maxn];

void scan() {
    scanf("%d%d%d", &d, &mx, &n);
    forn(i, n) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a, a+n);
}

void solve() {
    int pos = 0;
    int ptr = 0;
    i64 cost = 0;
    set<pii> q; // {cost, pos};
    q.emplace(0,0);

    bool ok = true;
    if (d - a[n-1].fi > mx) {
        ok = false;
    }
    if (a[0].fi > mx) {
        ok = false;
    }
    forn(i, n-1) if (a[i+1].fi - a[i].fi > mx) {
        ok = false;
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }

    while (pos < d) {
        int poi = ptr == n ? d : a[ptr].fi;
        int pid = -1, pcost = -1;
        while (true) {
            assert(!q.empty());
            pid = q.begin()->se;
            if (pos - pid >= mx) {
                q.erase(q.begin());
            } else {
                pcost = q.begin()->fi;
                break;
            }
        }
//         cerr << "pcost = " << pcost << ", len = " << (pos - poi) << endl;
        poi = min(poi, pid + mx);
        cost += (i64)(poi - pos) * pcost;
        pos = poi;

        while (ptr < n && a[ptr].fi <= pos) {
            q.emplace(a[ptr].se, a[ptr].fi);
            ++ptr;
        }
    }

    cout << cost << endl;
}

int main() {
#ifdef HOME
    freopen("c.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}