#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

struct Edge {
    int v, w, nxt;
} e[N << 1];
int hd[N], cnt;
void push(int u, int v, int w) {
    e[++ cnt] = (Edge) {v, w, hd[u]};
    hd[u] = cnt;
}

int n, d[N], s;

void dfs(int u, int f = 0) {
    for(int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == f) continue ;
        s += e[i].w < 0 ? 1 : 0;
        d[v] = d[u] + (e[i].w < 0 ? -1 : 1);
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for(int u, v, i = 1; i < n; i ++) {
        scanf("%d%d", &u, &v);
        push(u, v, 1);
        push(v, u, -1);
    }
    dfs(1);
    int ans = n - 1;
    for(int i = 1; i <= n; i ++)
        ans = min(ans, d[i] + s);
    printf("%d\n", ans);
    for(int i = 1; i <= n; i ++)
        if(d[i] + s == ans) printf("%d ", i);
    return 0;
}