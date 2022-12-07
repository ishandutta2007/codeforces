#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100005;

int n, q, val[N], f[N];
vector<int> g[N];

void dfs(int u, int fa) {
    f[u] = fa;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
    }
}

int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int query(int u) {
    int v = val[u];
    u = f[u];
    while (u) {
        if (gcd(val[u], v) > 1) return u;
        u = f[u];
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int tp, a, b;
    while (q--) {
        scanf("%d%d", &tp, &a);
        if (tp == 1) {
            printf("%d\n", query(a));
        } else {
            scanf("%d", &b);
            val[a] = b;
        }
    }
    return 0;
}