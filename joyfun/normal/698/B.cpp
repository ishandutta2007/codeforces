#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 200005;
int n, a[N], b[N];
vector<int> g[N];
int du[N];
int vis[N];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    dfs(a[u]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        du[a[i]]++;
    }
    queue<int> Q;
    for (int i = 1; i <= n; i++) if (!du[i]) Q.push(i);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        vis[u] = 1;
        int v = a[u];
        du[v]--;
        if (!du[v]) Q.push(v);
    }
    int f = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && i == a[i]) {
            f = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
        if (f == -1) {
            b[i] = i;
            f = i;
        } else b[i] = f;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (a[i] != b[i]) cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) printf("%d ", b[i]); printf("\n");
    return 0;
}