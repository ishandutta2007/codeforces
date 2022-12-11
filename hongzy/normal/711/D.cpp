#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
const int mo = 1e9 + 7;

struct Edge {
    int v, nxt;
} e[N << 1];
int hd[N], cnt;
void link(int u, int v) {
    e[cnt] = (Edge) {v, hd[u]};
    hd[u] = cnt ++;
}

int n, dfn[N], f[N], p, x, y;
vector<int> G[N];

void dfs(int u, int cur = -1) {
    dfn[u] = ++ p;
    for(int i = hd[u]; ~ i; i = e[i].nxt) {
        int v = e[i].v;
        if(cur == i) continue ;
        if(!dfn[v]) f[v] = u, dfs(v, i ^ 1);
        else if(!y && dfn[v] < dfn[u]) {
            for(int j = u; j != v; j = f[j]) y ++;
            y ++;
        }
    }
}

int qpow(int x, int y) {
    int ans = 1;
    for(; y >= 1; y >>= 1, x = 1ll * x * x % mo)
        if(y & 1) ans = 1ll * ans * x % mo;
    return ans;
}

int main() {
    scanf("%d", &n);
    fill(hd + 1, hd + n + 1, -1);
    for(int x, i = 1; i <= n; i ++) {
        scanf("%d", &x);
        link(x, i); link(i, x);
    }
    int ans = 1;
    for(int i = 1; i <= n; i ++) if(!dfn[i]) {
        y = 0; dfs(i); x += y;
        ans = 1ll * ans * (qpow(2, y) - 2) % mo;
    }
    ans = 1ll * ans * qpow(2, n - x) % mo;
    printf("%d\n", (ans + mo) % mo);
    return 0;
}
/*
(2^{n - y})\prod(2^y - 2)
*/