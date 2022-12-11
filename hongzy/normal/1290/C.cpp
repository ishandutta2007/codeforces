#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 6e5 + 10;
int n, m, ans, rt[N], fa[N], sz[N], cost[N];
vector<int> G[N];
bool use[N], rev[N];
char s[N];
void dfs(int u, int bel) {
	rt[u] = bel; if(bel) sz[bel] ++;
	for(int i = 0; i < (int) G[u].size(); i ++) {
		dfs(G[u][i], bel);
	}
}
int cur;
void upd(int u) {
	int x = u > n ? u - n : u;
	if(x >= cur) s[x] ^= 1, rt[u] = 0;
	for(int i = 0; i < (int) G[u].size(); i ++) {
		upd(G[u][i]);
	}
}
void merge(int x, int y, bool uprev = 0) {
	if(sz[x] < sz[y]) swap(x, y);
	if(y == 0) { if(rev[x]) upd(x); else dfs(x, 0); return ; }
	if(uprev) { if(rev[x] ^ rev[y]) upd(y); }
	dfs(y, x); fa[y] = x; G[x].push_back(y); cost[x] += cost[y];
}
void chose(int x, int y) {
	if(x == 0 || y == 0) {
		x ^= y; ans += cost[x];
		if(!rev[x]) upd(x);
		else dfs(x, 0);
		cost[x] = 0; return ;
	}
	if(cost[y] > cost[x]) swap(x, y);
	ans += cost[y]; cost[y] *= -1;
	if(sz[y] <= sz[x]) {
		if(rev[x] == rev[y]) upd(y);
		merge(x, y);
	} else {
		if(rev[y]) {
			rev[y] = 0; merge(y, x, 1);
		} else {
			rev[y] = 1;
			if(!rev[x]) upd(x);
			merge(y, x);
		}
	}
}
int main() {
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1; i <= n; i ++) s[i] -= '0';
	for(int i = 1; i <= m; i ++) {
		int c, x; scanf("%d%d", &c, &x);
		if(use[x]) x += n; else use[x] = 1;
		int y = x; rt[y] = y; fa[y] = 0; cost[y] = 1; sz[y] = c;
		for(int j = 2; j <= c; j ++) {
			scanf("%d", &x);
			if(use[x]) x += n; else use[x] = 1;
			sz[x] = 1; fa[x] = y; rt[x] = y; G[y].push_back(x);
		}
	}
	for(int i = 1; i <= n; i ++) {
		cur = i;
		if(rt[i] != rt[i + n]) {
			if(rev[rt[i]]) s[i] ^= 1;
			if(rev[rt[i + n]]) s[i] ^= 1;
			if(s[i] == 1) {
				merge(rt[i], rt[i + n], 1);
			} else {
				chose(rt[i], rt[i + n]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}