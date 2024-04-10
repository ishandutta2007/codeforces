#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, p[N], vis[N];
vector<int> g[N];
int gn;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    int f1 = 0, f2 = 0, odd = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ++gn;
        int u = i;
        vis[u] = 1;
        g[gn].push_back(u);
        u = p[u];
        while (1) {
            if (vis[u]) break;
            vis[u] = 1;
            g[gn].push_back(u);
            u = p[u];
        }
        if (g[gn].size() == 1) f1 = gn;
        if (g[gn].size() == 2) f2 = gn;
        if (g[gn].size() % 2) odd = 1;
    }
    if (f1) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            if (g[f1][0] == i) continue;
            printf("%d %d\n", i, g[f1][0]);
        }
    } else if (!f1 && f2) {
        if (odd) printf("NO\n");
        else {
            printf("YES\n");
            printf("%d %d\n", g[f2][0], g[f2][1]);
            for (int i = 1; i <= gn; i++) {
                if (f2 == i) continue;
                for (int j = 0; j < g[i].size(); j += 2)
                    printf("%d %d\n", g[f2][0], g[i][j]);
                for (int j = 1; j < g[i].size(); j += 2)
                    printf("%d %d\n", g[f2][1], g[i][j]);
            }
        }
    } else printf("NO\n");
    return 0;
}