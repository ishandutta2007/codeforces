#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
int n;
vector<int> g[N];
int ans[N];

void dfs(int u, int p) {
    int j = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        while (j == ans[p] || j == ans[u]) j++;
        ans[v] = j;
        j++;
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans[1] = 1;
    dfs(1, 0);
    int Max = 0;
    for (int i = 1; i <= n; i++) Max = max(Max, ans[i]);
    printf("%d\n", Max);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
    return 0;
}