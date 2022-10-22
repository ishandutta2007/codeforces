#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
bool vis[maxn];
int n, a[maxn];

int dfs(int u) {
	if (vis[u]) {
		return u;
	}
	return vis[u] = 1, dfs(a[u]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		printf("%d ", dfs(i));
	}
	return 0;
}