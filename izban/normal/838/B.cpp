#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1e9;

const int K = 18;
const int N = 1 << K;

ll a[N];
ll t[N * 2];
ll p[N * 2];

void build(int v, int tl, int tr) {
    p[v] = 0;
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void push(int v, int tl, int tr) {
    if (p[v] == 0) return;
    if (tl != tr) {
        p[v * 2] += p[v];
        p[v * 2 + 1] += p[v];
    }
    t[v] += p[v];
    p[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if (l > r) return;
    if (l == tl && r == tr) {
        p[v] = x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    add(v * 2, tl, tm, l, min(r, tm), x);
    add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

ll get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r) return 1e18;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) >> 1;
    return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int n, q;
vector<pair<int, int> > e[N];
int in[N], out[N], tmr;
int toRoot[N], toPar[N];

void dfs1(int v, ll cdist) {
    in[v] = tmr++;
    a[in[v]] = cdist + toRoot[v];
    for (auto o : e[v]) {
        int to = o.first;
        toPar[to] = o.second;
        dfs1(to, cdist + o.second);
    }
    out[v] = tmr;
}

bool isParent(int x, int y) {
    return in[x] <= in[y] && out[y] <= out[x];
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &q) == 2) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }

        vector<int> u(2 * n - 2), v(2 * n - 2), w(2 * n - 2);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            --u[i]; --v[i];
            e[u[i]].push_back({v[i], w[i]});
        }
        for (int i = n - 1; i < 2 * (n - 1); i++) {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            --u[i]; --v[i];
            assert(v[i] == 0);
            toRoot[u[i]] = w[i];
        }
        tmr = 0;

        dfs1(0, 0);
        build(1, 0, n - 1);

        for (int i = 0; i < q; i++) {
            int t;
            scanf("%d", &t);
            if (t == 1) {
                int id, w;
                scanf("%d%d", &id, &w);
                id--;
                if (id < n - 1) {
                    int cur = v[id];
                    add(1, 0, n - 1, in[cur], out[cur] - 1, -toPar[cur]);
                    toPar[cur] = w;
                    add(1, 0, n - 1, in[cur], out[cur] - 1, toPar[cur]);
                } else {
                    int cur = u[id];
                    add(1, 0, n - 1, in[cur], in[cur], -toRoot[cur]);
                    toRoot[cur] = w;
                    add(1, 0, n - 1, in[cur], in[cur], toRoot[cur]);
                }
            }
            if (t == 2) {
                int x, y;
                scanf("%d%d", &x, &y);
                --x; --y;
                ll ans = 0;
                if (isParent(x, y)) {
                    ans += get(1, 0, n - 1, in[y], in[y]) - toRoot[y];
                    ans -= get(1, 0, n - 1, in[x], in[x]) - toRoot[x];
                } else {
                    ans += get(1, 0, n - 1, in[x], out[x] - 1) - (get(1, 0, n - 1, in[x], in[x]) - toRoot[x]);
                    ans += get(1, 0, n - 1, in[y], in[y]) - toRoot[y];
                }
                printf("%lld\n", ans);
            }
        }
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}