#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 2005;
int n, parent[N];
ll d[N][N], ans[N][N];

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

vector<int> g[N];

struct Edge {
    int u, v, d;
    Edge() {}
    Edge(int u, int v, int d) {
        this->u = u;
        this->v = v;
        this->d = d;
    }
} e[N * N];

int en = 0;

bool cmp(Edge a, Edge b) {
    return a.d < b.d;
}

void dfs(int st, int u, int f, ll sum) {
    ans[st][u] = sum;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (f == v) continue;
        dfs(st, v, u, sum + d[u][v]);
    }
}

bool judge() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        for (int j = 1; j <= n; j++) {
            if (i == j && d[i][j]) return false;
            if (i != j && !d[i][j]) return false;
            if (d[i][j] != d[j][i]) return false;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            e[en++] = Edge(i, j, d[i][j]);
        }
    sort(e, e + en, cmp);
    for (int i = 0; i < en; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            g[e[i].u].push_back(e[i].v);
            g[e[i].v].push_back(e[i].u);
            parent[u] = v;
        }
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, i, 0, 0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ans[i][j] != d[i][j]) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &d[i][j]);
    if (judge()) printf("YES\n");
    else printf("NO\n");
    return 0;
}