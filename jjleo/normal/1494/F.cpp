#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
vector<pair<int, int> > v[maxn];
vector<int> ans;
bool tag[maxn], del[maxn], vis[maxn];
int cur[maxn], deg[maxn], x, y;

void dfs1(int i){
	if(vis[i]) return;
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++) if(!del[v[i][j].second]) dfs1(v[i][j].first);//debug37 ??? 
}

void dfs2(int i){
	for(int &j = cur[i];j < v[i].size();j++){
		if(del[v[i][j].second]) continue;
		del[v[i][j].second] = true;
		dfs2(v[i][j].first);
	}
	ans.push_back(i); 
}

void solve(int x){
	vector<int> v;
	for(int i = 1;i <= n;i++) if(deg[i] & 1) v.push_back(i);
	if(!v.empty() && v.size() != 2 || v.size() == 2 && x && v[0] != x && v[1] != x) return;
	if(!x) x = v.empty() ? 1 : v[0];
	for(int i = 1;i <= n;i++) vis[i] = false;
	dfs1(x);
	for(int i = 1;i <= n;i++) if(deg[i] && !vis[i]) return;
	dfs2(x);
	ans.push_back(-1);
	for(int i = 1;i <= n;i++) if(tag[i]) ans.push_back(i), ans.push_back(x);
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
	exit(0); 
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back({y, i}), v[y].push_back({x, i});
		deg[x]++, deg[y]++;
	} 
	solve(0);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j].first, id = v[i][j].second;
			if(deg[to] & 1) deg[i]--, deg[to]--, del[id] = tag[to] = true;
		}
		solve(i);
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j].first, id = v[i][j].second;
			if(tag[to]) deg[i]++, deg[to]++, del[id] = tag[to] = false;
			else deg[i]--, deg[to]--, del[id] = tag[to] = true;
			solve(i);
			if(tag[to]) deg[i]++, deg[to]++, del[id] = tag[to] = false;
			else deg[i]--, deg[to]--, del[id] = tag[to] = true;
		}
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j].first, id = v[i][j].second;
			if(tag[to]) deg[i]++, deg[to]++, del[id] = tag[to] = false;
		}
	}
	printf("0");
}