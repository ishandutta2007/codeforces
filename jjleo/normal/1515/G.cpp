#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, m, q;
int x, y, z;
vector<pair<int, int> > v[maxn], w[maxn];
bool vis[maxn];
int a[maxn], cnt, id[maxn];
ll f[maxn], g[maxn];

void dfs1(int i){
	if(vis[i]) return;
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++) dfs1(v[i][j].first);
	a[++cnt] = i;
}

void dfs2(int i){
	for(int j = 0;j < w[i].size();j++){
		int to = w[i][j].first, co = w[i][j].second;
		if(!id[to]) id[to] = id[i], f[to] = f[i] + co, dfs2(to);
		if(id[i] == id[to]) g[id[i]] = __gcd(g[id[i]], f[i] + co - f[to]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({y, z}), w[y].push_back({x, z}); 
	}
	for(int i = 1;i <= n;i++) dfs1(i);
	for(int i = n;i;i--) if(!id[a[i]]) id[a[i]] = a[i], dfs2(a[i]);
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d", &x, &y, &z);
		puts(y % __gcd(g[id[x]], 1ll * z) ? "NO" : "YES");
	}
}