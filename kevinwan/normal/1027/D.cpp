#include <bits/stdc++.h>
using namespace std;

int c[200001],vis[200001],a[200001];
int sect,det,ans;
bool on;
void dfs(int x) {
	vis[x]++;
	int y = a[x];
	if (vis[y] == 0)dfs(y);
	else if (vis[y] == 2) {
		vis[x] ++;
		return;
	}
	else if (vis[y] == 1) {
		sect = y;
		on = 1;
		det = c[x];
	}
	if (on)det = min(det, c[x]);
	if (x == sect)on = 0,ans+=det;
	vis[x]++;
}
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", c + i);
	for (i = 1; i <= n; i++) scanf("%d", a + i);
	for (i = 1; i <= n; i++) {
		if (vis[i] == 0)dfs(i);
	}
	printf("%d", ans);
	getchar(); getchar();
}