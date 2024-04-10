#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k, K;
int fa[maxn], dep[maxn];
bool vis[maxn];
vector<int> v[maxn], ans;

void dfs(int i){
	ans.push_back(i), k--;
	if(vis[i]) K--;
	if(k == 0) return;
	for(int j = 0;j < v[i].size() && k > K;j++){
		int to = v[i][j];
		if(vis[to]) continue;
		dfs(to), ans.push_back(i);
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]) dfs(to);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) v[i].clear(), vis[i] = false;
		for(int i = 2;i <= n;i++) scanf("%d", &fa[i]), v[fa[i]].push_back(i), dep[i] = dep[fa[i]] + 1;
		int x = 1;
		for(int i = 2;i <= n;i++) if(dep[i] > dep[x]) x = i;
		K = dep[x] + 1;
		while(x) vis[x] = true, x = fa[x];
		ans.clear(), dfs(1);
		printf("%d\n", ans.size() - 1);
		for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);puts("");
	}
}