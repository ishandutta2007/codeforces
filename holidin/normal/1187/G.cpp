#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 1;
const int LN = 2e6 + 1;
const int inf = 1e9;

struct edge {
    int a, b, cost, c, f, p;
};

edge w[LN];
int pr[N], top;
vector <int> e[N];
long long d[N], P[N];

void add_edge(int a, int b, int c, int cost) {
    ++top;
    w[top].a = a;
    w[top].b = b;
    w[top].c = c;
    w[top].cost = cost;
    w[top].f = 0;
    w[top].p = top + 1;
    e[a].push_back(top);
    ++top;
    w[top].a = b;
    w[top].b = a;
    w[top].c = 0;
    w[top].cost = -cost;
    w[top].f = 0;
    w[top].p = top - 1;
    e[b].push_back(top);
}


void FB(int ist, int st) {
    for (int i = 0; i <= st; ++i)
        d[i] = inf;
    d[0] = 0;
    for (int i = 0; i <= st; ++i)
    for (int u = 0; u <= st; ++u)
    for (int j = 0; j < e[u].size(); ++j)
    if (d[w[e[u][j]].b] > d[u] + w[e[u][j]].cost && w[e[u][j]].f < w[e[u][j]].c) {
        d[w[e[u][j]].b] = d[u] + w[e[u][j]].cost;
        pr[w[e[u][j]].b] = e[u][j];
    }
}

void DKSTR(int ist, int st) {
    set <pair<int, int> > s;
    for (int i = 0; i <= st; ++i)
        d[i] = inf;
    d[0] = 0;
    for (int i = 0; i <= st; ++i)
        s.insert({d[i], i});
    for (int i = 0; i <= st; ++i) {
        pair <int, int> pp = *s.begin();
        s.erase(s.begin());
        int u = pp.se;
        for (int j = 0; j < e[u].size(); ++j)
        if (w[e[u][j]].f < w[e[u][j]].c && d[w[e[u][j]].b] > d[u] + w[e[u][j]].cost - P[w[e[u][j]].b] + P[u]) {
            s.erase({d[w[e[u][j]].b], w[e[u][j]].b});
            d[w[e[u][j]].b] = d[u] + w[e[u][j]].cost - P[w[e[u][j]].b] + P[u];
            pr[w[e[u][j]].b] = e[u][j];
            s.insert({d[w[e[u][j]].b], w[e[u][j]].b});
        }
    }
}

int x[N], y[N];

int main() {
    int i, j, k, n, m, c, D, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> c >> D;
    int ist = 0, st = n * (n + k + 1) + 1;
    for (i = 1; i <= k; ++i) {
        cin >> j;
        add_edge(ist, j, 1, 0);
    }
    for (j = 0; j < m; ++j)
        cin >> x[j] >> y[j];
    add_edge(1, st, inf, 0);
    for (i = 1; i <= n + k; ++i) {
        add_edge(i * n + 1, st, inf, c * i);
        for (j = 0; j < m; ++j)
        for (l = 0; l < k; ++l) {
            add_edge((i - 1) * n + x[j], i * n + y[j], 1, D * (2 * l + 1));
            add_edge((i - 1) * n + y[j], i * n + x[j], 1, D * (2 * l + 1));
        }
        for (j = 1; j <= n; ++j)
            add_edge((i - 1) * n + j, i * n + j, inf, 0);
    }
    DKSTR(ist, st);
    for (i = 0; i <= st; ++i)
        P[i] = d[i];
    long long ans = 0;
    for (i = 1; i <= k; ++i) {
        int u = st;
        while (u != ist) {
            ans += w[pr[u]].cost;
            ++w[pr[u]].f;
            --w[w[pr[u]].p].f;
            u = w[pr[u]].a;
        }
        DKSTR(ist, st);
        for (j = 0; j <= st; ++j)
            P[j] += d[j];
    }
    cout << ans;
}