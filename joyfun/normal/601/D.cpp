#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 300005;

int n, c[N];
char str[N];
vector<int> g[N];
int ch[N][26], val[N], cc[N];

void gao(int u, int v) {
    for (int c = 0; c < 26; c++) {
        if (ch[v][c]) {
            if (!ch[u][c]) {
                ch[u][c] = ch[v][c];
                val[u] += val[ch[v][c]];
            } else {
                val[u] -= val[ch[u][c]];
                gao(ch[u][c], ch[v][c]);
                val[u] += val[ch[u][c]];
            }
        }
    }
}

void dfs(int u, int p) {
    val[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
        int c = str[v] - 'a';
        if (!ch[u][c]) {
            ch[u][c] = v;
            val[u] += val[v];
        } else {
            val[u] -= val[ch[u][c]];
            gao(ch[u][c], v);
            val[u] += val[ch[u][c]];
        }
    }
    cc[u] = val[u];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    scanf("%s", str + 1);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    int Max = 0, cnt = 0;
    for (int i = 1; i <= n; i++) Max = max(Max, c[i] + cc[i]);
    for (int i = 1; i <= n; i++) if (Max == c[i] + cc[i]) cnt++;
    printf("%d\n%d\n", Max, cnt);
    return 0;
}