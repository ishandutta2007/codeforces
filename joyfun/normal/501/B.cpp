#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int n, hn, vis[2005], to[2005];
map<string, int> hash;
char a[25], b[25];
char out[2005][25];

int get(char *str) {
    if (hash.count(str))
    return hash[str];
    strcpy(out[hn], str);
    hash[str] = hn++;
    return hash[str];
}

int dfs(int u) {
    while (1) {
    if (to[u] == -1) break;
    u = to[u];
    }
    return u;
}

int main() {
    scanf("%d", &n);
    hn = 0;
    memset(to, -1, sizeof(to));
    while (n--) {
    scanf("%s%s", a, b);
    int u = get(a), v = get(b);
    to[u] = v;
    vis[v] = 1;
    }
    int tot = 0;
    for (int i = 0; i < hn; i++)
    if (!vis[i]) {
        tot++;
    }
    printf("%d\n", tot);
    for (int i = 0; i < hn ;i++)
    if (!vis[i]) {
        printf("%s %s\n", out[i], out[dfs(i)]);
    }
    return 0;
}