#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int th;
vector<pii> g[100001];
int d[100001];
void dfs(int x) {
	for (pii p : g[x]) {
		if (p.second >= th)continue;
		int y = p.first;
		if(d[y]==-1)dfs(y);
		d[x] = max(d[x], d[y] + 1);
	}
	if (d[x] == -1)d[x] = 1;
}
int main() {
	int n, m, a, b,i,j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back({ b,i });
	}
	int cur = -1;
	for (i = 1 << 17; i; i >>= 1) {
		memset(d, -1, sizeof(d));
		th = cur + i;
		for (j = 1; j <= n; j++)if (d[j] == -1)dfs(j);
		bool suc = 0;
		for (j = 1; j <= n; j++)suc |= (d[j] == n);
		if (!suc)cur += i;
	}
	if (cur > m)printf("-1");
	else printf("%d", cur+1);
}