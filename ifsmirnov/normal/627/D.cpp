#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <random>
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

int n, lim;
vi e[maxn];
int pr[maxn];
int lbl[maxn];
int ROOT = 0;

void scan() {
    scanf("%d%d", &n, &lim);
    forn(i, n) scanf("%d", &lbl[i]);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
}

struct Max {
    pii v1, v2;
    Max() : v1(-inf, -inf), v2(-inf, -inf) {}
    void add(int x, int v) {
        if (x > v1.fi) { v2 = v1; v1 = {x, v}; }
        else if (x > v2.fi) { v2 = {x, v}; }
    }
    int max() const { return v1.fi; }
    int max(int v) const {
        if (v1.se == v) return v2.fi;
        return v1.fi;
    }
};

int s[maxn];
int fd[maxn], fu[maxn]; // full, bool
int sf[maxn]; // sum full
int dd[maxn], du[maxn]; // overall ans
Max mx[maxn];
int mu[maxn];

int M;
int maxtake;

void dfs1(int v, int u) {
    s[v] = 1;
    fd[v] = lbl[v] >= M;
    mx[v] = Max();
    dd[v] = 0;
    sf[v] = 0;

    for (int to: e[v]) if (to != u) {
        dfs1(to, v);
        s[v] += s[to];
        if (fd[to]) {
            sf[v] += s[to];
        } else {
            fd[v] = false;
            mx[v].add(dd[to], to);
        }
    }

    if (lbl[v] >= M) {
        if (fd[v]) {
            dd[v] = s[v];
        } else {
            dd[v] = sf[v] + mx[v].max() + 1;
        }
    } else {
        mx[v] = Max();
        sf[v] = 0;
        dd[v] = 0;
    }

//     cerr << v << ": " << dd[v] << " " << sf[v] << endl;
}

void dfs2(int v, int u) {
    if (u == -1) {
        fu[v] = true;
        du[v] = 0;
        mu[v] = 0;
    } else if (lbl[u] < M) {
        fu[v] = false;
        du[v] = 0;
        mu[v] = 0;
    } else {
        int sfu = sf[u];
        if (fu[u]) sfu += n - s[u];
        if (fd[v]) sfu -= s[v];
        ++sfu; // for u itself

        if (sfu == n - s[v]) {
            fu[v] = 1;
        } else {
            fu[v] = 0;
            int best = mx[u].max(v);
            if (!fu[u]) {
                best = max(best, mu[u]);
            }
            assert(best != -inf);
            mu[v] = sfu + best;
        }
    }

    if (lbl[v] >= M) {
        int take = sf[v];
        int add = mx[v].max();
        if (fu[v]) {
            take += n - s[v];
        } else {
            add = max(add, mu[v]);
        }
        add = max(add, 0);
        maxtake = max(maxtake, take + add + 1);
    }

//     cerr << v << ": " << mu[v] << endl;

    for (int to: e[v]) if (to != u) {
        dfs2(to, v);
    }
}

void solve() {
//     ROOT = random_device{}() % n;
    int l = 0, r = 1000001;
    while (r-l > 1) {
        int m = (l+r) / 2;
        M = m;
        maxtake = 0;
        dfs1(ROOT, -1);
        dfs2(ROOT, -1);
        if (maxtake >= lim) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;
}

int main() {
#ifdef HOME
    freopen("d.in", "r", stdin);
#endif

    scan();

    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}