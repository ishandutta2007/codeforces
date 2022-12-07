#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 200005;

int n, m, num = 1, bit[2][2 * N];
struct Node {
    int l, r, v, d;
}node[N];
vector<int> g[N];

void add(int x, int v, int *bit) {
    while (x <= 2 * n) {
        bit[x] += v;
        x += (x&(-x));
    }
}

int get(int x, int *bit) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}

void dfs(int u, int fa, int d) {
    node[u].l = num++; node[u].d = d;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u, 1 - d);
    }
    node[u].r = num++;
}

void init() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= n; i++)
        scanf("%d", &node[i].v);
    for (int j = 0; j < n - 1; j++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
}

void solve() {
    int cz, a, b;
    while (m--) {
        scanf("%d", &cz);
        if (cz == 1) {
            scanf("%d%d", &a, &b);
            add(node[a].l, b, bit[node[a].d]);
            add(node[a].r + 1, -b, bit[node[a].d]);
        }
        else {
            scanf("%d", &a);
            printf("%d\n", node[a].v + get(node[a].l, bit[node[a].d]) - get(node[a].l, bit[1 - node[a].d]));
        }
    }
}

int main() {
    init();
    solve();
    return 0;
}