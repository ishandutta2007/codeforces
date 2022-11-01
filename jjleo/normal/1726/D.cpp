#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, m;
vector<pair<int, int> > v[maxn];
bool vis[maxn];
int ans[maxn], Ans[maxn];

void dfs(int i, int d){
	vis[i] = true;
	for(auto it : v[i]){
		int to = it.first, id = it.second;
		if(vis[to]) continue;
		ans[id] = d;
		dfs(to, d ^ 1);
	} 
}

int a[maxn], b[maxn];
int fa[maxn], siz[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(siz[x] > siz[y]) swap(x, y);
	siz[y] += siz[x], fa[x] = y;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) ans[i] = -1;
		for(int i = 1;i <= n;i++) v[i].clear(), vis[i] = false;
		for(int i = 1;i <= m;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = x, b[i] = y;
			v[x].push_back({y, i}), v[y].push_back({x, i});
		}
		dfs(1, 0);
		vector<int> w;
		for(int i = 1;i <= m;i++) if(ans[i] == -1) w.push_back(i);
		int sum = n * 2;
		for(int s = 0;s < (1 << w.size());s++){
			int val = 0;
			for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1;
			for(int i = 1;i <= m;i++) if(ans[i] == 0) merge(a[i], b[i]);
			for(int i = 0;i < w.size();i++) if(!(s & (1 << i))) merge(a[w[i]], b[w[i]]);
			for(int i = 1;i <= n;i++) val += find(i) == i;
			for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1;
			for(int i = 1;i <= m;i++) if(ans[i] == 1) merge(a[i], b[i]);
			for(int i = 0;i < w.size();i++) if(s & (1 << i)) merge(a[w[i]], b[w[i]]);
			for(int i = 1;i <= n;i++) val += find(i) == i;
			if(val < sum){
				sum = val;
				for(int i = 0;i < w.size();i++) Ans[w[i]] = (s >> i) & 1;
			}
		}
		assert(sum == n * 2 - m);
		for(int i = 0;i < w.size();i++) ans[w[i]] = Ans[w[i]];
		for(int i = 1;i <= m;i++) printf("%d", ans[i]);puts("");
	}
}