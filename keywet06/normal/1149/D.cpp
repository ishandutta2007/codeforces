#include <bits/stdc++.h>

using namespace std;

const int N = 71;
const int M = 210;
const int V = 1 << 17;

bool vis[N][V];

int n, m, a, b, Cnt, Siz, Tot, NTot;
int Head[N], Fa[N], Ans[N], NId[N], Id[N], Rt[N], Rev[N], NRt[N], Size[N];
int d[N][V];

struct Node {
    int u, v, w;
} c[M];

bool operator<(const Node &i, const Node &j) { return i.w < j.w; }

struct Query {
    int x, p, Id;
} q[10000010];

bool operator<(const Query &i, Query &j) { return i.x > j.x; }

struct Edge {
    int v, w, nxt;
} e[M << 1];

void AddEdge(int u, int v, int w) {
    e[++Cnt].v = v;
    e[Cnt].w = w;
    e[Cnt].nxt = Head[u];
    Head[u] = Cnt;
}

int Read() {
    int x = 0;
    char ch = 0;
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}

int Ff(int x) {
    if (Fa[x] == x) return x;
    return Fa[x] = Ff(Fa[x]);
}

void Dijkstra() {
    memset(d, 63, sizeof(d));
    Ans[1] = d[1][0] = 0;
    q[++Siz] = (Query){0, 1, 0};
    while (Siz) {
        int u = q[1].p, idd = q[1].Id;
        pop_heap(q + 1, q + Siz + 1);
        --Siz;
        if (vis[u][idd]) continue;
        vis[u][idd] = 1;
        Ans[u] = min(Ans[u], d[u][idd]);
        for (int i = Head[u]; i; i = e[i].nxt) {
            if (Id[e[i].v] == Id[u] && e[i].w == b) continue;
            if (NId[e[i].v] && (1 << NId[e[i].v] - 1 & idd)) continue;
            int cur = idd;
            if (NId[e[i].v] != NId[u] && NId[u]) cur |= 1 << NId[u] - 1;
            if (d[u][idd] + e[i].w < d[e[i].v][cur]) {
                d[e[i].v][cur] = d[u][idd] + e[i].w;
                q[++Siz] = (Query){d[e[i].v][cur], e[i].v, cur};
                push_heap(q + 1, q + Siz + 1);
            }
        }
    }
}

int main() {
    int u, v, w;
    n = Read(), m = Read(), a = Read(), b = Read();
    for (int i = 1; i <= m; ++i) {
        c[i].u = u = Read();
        c[i].v = v = Read();
        c[i].w = w = Read();
        AddEdge(u, v, w);
        AddEdge(v, u, w);
    }
    sort(c + 1, c + m + 1);
    for (int i = 1; i <= n; ++i) Fa[i] = i;
    for (int i = 1; i <= m && c[i].w == a; ++i) {
        int fx = Ff(c[i].u), fy = Ff(c[i].v);
        if (fx != fy) Fa[fx] = fy;
    }
    for (int i = 1; i <= n; ++i)
        if (Fa[i] == i) Rt[i] = ++Tot, Rev[Tot] = i;
    for (int i = 1; i <= n; ++i) {
        ++Size[Rt[Ff(i)]];
        Id[i] = Rt[Ff(i)];
    }
    for (int i = 1; i <= Tot; ++i) {
        if (Size[i] > 3) NRt[Rev[i]] = ++NTot;
    }
    for (int i = 1; i <= n; ++i) {
        if (Size[Id[i]] > 3) NId[i] = NRt[Ff(i)];
    }
    memset(Ans, 63, sizeof(Ans));
    Dijkstra();
    for (int i = 1; i <= n; ++i) printf("%d ", Ans[i]);
    printf("\n");
    return 0;
}