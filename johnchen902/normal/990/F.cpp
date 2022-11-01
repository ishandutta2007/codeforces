#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct E { int u, v, f; } edges[200000]; 
vector<int> adj[200000];
int s[200000];
bool vis[200000];

int dfs(int u) {
    vis[u] = true;
    int sum = s[u];
    for (int ei : adj[u]) {
        E &e = edges[ei];
        int v = e.u + e.v - u;
        if (vis[v])
            continue;
        int f = dfs(v);
        e.f = u == e.u ? f : -f;
        sum += f;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", s + i);
    
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        edges[i].u = u;
        edges[i].v = v;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    if (dfs(0)) {
        puts("Impossible");
    } else {
        puts("Possible");
        for (int i = 0; i < m; i++)
            printf("%d\n", edges[i].f);
    }
}