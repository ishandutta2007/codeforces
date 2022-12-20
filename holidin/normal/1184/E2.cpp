#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;
const int sN = 1e5 + 1;
const int LogN = 20;
const int inf = 2e9;

int h[N], m[4 * N] ,ans[N];
int d[N], a[N], b[N], c[N], pr[N], v;
int p[LogN][sN];
int t[LogN];
bool use[N];
set <pair<int, int> > s;
vector <pair<int, int> > e[sN];

void als(int i, int j) {
    i += v - 2;
    m[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[i] = max(m[2*i + 1], m[2*i + 2]);
    }
}

int mx(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (l >= vr || vl >= r)
            return 0;
        else
            return max(mx(2*v + 1, vl, (vl + vr) >> 1, l, r), mx(2*v + 2, (vl + vr) >> 1, vr, l, r));
}

void dfs0(int u, int pr, int deep) {
    h[u] = deep;
    p[0][u] = pr;
    for (int i = 1; i < LogN; ++i)
        p[i][u] = p[i - 1][p[i - 1][u]];
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr && use[e[u][i].se])
        dfs0(e[u][i].fi, u, deep + 1);
}

int lca(int a, int b) {
    if (h[a] < h[b])
        swap(a, b);
    for (int i = LogN - 1; i >= 0; --i)
    if (h[a] - h[b] >= t[i])
        a = p[i][a];
    if (a == b)
        return a;
    for (int i = LogN - 1; i >= 0; --i)
    if (p[i][a] != p[i][b]) {
        a = p[i][a];
        b = p[i][b];
    }
    return p[0][a];
}

void dfs(int u, int pr) {
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr && use[e[u][i].se]) {
        als(h[u], c[e[u][i].se]);
        dfs(e[u][i].fi, u);
    }
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr && !use[e[u][i].se]) {
        int t = e[u][i].se;
        ans[e[u][i].se] = max(ans[e[u][i].se], mx(0, 1, v + 1, h[lca(a[t], b[t])], h[u]));
    }
}

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    cin >> n >> k;
    v = 1;
    while (v < n) v *= 2;
    for (i = 0; i < k; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        e[a[i]].push_back({b[i], i});
        e[b[i]].push_back({a[i], i});
    }
    for (i = 2; i <= n; ++i) {
        d[i] = inf;
        s.insert({d[i], i});
    }
    pr[1] = N - 1;
    d[1] = 0;
    s.insert({0, 1});
    while (s.size() > 0) {
        pair <int, int> p = *s.lower_bound({0, 0});
        s.erase(p);
        int u = p.se;
        use[pr[u]] = 1;
        for (i = 0; i < e[u].size(); ++i)
        if (d[e[u][i].fi] > c[e[u][i].se]) {
            pr[e[u][i].fi] = e[u][i].se;
            s.erase({d[e[u][i].fi], e[u][i].fi});
            d[e[u][i].fi] = c[e[u][i].se];
            s.insert({d[e[u][i].fi], e[u][i].fi});
        }
    }
    dfs0(1, 1, 1);
    dfs(1, 1);
    for (i = 0; i < k; ++i)
    if (!use[i])
        cout << ans[i] << "\n";
}