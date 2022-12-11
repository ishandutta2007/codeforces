#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 3e5 + 10;

int n, a[N], f[N], sz[N], l;
vector<int> G[N];

void dfs(int u) {
    if(!G[u].size()) {
        sz[u] = 1;
        l ++;
        return ;
    }
    if(a[u]) sz[u] = 1e9;
    for(int v : G[u]) {
        dfs(v);
        if(!a[u]) sz[u] += sz[v];
        else sz[u] = min(sz[u], sz[v]);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    for(int i = 2; i <= n; i ++) {
        scanf("%d", &f[i]);
        G[f[i]].push_back(i);
    }
    dfs(1);
    printf("%d\n", l - sz[1] + 1);
    return 0;
}