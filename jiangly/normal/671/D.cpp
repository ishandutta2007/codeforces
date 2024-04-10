#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 1E15;
constexpr int M = 1 << 20;
struct Node {
    LL mn, lazy;
} t[M];
void build(int p, int l, int r) {
    t[p].mn = INF;
    if (r - l == 1)
        return;
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid, r);
}
void pushdown(int p) {
    t[2 * p].mn = min(INF, t[2 * p].mn + t[p].lazy);
    t[2 * p].lazy = min(INF, t[2 * p].lazy + t[p].lazy);
    t[2 * p + 1].mn = min(INF, t[2 * p + 1].mn + t[p].lazy);
    t[2 * p + 1].lazy = min(INF, t[2 * p + 1].lazy + t[p].lazy);
    t[p].lazy = 0;
}
void pushup(int p) {t[p].mn = min(t[2 * p].mn, t[2 * p + 1].mn);}
void modify(int p, int l, int r, int x, LL v) {
    if (r - l == 1) {
        t[p].mn = v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(p);
    if (x < mid)
        modify(2 * p, l, mid, x, v);
    else
        modify(2 * p + 1, mid, r, x, v);
    pushup(p);
}
void rangeAdd(int p, int l, int r, int x, int y, LL v) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y) {
        t[p].mn = min(INF, t[p].mn + v);
        t[p].lazy = min(INF, t[p].lazy + v);
        return;
    }
    int mid = (l + r) / 2;
    pushdown(p);
    rangeAdd(2 * p, l, mid, x, y, v);
    rangeAdd(2 * p + 1, mid, r, x, y, v);
    pushup(p);
}
LL rangeMin(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x)
        return INF;
    if (l >= x && r <= y)
        return t[p].mn;
    int mid = (l + r) / 2;
    pushdown(p);
    return min(rangeMin(2 * p, l, mid, x, y), rangeMin(2 * p + 1, mid, r, x, y));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    build(1, 0, m);
    vector<vector<int>> e(n), add(n), del(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        e[--u].push_back(--v);
        e[v].push_back(u);
    }
    vector<int> in(n), out(n);
    int dfs_now = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        in[u] = dfs_now++;
        for (int v : e[u])
            if (v != p)
                dfs(v, u);
        out[u] = dfs_now;
    };
    dfs(0, -1);
    vector<tuple<int, int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        q[i] = {--u, --v, c};
    }
    sort(q.begin(), q.end(), [&](const tuple<int, int, int> &i, const tuple<int, int, int> &j) {return in[get<0>(i)] < in[get<0>(j)];});
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        tie(u, v, c) = q[i];
        add[u].push_back(i);
        del[v].push_back(i);
    }
    vector<LL> dp(n);
    vector<int> st(n + 1);
    for (int i = 0, j = 0; i <= n; ++i) {
        while (j < m && in[get<0>(q[j])] < i)
            ++j;
        st[i] = j;
    }
    function<void(int, int)> solve = [&](int u, int p) {
        LL sum = 0;
        for (int v : e[u]) {
            if (v == p)
                continue;
            solve(v, u);
            sum = min(INF, sum + dp[v]);
        }
        if (u == 0) {
            dp[u] = sum;
            return;
        }
        for (int i : add[u])
            modify(1, 0, m, i, min(INF, get<2>(q[i]) + sum));
        for (int i : del[u])
            modify(1, 0, m, i, INF);
        for (int v : e[u])
            if (v != p)
                rangeAdd(1, 0, m, st[in[v]], st[out[v]], sum - dp[v]);
        dp[u] = rangeMin(1, 0, m, st[in[u]], st[out[u]]);
    };
    solve(0, -1);
    if (dp[0] == INF)
        cout << -1 << "\n";
    else
        cout << dp[0] << "\n";
    return 0;
}