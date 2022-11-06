#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 3e5 + 10;
pair<vector<int>, int> e[N];
int id[N];
set<int> p[N];

void fail() {
    printf("NO\n");
    exit(0);
}

void easy(int n) {
    printf("YES\n");
    forn(i, 0, n) printf("%d ", 1);
    exit(0);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    forn(i, 0, n) e[i].sn = i;
    forn(i, 0, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        e[u].fs.eb(v);
        e[v].fs.eb(u);
    }
    forn(i, 0, n) e[i].fs.eb(i);
    forn(i, 0, n) sort(all(e[i].fs));
    sort(e, e + n);
    int ix = 0;
    id[e[0].sn] = 0;
    forn(i, 1, n) {
        if (e[i].fs != e[i - 1].fs) ++ix;
        id[e[i].sn] = ix;
    }
    if (ix == 0) easy(n);
    forn(i, 0, n) {
        for (int j : e[i].fs) {
            int u = id[e[i].sn], v = id[j];
            if (u != v) {
                p[u].insert(v);
                p[v].insert(u);
            }
        }
    }
    vector<int> color(ix + 1, -1);
    int st = -1;
    forn(i, 0, ix + 1) {
        if (p[i].size() > 2) fail();
        if (p[i].size() == 1) st = i;
    }
    if (st == -1) fail();
    int prev = -1;
    for (int i = 0; ; ++i) {
        color[st] = i;
        int nxt = -1;
        for (int j : p[st]) {
            if (j != prev) {
                nxt = j;
            }
        }
        if (nxt == -1) break;
        else {
            prev = st;
            st = nxt;
        }
    }
    forn(i, 0, ix + 1)
        if (color[i] == -1)
            fail();
    printf("YES\n");
    forn(i, 0, n) printf("%d ", 1 + color[id[i]]);
}