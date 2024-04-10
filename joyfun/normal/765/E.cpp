#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 200005;
int n;
vi g[N];
int p[N], pn, d[N], fa[N], vis[N];
int Q[N];

int bfs(int s) {
	memset(d, -1, sizeof(d));
	int qn = 0; Q[qn++] = s; d[s] = 0;
	for (int i = 0; i < qn; i++) {
		int u = Q[i];
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j];
			if (d[v] != -1) continue;
			d[v] = d[u] + 1;
			fa[v] = u;
			Q[qn++] = v;
		}
	}
	int ans = Q[0];
	for (int i = 0; i < qn; i++) if (d[ans] < d[Q[i]]) ans = Q[i];
	return ans;
}

void getp() {
	int s = bfs(1);
	int t = bfs(s);
	pn = 0;
	while (t != s) {
		p[pn++] = t;
		t = fa[t];
	}
	p[pn++] = s;
}

int dfs(int u, int p = -1) {
	int sb = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (vis[v] || v == p) continue;
		int tmp = dfs(v, u);
		if (tmp == -1) return -1;
		if (sb == 0) sb = tmp;
		else if (sb != tmp) return -1;
	}
	return sb + 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	getp();
	for (int i = 0; i < pn; i++) vis[p[i]] = 1;
	int f = 1;
	for (int i = 0; i < pn; i++) {
		int len = i < pn / 2 ? i + 1 : pn - i;
		if (pn % 2 && i == pn / 2) continue;
		int tmp = dfs(p[i]);
		if (tmp != 1 && tmp != len) {
			f = 0;
			break;
		}
	}
	if (pn % 2) {
		int u = p[pn / 2];
		int sb = 0;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (vis[v]) continue;
			int tmp = dfs(v);
			if (tmp == -1) {
				f = 0;
				break;
			}
			if (tmp == pn / 2) continue;
			if (sb == 0) sb = tmp;
			else if (sb != tmp) {
				f = 0;
				break;
			}
		}
		pn = pn / 2 + 1 + sb;
	}
	if (f == 0) printf("-1\n");
	else {
		while (pn % 2) pn = pn / 2 + 1;
		printf("%d\n", pn - 1);
	}
	return 0;
}