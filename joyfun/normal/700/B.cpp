#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
int n, k;
int c[N];
vector<int> g[N];
long long ans = 0;
void dfs(int u, int p) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
		c[u] += c[v];
	}
	ans += min(c[u], 2 * k - c[u]);
}

int main() {
	scanf("%d%d", &n, &k);
	int x;
	for (int i = 0; i < 2 * k; i++) {
		scanf("%d", &x);
		c[x] = 1;
	}
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	printf("%lld\n", ans);
	return 0;
}