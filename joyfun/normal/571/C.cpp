#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

int n, m, s[N][2];

struct Edge {
    int v, id, f, nxt;
    Edge() {}
    Edge(int v, int id, int f, int nxt) : v(v), id(id), f(f), nxt(nxt) {}
} edge[N * 2];

int head[N], sz;

void add_edge(int u, int v , int id, int f) {
    edge[sz] = Edge(v, id, f, head[u]);
    head[u] = sz++;
}

int vis[N], ans[N], use[N * 2];

bool dfs(int u) {
    if (vis[u]) return true;
    vis[u] = 1;
    int flag = 0;
    for (int i = head[u]; i + 1; i = edge[i].nxt) {
        int v = edge[i].v;
        int id = edge[i].id;
        int f = edge[i].f;
        if (use[id]) continue;
        use[id] = 1;
        int tmp = dfs(v);
        if (edge[i].f == edge[i^1].f) tmp = 1;
        //printf("%d %d %d %d %d\n", u, v, tmp, f, id);
        flag |= tmp;
        ans[id] = edge[i^tmp].f;
    }
    return flag;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int k, x;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            if (x < 0) {
                if (s[-x][1]) {
                    int pre = s[-x][1];
                    add_edge(i, pre, -x, 0);
                    add_edge(pre, i, -x, 0);
                    s[-x][1] = 0;
                } else s[-x][1] = i;
            }
            else {
                if (s[x][0]) {
                    int pre = s[x][0];
                    add_edge(i, pre, x, 1);
                    add_edge(pre, i, x, 1);
                    s[x][0] = 0;
                } else s[x][0] = i;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        if (s[i][0]) cnt++;
        if (s[i][1]) cnt++;
        if (cnt == 0) continue;
        if (cnt == 1) {
            if (s[i][0]) {
                add_edge(s[i][0], s[i][0], i, 1);
                add_edge(s[i][0], s[i][0], i, 1);
            }
            else {
                add_edge(s[i][1], s[i][1], i, 0);
                add_edge(s[i][1], s[i][1], i, 0);
            }
        } else {
            add_edge(s[i][0], s[i][1], i, 0);
            add_edge(s[i][1], s[i][0], i, 1);
        }
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (!dfs(i)) {
            flag = 0;
            break;
        }
    }
    if (!flag) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 1; i <= m; i++) printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}