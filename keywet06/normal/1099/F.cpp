#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    struct node {
        int s, e;
        long long cnt, sm;
    };
    vector<node> T;

    SegTree(int n) : T(n << 2) { build(1, 1, n); }

    void build(int i, int s, int e) {
        T[i] = {s, e, 0, 0};
        if (s == e) return;
        int m = (s + e) >> 1;
        build(i << 1, s, m);
        build(i << 1 | 1, m + 1, e);
    }

    void update(int i, int j, int x) {
        if (j < T[i].s || T[i].e < j) return;
        if (T[i].s == T[i].e) {
            T[i].cnt += x;
            T[i].sm = T[i].cnt * T[i].s;
            return;
        }
        update(i << 1, j, x);
        update(i << 1 | 1, j, x);
        T[i].cnt = T[i << 1].cnt + T[i << 1 | 1].cnt;
        T[i].sm = T[i << 1].sm + T[i << 1 | 1].sm;
    }

    long long query(int i, long long t) {
        if (t <= 0) return 0;
        if (T[i].s == T[i].e) return min(T[i].cnt, t / T[i].s);
        long long lt = T[i << 1].sm;
        if (t <= lt) return query(i << 1, t);
        return T[i << 1].cnt + query(i << 1 | 1, t - lt);
    }
};

const long long INF = 1e15;
const int N = 2e5;
const int M = 1e6 + 5;

int n, x[N], t[N];

long long T;
long long d[N], best[N], dp[N];

vector<array<int, 2>> g[N];

SegTree st(M);

void dfs(int u) {
    st.update(1, t[u], x[u]);
    best[u] = st.query(1, T - 2 * d[u]);
    for (auto &vw : g[u]) {
        d[vw[0]] = d[u] + vw[1];
        dfs(vw[0]);
    }
    long long mx = best[u], mx2 = best[u];
    for (auto &vw : g[u]) {
        long long sub = dp[vw[0]];
        if (sub > mx)
            mx2 = mx, mx = sub;
        else if (sub > mx2)
            mx2 = sub;
    }
    dp[u] = mx2;
    st.update(1, t[u], -x[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 2; i <= n; i++) {
        int p, w;
        cin >> p >> w;
        g[p].push_back({i, w});
    }

    dfs(1);

    long long ans = best[1];
    for (auto &vw : g[1]) ans = max(ans, dp[vw[0]]);
    cout << ans << "\n";

    return 0;
}