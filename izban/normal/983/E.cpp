#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

const string FINITE = "Finite";
const string INFINITE = "Infinite";

const int K = 18;
const int N = 1 << K;

int n, m;
int p[N][K];
int h[N];
int a[N], b[N], c[N];
pair<int, int> mn[N];
int p2[N][K];
vector<int> e[N];

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = 0; i < K; i++) if ((h[u] - h[v]) & (1 << i)) u = p[u][i];
    if (u == v) return u;
    for (int i = K - 1; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}


struct segtree {
    int N;
    vector<vector<int>> t;

    segtree() {}
    void init(int n) {
        N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, vector<int>());
    }
    segtree(int n) {
        init(n);
    }

    int get(int v, int x, int y) {
        return upper_bound(t[v].begin(), t[v].end(), y) - lower_bound(t[v].begin(), t[v].end(), x);
    }

    int get(int l, int r, int x, int y) {
        int res = 0;
        l += N;
        r += N;
        while (l <= r) {
            if (l % 2 == 1) res += get(l, x, y);
            if (r % 2 == 0) res += get(r, x, y);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }

    void upd(int x, int y) {
        x += N;
        t[x].push_back(y);
    }

    void srt() {
        for (int i = N; i < 2 * N; i++) {
            sort(t[i].begin(), t[i].end());
        }
        for (int v = N - 1; v >= 1; v--) {
            t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
            merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
        }
    }
};

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    bool first = 1;
    while (scanf("%d", &n) == 1) {
        if (first) first = 0;
        else printf("\n");

        p[0][0] = 0;
        h[0] = 0;
        for (int i = 1; i < n; i++) {
            scanf("%d", &p[i][0]);
            p[i][0]--;
        }

        for (int i = 0; i < n; i++) {
            if (i) h[i] = h[p[i][0]] + 1;
            for (int j = 1; j < K; j++) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }

        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a[i], &b[i]);
            a[i]--; b[i]--;
        }

        for (int i = 0; i < n; i++) {
            mn[i] = make_pair(h[i], i);
        }
        for (int i = 0; i < m; i++) {
            c[i] = lca(a[i], b[i]);
            int w = c[i];
            mn[a[i]] = min(mn[a[i]], make_pair(h[w], w));
            mn[b[i]] = min(mn[b[i]], make_pair(h[w], w));
        }
        for (int i = n - 1; i >= 0; i--) {
            mn[p[i][0]] = min(mn[p[i][0]], mn[i]);
        }

        for (int i = 0; i < n; i++) {
            p2[i][0] = mn[i].second;
            for (int j = 1; j < K; j++) {
                p2[i][j] = p2[p2[i][j - 1]][j - 1];
            }
        }

        for (int i = 0; i < n; i++) e[i].clear();
        for (int i = 1; i < n; i++) e[p[i][0]].push_back(i);


        int tmr = 0;
        vector<int> in(n), out(n);
        function<void(int)> dfs = [&](int v) {
            in[v] = tmr++;
            for (int to : e[v]) {
                dfs(to);
            }
            out[v] = tmr - 1;
        };
        dfs(0);


        segtree tr(n);
        for (int i = 0; i < m; i++) {
            if (in[a[i]] > in[b[i]]) swap(a[i], b[i]);
            if (a[i] == c[i]) continue;
            tr.upd(in[b[i]], in[a[i]]);
        }
        tr.srt();

        int q;
        scanf("%d", &q);
        vector<int> res(q);
        for (int i = 0; i < q; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            int w = lca(u, v);

            int ans = 0;
            for (int i = K - 1; i >= 0; i--) {
                if (h[p2[u][i]] > h[w]) {
                    ans += 1 << i;
                    u = p2[u][i];
                }
                if (h[p2[v][i]] > h[w]) {
                    ans += 1 << i;
                    v = p2[v][i];
                }
            }
            assert(u != v);
            if (!(h[p2[u][0]] <= h[w] && h[p2[v][0]] <= h[w])) {
                ans = -1;
            } else {
                if (in[u] > in[v]) swap(u, v);

                ans += 2;
                if (in[u] <= in[v] && out[v] <= out[u]) {
                    ans -= h[p2[v][0]] <= h[u];
                } else {
                    int cnt = tr.get(in[v], out[v], in[u], out[u]);
                    assert(cnt >= 0);
                    ans -= cnt > 0;
                }
            }
            res[i] = ans;
        }
        for (int i = 0; i < q; i++) printf("%d\n", res[i]);
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}