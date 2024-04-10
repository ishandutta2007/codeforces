#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef vector<int> vi;

const int maxn = 100500;

int n, m;
vi e[maxn];
int ts[maxn], tspos;
int b[maxn];
int pos[maxn];
int u[maxn], v[maxn];

void dfs(int v) {
    b[v] = 1;
    for (int to: e[v]) if (!b[to]) {
        dfs(to);
    }
    ts[tspos++] = v;
}

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].push_back(--v);
        ::u[i] = u;
        ::v[i] = v;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scan();
    forn(i, n) if (!b[i]) dfs(i);
    assert(tspos == n);
    reverse(ts, ts+n);
    forn(i, n) pos[ts[i]] = i;
    int need = n-1;
    forn(i, m) {
        int pu = pos[u[i]];
        int pv = pos[v[i]];
        if (pu+1 == pv) --need;
        if (need == 0) {
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}