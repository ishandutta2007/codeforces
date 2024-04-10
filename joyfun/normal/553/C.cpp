#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
const int MOD = 1000000007;

#define MK(a, b) make_pair(a, b)
#define fi first
#define se second

typedef pair<int, int> pii;
int n, m;

vector<pii> g[N];
int col[N];
int ans;

void dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].fi;
        int w = g[u][i].se;
        if (col[v] == -1) {
            col[v] = col[u]^(!w);
            dfs(v);
        } else {
            if (w == 1 && col[v] != col[u]) ans = 0;
            if (w == 0 && col[u] == col[v]) ans = 0;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v, w;
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(MK(v, w));
        g[v].push_back(MK(u, w));
    }
    memset(col, -1, sizeof(col));
    ans = (MOD + 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            col[i] = 0;
            dfs(i);
            ans = (ans + ans) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}