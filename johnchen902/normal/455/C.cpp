#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
vector<int> adj[300000];
int dj[300000];
int ln[300000];
int query(int u) {
    return dj[u] == -1 ? u : (dj[u] = query(dj[u]));
}
void merge(int u, int v) {
    u = query(u);
    v = query(v);
    if(u != v) dj[u] = v;
}
pair<int, int> dfs(int x, int p = -1) {
    pair<int, int> q = {-1, x};
    for(int i : adj[x])
        if(i != p)
            q = max(q, dfs(i, x));
    return {q.first + 1, q.second};
}
int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    fill_n(dj, n, -1);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        merge(u, v);
    }
    for(int i = 0; i < n; i++) {
        if(dj[i] != -1) continue;
        auto p = dfs(i);
        ln[i] = dfs(p.second).first;
    }
    for(int i = 0; i < q; i++) {
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            int u;
            scanf("%d", &u);
            u--;
            u = query(u);
            printf("%d\n", ln[u]);
        } else {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            u = query(u);
            v = query(v);
            if(u != v) {
                ln[v] = max((ln[u] + 1) / 2 + 1 + (ln[v] + 1) / 2, max(ln[u], ln[v]));
                dj[u] = v;
            }
        }
    }
}