#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXNODE = 205 * 2;
const int MAXEDGE = 100005;

typedef int Type;
const Type INF = 0x3f3f3f3f;

const int N = 205;

int n, a, odd[N], even[N], oddid[N], evenid[N];
int on, en;
int vis[20005], prime[20005], pn = 0;

struct Edge {
    int u, v;
    Type cap, flow;
    Edge() {}
    Edge(int u, int v, Type cap, Type flow) {
        this->u = u;
        this->v = v;
        this->cap = cap;
        this->flow = flow;
    }
};

struct Dinic {
    int n, m, s, t;
    Edge edges[MAXEDGE];
    int first[MAXNODE];
    int next[MAXEDGE];
    bool vis[MAXNODE];
    Type d[MAXNODE];
    int cur[MAXNODE];
    int match[MAXNODE][2], mn[MAXNODE];
    int vv[MAXNODE];
    vector<int> cut;

    void init(int n) {
        this->n = n;
        memset(first, -1, sizeof(first));
        memset(mn, 0, sizeof(mn));
        m = 0;
    }
    void add_Edge(int u, int v, Type cap) {
        edges[m] = Edge(u, v, cap, 0);
        next[m] = first[u];
        first[u] = m++;
        edges[m] = Edge(v, u, 0, 0);
        next[m] = first[v];
        first[v] = m++;
    }

    bool bfs() {
        memset(vis, false, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = true;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = first[u]; i != -1; i = next[i]) {
                Edge& e = edges[i];
                if (!vis[e.v] && e.cap > e.flow) {
                    vis[e.v] = true;
                    d[e.v] = d[u] + 1;
                    Q.push(e.v);
                }
            }
        }
        return vis[t];
    }

    Type dfs(int u, Type a) {
        if (u == t || a == 0) return a;
        Type flow = 0, f;
        for (int &i = cur[u]; i != -1; i = next[i]) {
            Edge& e = edges[i];
            if (d[u] + 1 == d[e.v] && (f = dfs(e.v, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[i^1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    Type Maxflow(int s, int t) {
        this->s = s; this->t = t;
        Type flow = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++)
                cur[i] = first[i];
            flow += dfs(s, INF);
        }
        return flow;
    }

    void solve() {
        for (int i = 0; i < m; i += 2) {
            if (edges[i].u == n - 2 || edges[i].v == n - 1) continue;
            if (edges[i].flow == 0) continue;
            match[oddid[edges[i].u]][mn[oddid[edges[i].u]]++] = evenid[edges[i].v - on];
            match[evenid[edges[i].v - on]][mn[evenid[edges[i].v - on]]++] = oddid[edges[i].u];
        }
        memset(vv, 0, sizeof(vv));
        int out[205][205], hn = 0, on[205];
        memset(on, 0, sizeof(on));
        for (int i = 1; i <= n - 2; i++) {
            if (vv[i]) continue;
            on[hn] = 0;
            int s = i;
            while (1) {
                vv[s] = 1;
                out[hn][on[hn]++] = s;
                if (!vv[match[s][0]]) {
                    s = match[s][0];
                    continue;
                }
                if (!vv[match[s][1]]) {
                    s = match[s][1];
                    continue;
                }
                break;
            }
            hn++;
        }
        printf("%d\n", hn);
        for (int i = 0; i < hn; i++) {
            printf("%d", on[i]);
            for (int j = 0; j < on[i]; j++)
                printf(" %d", out[i][j]);
            printf("\n");
        }
    }
} gao;

int main() {
    for (int i = 2; i < 20005; i++) {
        if (vis[i]) continue;
        prime[pn++] = i;
        for (int j = i * i; j < 20005; j += i) {
            vis[j] = 1;
        }
    }
    scanf("%d", &n);
    gao.init(n + 2);
    on = en = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a % 2) {
            oddid[on] = i;
            odd[on++] = a;
        }
        else {
            evenid[en] = i;
            even[en++] = a;
        }
    }
    for (int i = 0; i < on; i++) gao.add_Edge(n, i, 2);
    for (int i = 0; i < en; i++) gao.add_Edge(i + on, n + 1, 2);
    for (int i = 0; i < on; i++)
        for (int j = 0; j < en; j++) {
            if (!vis[odd[i] + even[j]])
                gao.add_Edge(i, on + j, 1);
    }
    if (gao.Maxflow(n, n + 1) != n) printf("Impossible\n");
    else {
        gao.solve();
    }
    return 0;
}