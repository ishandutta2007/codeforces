#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100005;

int n, m, x[N], now[N], vis[N], nv;
vector<int> g[N], ans;

void dfs(int u, int p) {
    vis[u] = 1;
    ans.push_back(u);
    now[u] ^= 1;
    for (int i = 0; i < g[u].size(); i++) {
	int v = g[u][i];
	if (vis[v]) continue;
	dfs(v, u);
    }
    if (x[u]^now[u]) {
	if (p != 0) {
	    ans.push_back(p);
	    ans.push_back(u);
	    now[p] ^= 1;
	    now[u] ^= 1;
	}
    }
    if (p != 0) {
	ans.push_back(p);
	now[p] ^= 1;
    }
}

bool judge() {
    if (x[nv]^now[nv]) {
	if (ans.size() == 0) return false;
	now[nv] ^= 1;
	ans.pop_back();
    }
    for (int i = 1; i <= n; i++)
	if (x[i]^now[i]) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
	scanf("%d%d", &u, &v);
	g[u].push_back(v);
	g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
	scanf("%d", &x[i]);
    memset(now, 0, sizeof(now));
    for (int i = 1; i <= n; i++) {
	if (x[i]^now[i]) {
	    nv = i;
	    dfs(i, 0);
	    break;
	}
    }
    if (judge()) {
	int tmp = ans.size();
	printf("%d\n", tmp);
	for (int i = 0; i < tmp; i++) {
	    printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	}
    }
    else printf("-1\n");
    return 0;
}