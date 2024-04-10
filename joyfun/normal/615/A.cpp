#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int tmp[105], vis[105];

bool judge() {
    for (int i = 1; i <= m; i++) if (vis[i] == 0) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    int x, k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        memset(tmp, 0, sizeof(tmp));
        while (x--) {
            scanf("%d", &k);
            tmp[k] = 1;
        }
        for (int j = 1; j <= m; j++) if (tmp[j]) vis[j] = 1;
    }
    printf("%s\n", judge() ? "YES" : "NO");
    return 0;
}