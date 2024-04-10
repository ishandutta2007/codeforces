#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct top {
	int a[10];
	top() {
		memset(a, 0x3f, sizeof(a));
	}
	int operator[](int x) {
		return a[x];
	}
	void add(int x) {
		if (x < a[9])a[9] = x;
		for (int i = 8; i >= 0; i--)if (a[i + 1] < a[i])swap(a[i + 1], a[i]);
	}
};
top merge(top a, top b) {
	top c;
	for (int i = 0; i < 10; i++)c.add(a[i]), c.add(b[i]);
	return c;
}
int anc[100001][17],d[100001];
top th[100001][17];
vector<int> g[100001];
top ans;
void dfs(int x, int p) {
	for (int y : g[x]) {
		if (y == p)continue;
		anc[y][0] = x;
		d[y] = d[x] + 1;
		dfs(y, x);
	}
}
int climb(int y, int num) {
	for (int i = 0; i < 17; i++)if ((num >> i) & 1)ans = merge(ans, th[y][i]), y = anc[y][i];
	return y;
}
int main() {
	int n, m, q,i,j,a,b,c;
	scanf("%d%d%d", &n, &m, &q);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b),g[a].push_back(b), g[b].push_back(a);
	for (i = 1; i <= m; i++)scanf("%d", &a), th[a][0].add(i);
	anc[1][0]=1;
	dfs(1, 0);
	for (i = 1; i < 17; i++)for (j = 1; j <= n; j++)anc[j][i] = anc[anc[j][i - 1]][i - 1], th[j][i] = merge(th[j][i - 1], th[anc[j][i - 1]][i - 1]);
	while (q--) {
		scanf("%d%d%d", &a, &b, &c);
		ans = top();
		if (d[a] > d[b])a = climb(a, d[a] - d[b]);
		else b = climb(b, d[b] - d[a]);
		for (i = 16; i >= 0; i--) {
			if (anc[a][i] == anc[b][i])continue;
			ans = merge(ans, th[a][i]);
			ans = merge(ans, th[b][i]);
			a = anc[a][i];
			b = anc[b][i];
		}
		if (a != b)ans = merge(ans, merge(th[a][0], th[b][0])),a=anc[a][0];
		ans = merge(ans, th[a][0]);
		vector<int> pr;
		for (i = 0; i < 10; i++)if (ans[i] != 0x3f3f3f3f)pr.push_back(ans[i]);
		printf("%d ", min(c, (int)pr.size()));
		for (i = 0; i < min(c, (int)pr.size()); i++)printf("%d ", pr[i]);
		printf("\n");
	}
}