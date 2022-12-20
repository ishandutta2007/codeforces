#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int CS = 3e5 + 1;
const int inf = 1e9;

struct edge {
    int b, c, w, pa, pi, f;
};

vector <edge> e[N];
vector <int> v1[N], v2[N];
int d[N], pr[N], jpr[N], c1[N], c2[N], n, sum[N], f[N];

void clear_all(int n) {
    int i;
    for (i = 0; i <= n; ++i) {
        e[i].clear();
        v1[i].clear();
        v2[i].clear();
    }
}

void add_edge(int a, int b, int c, int w) {
    e[a].push_back({b, c, w, b, e[b].size(), 0});
    e[b].push_back({a, 0, -w, a, e[a].size() - 1, 0});
}

void MCMF(int ist, int st, int n) {
    int i, j, cnt = 0;
    while (true) {
        for (i = 0; i <= n; ++i)
            d[i] = inf;
        d[ist] = 0;
        while (true) {
            bool flag = false;
            for (i = 0; i <= n; ++i)
            for (j = 0; j < e[i].size(); ++j)
            if (e[i][j].f < e[i][j].c && d[e[i][j].b] > d[i] + e[i][j].w) {
                d[e[i][j].b] = d[i] + e[i][j].w;
                pr[e[i][j].b] = i;
                jpr[e[i][j].b] = j;
                flag = true;
            }
            if (!flag)
                break;
        }
        if (d[st] >= inf / 2)
            break;
        int u = st;
        while (u != ist) {
            int u1 = pr[u], j1 = jpr[u];
            ++e[u1][j1].f;
            --e[e[u1][j1].pa][e[u1][j1].pi].f;
            u = u1;
        }
    }
}

void dfs1(int u, int pr, int t) {
    sum[u] = 0;
    if (c1[u] != inf)
        add_edge(t, u, c1[u], 0);
    else
        add_edge(t + 2 * n, u, c1[u], 0);
    for (int i = 0; i < v1[u].size(); ++i)
    if (v1[u][i] != pr) {
        if (c1[u] == inf)
            dfs1(v1[u][i], u, t);
        else
            dfs1(v1[u][i], u, u);
        sum[u] += sum[v1[u][i]];
    }
    add_edge(u, u + 2 * n, c1[u] - sum[u], 0);
    if (c1[u] < sum[u]) {
        cout << -1;
        exit(0);
    }
    add_edge(u + 2 * n, u + 3 * n, 1, f[u]);
    if (c1[u] != inf)
        sum[u] = c1[u];
}

void dfs2(int u, int pr, int t) {
    sum[u] = 0;
    if (c2[u] != inf)
        add_edge(u + n, t + n, c2[u], 0);
    else
        add_edge(u + n, t + 3 * n, c2[u], 0);
    for (int i = 0; i < v2[u].size(); ++i)
    if (v2[u][i] != pr) {
        if (c2[u] == inf)
            dfs2(v2[u][i], u, t);
        else
            dfs2(v2[u][i], u, u);
        sum[u] += sum[v2[u][i]];
    }
    add_edge(u + 3 * n, u + n, c2[u] - sum[u], 0);
    if (c2[u] < sum[u]) {
        cout << -1;
        exit(0);
    }
    if (c2[u] != inf)
        sum[u] = c2[u];
}

int main() {
    int i, j, x, y, k, q1, q2, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    int ist = 0, st = 4*n + 1;
    for (i = 1; i <= n; ++i) {
        cin >> f[i];
        f[i] = CS - f[i];
    }
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        v1[a].push_back(b);
        v1[b].push_back(a);
    }
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        v2[a].push_back(b);
        v2[b].push_back(a);
    }
    for (i = 1; i <= n; ++i) {
        c1[i] = inf;
        c2[i] = inf;
    }
    cin >> q1;
    for (i = 1; i <= q1; ++i) {
        cin >> a >> b;
        c1[a] = b;
    }
    cin >> q2;
    for (i = 1; i <= q2; ++i) {
        cin >> a >> b;
        c2[a] = b;
    }
    dfs1(x, 0, 0);
    dfs2(y, 3 * n + 1, 3 * n + 1);
    MCMF(ist, st, 4*n + 1);
    long long ans = 0;
    for (i = 0; i <= 4*n + 1; ++i)
    for (j = 0; j < e[i].size(); ++j)
    if (e[i][j].c != inf && e[i][j].w == 0 && e[i][j].c > 0 &&  e[i][j].f != e[i][j].c && abs(i - e[i][j].b) <= n) {
        cout << -1;
        return 0;
    } else if (e[i][j].w > 0 && e[i][j].f > 0)
            ans += CS - e[i][j].w;
    cout << ans;
}