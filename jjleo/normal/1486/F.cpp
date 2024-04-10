#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n, m;
vector<int> v[maxn];
int x, y;
int fa[maxn][25], dep[maxn], lg[maxn];

void dfs1(int i){
	dep[i] = dep[fa[i][0]] + 1;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i][0]) continue;
		fa[to][0] = i, dfs1(to);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int a[maxn], b[maxn];
vector<pair<int, int> > w[maxn];
int cnt[maxn];
map<pair<int, int>, int> mp;
long long ans;

void dfs2(int i){
	ans += 1ll * w[i].size() * ((int)w[i].size() - 1) / 2;
	for(int j = 0;j < w[i].size();j++){
		int x = w[i][j].first, y = w[i][j].second;
		if(x) ans -= cnt[x]++;
		if(y) ans -= cnt[y]++, ans += mp[w[i][j]]++;
	}
	mp.clear();
	for(int j = 0;j < w[i].size();j++){
		int x = w[i][j].first, y = w[i][j].second;
		cnt[x] = cnt[y] = 0;
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i][0]) continue;
		dfs2(to);
		a[i] += a[to];
	}
	for(int j = 0;j < w[i].size();j++){
		int x = w[i][j].first, y = w[i][j].second;
		ans += a[i] - a[x] - a[y];
	}
	a[i] += b[i];
}

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs1(1);
	scanf("%d", &m);
	while(m--){
		scanf("%d%d", &x, &y);
		if(x == y){
			w[x].push_back({0, 0});
			continue;
		}
		int z = lca(x, y);
		if(z == x){
			a[y]++;
			int Y = y;
			for(int i = 20;~i;i--) if((dep[y] - dep[z] - 1) & (1 << i)) Y = fa[Y][i];
			b[Y]--; 
			w[z].push_back({Y, 0}); 
		}else if(z == y){
			a[x]++;
			int X = x;
			for(int i = 20;~i;i--) if((dep[x] - dep[z] - 1) & (1 << i)) X = fa[X][i];
			b[X]--;
			w[z].push_back({X, 0}); 
		}else{
			a[x]++;
			int X = x;
			for(int i = 20;~i;i--) if((dep[x] - dep[z] - 1) & (1 << i)) X = fa[X][i];
			b[X]--;
			a[y]++;
			int Y = y;
			for(int i = 20;~i;i--) if((dep[y] - dep[z] - 1) & (1 << i)) Y = fa[Y][i];
			b[Y]--; 
			w[z].push_back({min(X, Y), max(X, Y)}); 
		}
	}
	dfs2(1);
	printf("%lld", ans);
}