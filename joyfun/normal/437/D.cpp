#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, m, node[N], parent[N], sum[N];

struct Edge {
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0) {
    this->u = u; this->v = v; this->w = w;
    }
} e[N];

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
    parent[i] = i;
    sum[i] = 1;
    scanf("%d", &node[i]);
    }
    int u, v;
    for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    e[i] = Edge(u, v, min(node[u], node[v]));
    }
    sort(e, e + m, cmp);
    double ans = 0;
    for (int i = 0; i < m; i++) {
    int pa = find(e[i].u);
    int pb = find(e[i].v);
    if (pa != pb) {
        ans += (double)e[i].w * sum[pa] * sum[pb];
        parent[pb] = pa;
        sum[pa] += sum[pb];
    }
    }
    printf("%.6lf\n", ans * 2 / (n * 1.0 * (n - 1)));
    return 0;
}