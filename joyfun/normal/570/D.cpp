#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 500005;

int n, m;
vector<int> g[N];
vector<int> q[N];
int h[N];

int res[N], pre[N];
char str[N];

void dfs(int u, int d) {
    for (int i = 0; i < q[u].size(); i++) {
        int id = q[u][i];
        res[id] ^= pre[h[id]];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs(v, d + 1);
    }
    pre[d] ^= (1<<(str[u] - 'a'));
    for (int i = 0; i < q[u].size(); i++) {
        int id = q[u][i];
        res[id] ^= pre[h[id]];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int f;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &f);
        g[f].push_back(i);
    }
    scanf("%s", str + 1);
    int V, H;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &V, &H);
        q[V].push_back(i);
        h[i] = H;
    }
    dfs(1, 1);
    for (int i = 0; i < m; i++)
        printf("%s\n", (res[i]&(res[i] - 1)) ? "No" : "Yes");
    return 0;
}