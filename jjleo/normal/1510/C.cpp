#include <bits/stdc++.h>
#define maxn 150086

using namespace std;

int n, m, k;
vector<pair<int, int> > v[maxn];
bool del[maxn];
int x, y, z;
int fa[maxn], val[maxn];
int dep[maxn];
vector<pair<int, int> > ans; 
bool vis[maxn];

void dfs1(int i){
	dep[i] = dep[fa[i]] + 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, id = v[i][j].second;
		if(to == fa[i]) continue;
		if(!dep[to]) fa[to] = i, val[to] = id, dfs1(to);
		else if(dep[to] < dep[i]){
			del[id] = true;
			int x = i;
			while(x ^ to) del[val[x]] = true, x = fa[x];
		}
	}
}

int dfs2(int i, int fa){
	vis[i] = true;
	int sum = 0;
	for(int j = 0;j < v[i].size();j++) if(!del[v[i][j].second]) sum ^= 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, id = v[i][j].second;
		if(to == fa || del[id]) continue;
		if(dfs2(to, i) && sum) sum = 0, del[id] = true;
	}
	return sum;
}

int dfs3(int i, int fa){
	vis[i] = true;
	int last = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, id = v[i][j].second;
		if(to == fa || del[id]) continue;
		int x = dfs3(to, i);
		if(x){
			if(!last) last = x;
			else ans.push_back({last, x}), last = 0;
		}
	}
	return last ? last : i;
}

int main(){
	while(1){
		scanf("%d%d", &n, &k);
		if(!n) return 0;
		for(int i = 1;i <= n;i++) v[i].clear(), dep[i] = 0, vis[i] = false;
		m = 0;
		while(k--){
			scanf("%d%d", &z, &x), z--;
			while(z--){
				scanf("%d", &y);
				del[++m] = false;
				v[x].push_back({y, m}), v[y].push_back({x, m});
				x = y;
			}
		}
		dfs1(1);
		for(int i = 1;i <= n;i++) if(!vis[i]) dfs2(i, 0);
		for(int i = 1;i <= n;i++) vis[i] = false;
		ans.clear();
		for(int i = 1;i <= n;i++) if(!vis[i]){
			int x = dfs3(i, 0);
			if(x ^ i) ans.push_back({x, i});
		}
		printf("%d\n", ans.size());
		for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
	}
}