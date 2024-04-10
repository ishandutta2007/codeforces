#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n, q;
int Fa[maxn];
int find(int x){
	return x == Fa[x] ? x : Fa[x] = find(Fa[x]);
}

vector<pair<int, int> > v[maxn];
int x, y, z;
int lg[maxn], fa[maxn][25], dep[maxn], dfn[maxn], siz[maxn], cnt, val[maxn];
struct Edge{
	int x, y, z, i;
};
vector<Edge> w;
bool ans[maxn];

void dfs(int i){
	dfn[i] = ++cnt, siz[i] = 1;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, co = v[i][j].second;
		if(to == fa[i][0]) continue;
		fa[to][0] = i, dep[to] = dep[i] + 1, val[to] = val[i] ^ co, dfs(to), siz[i] += siz[to];
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int a[maxn];
inline void add(int x, int y){
	for(;x < maxn;x += x & -x) a[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += a[x];
	return sum;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) Fa[i] = i;
	for(int i = 1;i <= q;i++){
		scanf("%d%d%d", &x, &y, &z);
		if(find(x) == find(y)) w.push_back((Edge){x, y, z, i});
		else v[x].push_back({y, z}), v[y].push_back({x, z}), x = find(x), y = find(y), Fa[x] = y, ans[i] = true;
	}
	for(int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1;i <= n;i++) if(!fa[i][0]) dfs(i);
	for(int i = 0;i < w.size();i++){
		int x = w[i].x, y = w[i].y;
		if(!(val[x] ^ val[y] ^ w[i].z) || query(dfn[x]) + query(dfn[y]) - query(dfn[lca(x, y)]) * 2) continue;
		ans[w[i].i] = true;
		while(x ^ y){
			if(dep[x] > dep[y]) add(dfn[x], 1), add(dfn[x] + siz[x], -1), x = fa[x][0];
			else add(dfn[y], 1), add(dfn[y] + siz[y], -1), y = fa[y][0];
		}
	}
	for(int i = 1;i <= q;i++) puts(ans[i] ? "YES" : "NO");
}