#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 5e5 + 10;

int n, q, v[N], h[N], ans[N], sz[N], son[N], d[N];
vector<int> G[N], arr[N];
char s[N];

void dfs0(int u, int fa = 0) {
	sz[u] = 1; son[u] = 0; d[u] = d[fa] + 1;
	for(int v : G[u]) if(v != fa) {
		dfs0(v, u); sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}

int cnt[N][26];

void dfs2(int u, int de, int fa = 0) {
	cnt[d[u]][s[u]] += de;
	for(int v : G[u]) if(v != fa) dfs2(v, de, u);
}

void dfs(int u, int fa = 0, bool del = 0) {
	for(int v : G[u]) if(v != fa && v != son[u]) dfs(v, u, 1);
	if(son[u]) dfs(son[u], u, 0);
	cnt[d[u]][s[u]] ++;
	for(int v : G[u]) if(v != fa && v != son[u]) dfs2(v, 1, u);
	for(int id : arr[u]) {
		int x = 0, y = 0;
		for(int i = 0; i < 26; i ++) if(cnt[h[id]][i]) {
			if(cnt[h[id]][i] & 1) x ++;
			else y ++;
		}
		if(x <= 1) ans[id] = 1;
		else ans[id] = 0;
	}
	if(del) dfs2(u, -1, fa);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 2, u; i <= n; i ++) {
		scanf("%d", &u);
		G[i].push_back(u);
		G[u].push_back(i);
	}
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i ++) s[i] -= 'a';
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d", v + i, h + i);
		arr[v[i]].push_back(i);	
	}
	dfs0(1); dfs(1);
	for(int i = 1; i <= q; i ++) 
		puts(ans[i] ? "Yes" : "No");
	return 0;
}