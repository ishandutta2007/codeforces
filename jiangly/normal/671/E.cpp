#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 1E18;
int n, k, ans;
vector<int> w, g, nxt, stk;
vector<LL> pre, suf;
vector<vector<int>> e;
struct Node {
    LL minp, ans, mx, lazy;
    Node() : minp(0), ans(0), mx(0), lazy(0) {}
};
vector<Node> t;
void add(int p, LL v) {
    t[p].mx += v;
    t[p].lazy += v;
    t[p].ans += v;
}
void pushdown(int p) {
    add(2 * p, t[p].lazy);
    add(2 * p + 1, t[p].lazy);
    t[p].lazy = 0;
}
LL solve(int p, int l, int r, LL tmp) {
    if (r - l == 1)
        return tmp + t[p].minp;
    int mid = (l + r) / 2;
    pushdown(p);
    if (t[2 * p].mx >= tmp)
        return min(t[p].ans, solve(2 * p, l, mid, tmp));
    else
        return min(t[2 * p].minp + tmp, solve(2 * p + 1, mid, r, tmp));
}
void pushup(int p, int l, int r) {
    t[p].mx = max(t[2 * p].mx, t[2 * p + 1].mx);
    int mid = (l + r) / 2;
    t[p].ans = solve(2 * p + 1, mid, r, t[2 * p].mx);
}
void build(int p, int l, int r) {
    if (r - l == 1) {
        t[p].mx = suf[l];
        t[p].minp = -suf[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid, r);
    t[p].minp = min(t[2 * p].minp, t[2 * p + 1].minp);
    pushup(p, l, r);
}
void rangeAdd(int p, int l, int r, int x, int y, LL v) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y) {
        add(p, v);
        return;
    }
    int mid = (l + r) / 2;
    pushdown(p);
    rangeAdd(2 * p, l, mid, x, y, v);
    rangeAdd(2 * p + 1, mid, r, x, y, v);
    pushup(p, l, r);
}
int rightMost(int p, int l, int r, LL v) {
    if (r - l == 1)
        return t[p].minp <= v ? l : -1;
    int mid = (l + r) / 2;
    pushdown(p);
    if (t[2 * p + 1].minp <= v)
        return rightMost(2 * p + 1, mid, r, v);
    return rightMost(2 * p, l, mid, v);
}
int query(int p, int l, int r, LL tmp) {
    if (r - l == 1)
        return t[p].minp + tmp <= k ? l : -1;
    int mid = (l + r) / 2;
    pushdown(p);
    if (t[2 * p].mx >= tmp) {
        if (t[p].ans <= k)
            return query(2 * p + 1, mid, r, t[2 * p].mx);
        else
            return query(2 * p, l, mid, tmp);
    } else {
        return max(rightMost(2 * p, l, mid, k - tmp), query(2 * p + 1, mid, r, tmp));
    }
}
void dfs(int u) {
    stk.push_back(u);
    if (nxt[u] != n)
        rangeAdd(1, 0, n, nxt[u] - 1, n, pre[u] - pre[nxt[u]]);
    if (u != n) {
        int l = 1, r = stk.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (pre[u] - pre[stk[mid]] <= k)
                r = mid;
            else
                l = mid + 1;
        }
        l = u;
        r = stk[r - 1];
        rangeAdd(1, 0, n, 0, l, -INF);
        rangeAdd(1, 0, n, r - 1, n, INF);
        LL tmp = -INF;
        ans = max(ans, query(1, 0, n, tmp) - u + 1);
        rangeAdd(1, 0, n, 0, l, INF);
        rangeAdd(1, 0, n, r - 1, n, -INF);
    }
    for (int v : e[u])
        dfs(v);
    if (nxt[u] != n)
        rangeAdd(1, 0, n, nxt[u] - 1, n, pre[nxt[u]] - pre[u]);
    stk.pop_back();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    w.resize(n - 1);
    g.resize(n);
    nxt.resize(n + 1);
    pre.resize(n + 1);
    suf.resize(n);
    e.resize(n + 1);
    t.resize(4 * n);
    for (int i = 0; i < n - 1; ++i)
        cin >> w[i];
    for (int i = 0; i < n; ++i)
        cin >> g[i];
    for (int i = 1; i < n; ++i)
        pre[i] = pre[i - 1] + g[i - 1] - w[i - 1];
    for (int i = 1; i < n; ++i)
        suf[i] = suf[i - 1] + g[i] - w[i - 1];
    stk.push_back(n);
    pre[n] = -INF;
    nxt[n] = n;
    for (int i = n - 1; i >= 0; --i) {
        while (pre[i] <= pre[stk.back()])
            stk.pop_back();
        nxt[i] = stk.back();
        e[nxt[i]].push_back(i);
        stk.push_back(i);
    }
    stk.clear();
    build(1, 0, n);
    dfs(n);
    cout << ans << endl;
    return 0;
}