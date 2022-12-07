#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

const int N = 1005;
int n, m, vis[N], val[N];
vector<int> g[N];
struct Node {
    int value;
    int id;
} node[N];

bool cmp(Node a, Node b) {
    return a.value > b.value;
}

int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &node[i].value);
        node[i].id = i;
        val[i] = node[i].value;
    }
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    sort(node + 1, node + 1 + n, cmp);
    for (i = 1; i <= n; i++) {
        int u = node[i].id;
        vis[u] = 1;
        for (j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            if (vis[v]) continue;
            ans += val[v];
        }
    }
    printf("%d\n", ans);
    return 0;
}