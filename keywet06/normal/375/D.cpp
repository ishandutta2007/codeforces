#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int S = 300;

int n, m, clk;
int Col[N], Dfn[N], End[N], a[N];

vector<int> g[N];

void Dfs(int u, int p = -1) {
    Dfn[u] = clk;
    a[clk++] = Col[u];
    for (int v : g[u]) {
        if (v != p) Dfs(v, u);
    }
    End[u] = clk;
}

struct Query {
    int l, r, k, id;
    bool operator<(const Query &b) const {
        return (l / S) == (b.l / S) ? r < b.r : l < b.l;
    }
} qry[N];

int Lar[N + 1], Sma[N + 1];
int App[N], Ans[N];

void Init(void) {
    fill(Lar, Lar + n + 1, 0);
    fill(Sma, Sma + n + 1, 0);
    fill(App, App + N, 0);
}

void Advance(int i, int x) {
    Sma[i] += x;
    Lar[i / S] += x;
}

void Insert(int c, int x) {
    int &t = App[c];
    Advance(t, -1);
    t += x;
    Advance(t, 1);
}

int Ask(int lb) {
    int sum = 0;
    while (lb % S) {
        sum += Sma[lb++];
    }
    lb /= S;
    while (lb * S <= n) {
        sum += Lar[lb++];
    }
    return sum;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", Col + i), --Col[i];
        g[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    clk = 0;
    Dfs(0);
    for (int i = 0; i < m; ++i) {
        int u, k;
        scanf("%d%d", &u, &k);
        --u;
        qry[i] = {Dfn[u], End[u], k, i};
    }
    sort(qry, qry + m);
    int L = 0, R = 0;
    Init();
    for (int i = 0; i < m; ++i) {
        int l = qry[i].l, r = qry[i].r;
        while (L > l) Insert(a[--L], 1);
        while (R < r) Insert(a[R++], 1);
        while (L < l) Insert(a[L++], -1);
        while (R > r) Insert(a[--R], -1);
        Ans[qry[i].id] = Ask(qry[i].k);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", Ans[i]);
    }
    return 0;
}