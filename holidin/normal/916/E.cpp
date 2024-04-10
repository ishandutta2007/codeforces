#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int LogN = 17;

int p[LogN][N], tin[N], tout[N], dp[N], top = 0, v = 1, n, a[N];
long long d[4*N], m[4*N];
vector <int> e[N];

void als(int i, int j) {
    i = i + v - 2;
    m[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[i] += j;
    }
}

void push(int v, int vl, int vr) {
    if (d[v] != 0) {
        d[2*v + 1] += d[v];
        d[2*v + 2] += d[v];
        m[2*v + 1] += d[v] * (vr - vl) / 2;
        m[2*v + 2] += d[v] * (vr - vl) / 2;
        d[v] = 0;
    }
}

void recalc(int v) {
    m[v] = m[2*v + 1] + m[2*v + 2];
}

long long sum(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (vl >= r || l >= vr)
            return 0;
        else {
            push(v, vl, vr);
            return sum(2*v + 1, vl, (vl + vr)/2, l, r) + sum(2*v + 2, (vl + vr)/2, vr, l, r);
        }
}

void add_do(int v, int vl, int vr, int l, int r, long long x) {
    if (l <= vl && vr <= r) {
        m[v] += x * (vr - vl);
        d[v] += x;
    } else if (vl >= r || l >= vr)
            return;
        else {
            push(v, vl, vr);
            add_do(2*v + 1, vl, (vl + vr)/2, l, r, x);
            add_do(2*v + 2, (vl + vr)/2, vr, l, r, x);
            recalc(v);
        }
}

void dfs(int u, int pr, int deep) {
    ++top;
    tin[u] = top;
    p[0][u] = pr;
    dp[u] = deep;
    for (int i = 1; i < LogN; ++i)
        p[i][u] = p[i - 1][p[i - 1][u]];
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        dfs(e[u][i], u, deep + 1);
    tout[u] = top;
}

int lca(int a, int b) {
    if (dp[a] > dp[b])
        swap(a, b);
    for (int i = LogN - 1; i >= 0; --i)
    if (dp[a] <= dp[p[i][b]])
        b = p[i][b];
    if (a == b)
        return a;
    for (int i = LogN - 1; i >= 0; --i)
    if (p[i][a] != p[i][b]) {
        a = p[i][a];
        b = p[i][b];
    }
    return p[0][a];
}

long long sum_tree(int root, int vert) {
    if (root == vert)
        return m[0];
    if (tin[vert] <= tin[root] && tout[root] <= tout[vert]) {
        int x = root;
        for (int i = LogN - 1; i >= 0; --i)
        if (dp[p[i][x]] > dp[vert])
            x = p[i][x];
        return sum(0, 1, v + 1, 1, tin[x]) + sum(0, 1, v + 1, tout[x] + 1, n + 1);
    } else
        return sum(0, 1, v + 1, tin[vert], tout[vert] + 1);
}

void add_tree(int root, int a, int b, long long x) {
    int lp = lca(a, b);
    int ans = lp;
    if (tin[lp] < tin[root] && tout[root] <= tout[lp]) {
        int pl = lca(a, root);
        if (pl != lp)
            ans = pl;
        pl = lca(b, root);
        if (pl != lp)
            ans = pl;
    }
    if (ans == root) {
        add_do(0, 1, v + 1, 1, n + 1, x);
        return;
    }
    if (tin[ans] < tin[root] && tout[root] <= tout[ans]) {
        int vert = root;
        for (int i =  LogN - 1; i >= 0; --i)
        if (dp[ans] < dp[p[i][vert]])
            vert = p[i][vert];
        add_do(0, 1, v + 1, 1, tin[vert], x);
        add_do(0, 1, v + 1, tout[vert] + 1, n + 1, x);
    } else
        add_do(0, 1, v + 1, tin[ans], tout[ans] + 1, x);

}

int main() {
    int i, j, q, i1, a1, b1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i < n; ++i) {
        cin >> a1 >> b1;
        e[a1].push_back(b1);
        e[b1].push_back(a1);
    }
    dfs(1, 1, 0);
    v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i)
        als(tin[i], a[i]);
    int tek = 1;
    for (i = 0; i < q; ++i) {
        int t, x;
        cin >> t;
        if (t == 1)
            cin >> tek;
        if (t == 2) {
            cin >> a1 >> b1 >> x;
            add_tree(tek, a1, b1, x);
        }
        if (t == 3) {
            cin >> a1;
            cout << sum_tree(tek, a1) << "\n";
        }
    }
}