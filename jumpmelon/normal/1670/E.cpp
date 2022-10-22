#include <bits/stdc++.h>

using namespace std;

const int MAXP = 17, MAXN = 1 << MAXP;

int p, n;
struct edge { int i, v; };
vector<edge> G[MAXN + 5];
int LV[MAXN + 5], LE[MAXN + 5];

void DFS(int u, int fa, int d) {
    for (auto &&e : G[u])
        if (e.v != fa) {
            DFS(e.v, u, d ^ 1);
            LV[e.v] = d << p | e.v;
            LE[e.i] = (d ^ 1) << p | e.v;
        }
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d", &p);
        n = 1 << p;
        for (int i = 1; i <= n; i++)
            G[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back({i, v});
            G[v].push_back({i, u});
        }
        LV[n] = n;
        DFS(n, 0, 0);
        printf("%d\n", n);
        for (int i = 1; i <= n; i++)
            printf("%d%c", LV[i], i < n ? ' ' : '\n');
        for (int i = 1; i < n; i++)
            printf("%d%c", LE[i], i + 1 < n ? ' ' : '\n');
    }
    return 0;
}