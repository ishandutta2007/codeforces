#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 3010;

int f[N], deg[N], val[N];
vector<int> G[N];
char s[N][N];
bool rt[N], edge[N][N];

int gf(int u) {
    return u == f[u] ? u : f[u] = gf(f[u]);
}

void merge(int u, int v) {
    u = gf(u); v = gf(v);
    if(u != v) f[u] = v;
}

void link(int u, int v) {
    if(!edge[u][v]) {
        edge[u][v] = 1;
        G[u].push_back(v);
        deg[v] ++;
    }
}

int l1, l2, n;

int main() {
    scanf("%d%d", &l1, &l2);
    n = l1 + l2;
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= l1; i ++) {
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= l2; j ++) {
            if(s[i][j] == '=') {
                merge(i, l1 + j);
            }
        }
    }
    int nodes = 0;
    for(int i = 1; i <= n; i ++)
        if(gf(i) == i) rt[i] = 1, nodes ++;
    for(int i = 1; i <= l1; i ++) {
        for(int j = 1; j <= l2; j ++) {
            if(s[i][j] == '<') {
                link(f[i], f[l1 + j]);
            }
            if(s[i][j] == '>') {
                link(f[l1 + j], f[i]);
            }
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i ++) {
        if(rt[i] && !deg[i]) {
            q.push(i);
            val[i] = 1;
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : G[u]) {
            if(!-- deg[v]) {
                q.push(v);
                val[v] = val[u] + 1;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(rt[i] && val[i] == 0) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for(int i = 1; i <= l1; i ++) printf("%d ", val[f[i]]);
    puts("");
    for(int i = 1; i <= l2; i ++) printf("%d ", val[f[i + l1]]);
    return 0;
}