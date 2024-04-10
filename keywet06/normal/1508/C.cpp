#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct edge {
    int u, v, w;
    bool operator<(const edge &oth) const { return w < oth.w; }
} e[N << 1];
int n, m, x, mn = INT_MAX;
long long ans, rem;
struct disjoint_sets_union {
    int fa[N];
    int Query(int p) {
        if (fa[p] == p) return p;
        return fa[p] = Query(fa[p]);
    }

} dsu;
queue<int> que;
set<int> unvised, G[N];
bool vis[N], type[N];
void FindBlocks() {
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            que.push(i);
            vis[i] = true;
            unvised.erase(i);
            dsu.fa[i] = i;
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (set<int>::iterator it = unvised.begin();
                     it != unvised.end();) {
                    int v = *it++;
                    if (G[u].count(v)) continue;
                    dsu.fa[v] = u, unvised.erase(v), vis[v] = true;
                    que.push(v), rem--;
                }
            }
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rem = 1LL * n * (n - 1) / 2 - m;
    for (int i = 1; i <= n; i++) unvised.insert(i);
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        G[e[i].u].insert(e[i].v);
        G[e[i].v].insert(e[i].u);
        x ^= e[i].w;
    }
    sort(e + 1, e + m + 1);
    FindBlocks();
    for (int i = 1; i <= m; i++) {
        int fau = dsu.Query(e[i].u), fav = dsu.Query(e[i].v);
        if (fau != fav) dsu.fa[fau] = fav, ans += e[i].w, type[i] = 1;
    }
    if (rem > 0) return printf("%lld\n", ans) && 0;
    for (int i = 1; i <= n; i++) dsu.fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int fau = dsu.Query(e[i].u), fav = dsu.Query(e[i].v);
        if (fau == fav) continue;
        dsu.fa[fau] = fav;
        if (!type[i]) {
            mn = e[i].w;
            break;
        }
    }
    printf("%lld\n", ans + min(x, mn));
    return 0;
}