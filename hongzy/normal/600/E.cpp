#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int sz[N], son[N], col[N];
int tag[N], maxv;
long long sum, ans[N];
vector<int> G[N];

void dfs1(int u, int fa) {
	sz[u] = 1;
	for(int & v : G[u]) if(v != fa) {
		dfs1(v, u); sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}

int skip;
void ins(int u, int fa) {
	tag[col[u]] ++;
	if(tag[col[u]] > maxv) maxv = tag[col[u]], sum = 0;
	if(tag[col[u]] == maxv) sum += col[u];
	for(int & v : G[u]) if(v != fa && v != skip) ins(v, u);
}

void del(int u, int fa) {
	tag[col[u]] = 0;
	for(int & v : G[u]) if(v != fa) del(v, u);
}

void dfs2(int u, int fa, bool sav) {
	for(int & v : G[u]) if(v != fa && v != son[u])
		dfs2(v, u, 0);
	if(son[u]) dfs2(son[u], u, 1), skip = son[u];
	ins(u, fa); ans[u] = sum;
	if(!sav) del(u, fa), sum = maxv = 0;
}

int main() {
	int n, u, v; scanf("%d", &n);
	for(int i = 1; i <= n; i ++) 
		scanf("%d", &col[i]);
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0); dfs2(1, 0, 0);
	for(int i = 1; i <= n; i ++)
		printf("%I64d%c", ans[i], " \n"[i == n]);
	return 0;
}