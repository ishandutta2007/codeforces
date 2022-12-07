#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int N = 100005;
const int M = 200005;

struct Edge {
    int u, v;
    Edge() {}
    Edge(int u, int v) {
        this->u = u;
        this->v = v;
    }
} edge[M];

int head[N], nxt[M], en;
int fa[N][20], deep[N];

void init() {
    en = 0;
    memset(head, -1, sizeof(head));
}

void add_Edge(int u, int v) {
    edge[en] = Edge(u, v);
    nxt[en] = head[u];
    head[u] = en++;
}

void bfs(int root) {
    queue<int> Q;
    deep[root] = 0;
    fa[root][0] = root;
    Q.push(root);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int i = 1; i < 20; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int i = head[u]; i + 1; i = nxt[i]) {
            int v = edge[i].v;
            if (v == fa[u][0]) continue;
            deep[v] = deep[u] + 1;
            fa[v][0] = u;
            Q.push(v);
        }
    }
}

int lca(int u, int v) {
    if (deep[u] > deep[v]) swap(u, v);
    int hu = deep[u], hv = deep[v];
    int tu = u, tv = v;
    int tmp = hv - hu;
    for (int i = 0; i < 20; i++)
        if (tmp&(1<<i)) tv = fa[tv][i];
    if (tu == tv) return tu;
    for (int i = 19; i >= 0; i--) {
        if (fa[tu][i] == fa[tv][i])
            continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}

int L[N], R[N], idx;

void dfs(int u, int p) {
    L[u] = ++idx;
    for (int i = head[u]; i + 1; i = nxt[i]) {
        int v = edge[i].v;
        if (v == p) continue;
        dfs(v, u);
    }
    R[u] = idx;
}

int n;

int k, x[N * 2];
bool cmp(int a, int b) {
    return L[a] < L[b];
}

set<pair<int, int> > s;

int dp[N][2];
int xx[N], vis[N];
const int INF = 0x3f3f3f3f;

int V[N], vn;

int solve() {
    int kk = k;
    sort(x, x + k, cmp);
    for (int i = 0; i < kk; i++) {
        xx[i] = x[i];
        vis[xx[i]] = 1;
    }
   // printf("%d\n", kk);
    for (int i = 0; i < kk; i++) {
        if (xx[i] == 1) continue;
        if (vis[fa[xx[i]][0]]) {
            for (int j = 0; j < kk; j++)
                vis[xx[j]] = 0;
            return -1;
        }
    }
    for (int i = 1; i < kk; i++)
        x[k++] = lca(x[i - 1], x[i]);
    sort(x, x + k, cmp);
    k = unique(x, x + k) - x;
    //printf("%d\n", k);
    s.clear();
    for (int u = k - 1; u >= 0; u--) {
        dp[u][0] = dp[u][1] = 0;
        if (vis[x[u]]) dp[u][0] = INF;
        int vn = 0;
        int cnt = 0;
        while (1) {
            set<pair<int, int> >::iterator it = s.lower_bound(make_pair(L[x[u]], 0));
            if (it == s.end()) break;
            int v = it->second;
            if (L[x[v]] > R[x[u]]) break;
            s.erase(it);
            V[vn++] = v;
           // printf("%d %d@\n", u, vis[x[u]]);
            if (vis[x[u]]) {
                dp[u][1] += min(dp[v][0], dp[v][1] + 1);
            //    printf("%d %d\n", u, dp[u][1]);
            }
            else {
                if (dp[v][0] == INF) cnt++;
                dp[u][0] += min(dp[v][0], dp[v][1]);
            }
        }
        if (!vis[x[u]]) {
            dp[u][0]++;
            if (cnt >= 2) dp[u][1] = INF;
            else if (cnt == 1) {
                for (int i = 0; i < vn; i++) {
                    int v = V[i];
                    if (dp[v][0] == INF) dp[u][1] += dp[v][1];
                    else dp[u][1] += dp[v][0];
                }
            } else {
                int Min = INF;
                for (int i = 0; i < vn; i++) {
                    int v = V[i];
                    dp[u][1] += dp[v][0];
                    Min = min(Min, dp[v][1] - dp[v][0]);
                }
                dp[u][0] = min(dp[u][0], dp[u][1]);
                dp[u][1] += Min;
            }
        }
       // printf("%d %d\n", dp[u][0], dp[u][1]);
     //  printf("%d %d\n", L[x[u]], u);
        s.insert(make_pair(L[x[u]], u));
    }
   // printf("%d\n", kk);
    for (int i = 0; i < kk; i++) vis[xx[i]] = 0;
    return min(dp[0][0], dp[0][1]);
}

int main() {
    scanf("%d", &n);
    init();
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        add_Edge(u, v);
        add_Edge(v, u);
    }
    bfs(1);
    idx = 0;
    dfs(1, 1);
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
            scanf("%d", &x[i]);
        printf("%d\n", solve());
    }
    return 0;
}