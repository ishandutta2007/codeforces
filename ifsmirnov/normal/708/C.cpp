#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
// #define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
// #define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;
#define sz(x) int((x).size())

const int maxn = 400500;

struct Mx {
    int a1, a2;
    Mx() : a1(0), a2(0) {}
    void add(int x) {
        if (x >= a1) { a2 = a1; a1 = x; }
        else if (x >= a2) { a2 = x; }
    }

    int get(int but) {
        if (a1 == but) return a2;
        return a1;
    }
};

int n;
vi e[maxn];
int s[maxn], p[maxn];
Mx ms[maxn];
int up[maxn];
int can[maxn];

const int ROOT = 0;

void scan() {
    scanf("%d", &n);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
}

void dfs1(int v, int anc) {
    p[v] = anc;
    if (anc != -1) {
        e[v].erase(find(all(e[v]), anc));
    }

    s[v] = 1;
    for (int to: e[v]) {
        dfs1(to, v);
        s[v] += s[to];
        if (s[to] <= n/2) {
            ms[v].add(s[to]);
        } else {
            ms[v].add(ms[to].get(-1));
        }
    }
}

void dfs2(int v) {
    if (p[v] != -1) {
        int u = p[v];
        int r = n - s[v];
        if (r <= n/2) {
            up[v] = r;
        } else {
            up[v] = max(ms[u].get(s[v]), up[u]);
        }
    }

    bool fail = false;
    int r = n - s[v];
    if (r > n/2) {
        if (r - up[v] <= n/2) {
            fail = false;
        } else {
            fail = true;
        }
    }

    if (!fail) {
        for (int to: e[v]) {
            if (s[to] > n/2) {
                if (s[to] - ms[to].get(-1) <= n/2) {
                    fail = false;
                } else {
                    fail = true;
                    break;
                }
            }
        }
    }

    can[v] = !fail;

    for (int to: e[v]) dfs2(to);
}

void solve() {
    dfs1(ROOT, -1);
    dfs2(ROOT);
    forn(i, n) printf("%d%c", can[i], " \n"[i+1 == n]);
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}