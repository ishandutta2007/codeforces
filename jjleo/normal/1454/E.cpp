#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
vector<int> v[maxn];
int x, y;

int fa[maxn];
bool vis[maxn];

void dfs1(int i){
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		if(vis[to]){
			x = to, y = i;
		}else{
			fa[to] = i;
			dfs1(to);
		}
	}
}

bool tag[maxn];
int siz[maxn];

void dfs2(int i, int fa){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa || tag[to]) continue;
		dfs2(to, i);
		siz[i] += siz[to];
	}
}

vector<int> w;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear(), vis[i] = false, tag[i] = false;
		for(int i = 1;i <= n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs1(1);
		w.clear();
		while(1){
			w.push_back(x);
			tag[x] = true;
			if(x == y) break;
			x = fa[x];
		}
		long long ans = 0;
		for(int i = 0;i < w.size();i++){
			dfs2(w[i], 0);
			ans += 1ll * siz[w[i]] * (siz[w[i]] - 1) / 2;
		}
		for(int i = 0;i < w.size();i++){
			ans += 1ll * siz[w[i]] * (n - siz[w[i]]);
		}
		printf("%lld\n", ans);
	}
}