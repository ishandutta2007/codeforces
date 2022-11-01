#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int T;
int n, m, s, t;
vector<int> v[maxn], w[maxn];
int x, y;
int dep[maxn], fa[maxn][25], lg[maxn];
bool vis[maxn];

void dfs(int i){
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(dep[to]){
			if(to ^ fa[i][0]){
				int x = i;
				for(int k = 20;~k;k--) if((dep[i] - dep[to] - 1) & (1 << k)) x = fa[x][k];
				w[x].push_back(i);
			}
			continue;
		}
		fa[to][0] = i;
		dep[to] = dep[i] + 1;
		dfs(to);
	}
}

queue<pair<int, int> > q;
vector<pair<int, int> > ans;

int main(){
	scanf("%d", &T);
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	while(T--){
		scanf("%d%d%d%d", &n, &m, &s, &t);
		for(int i = 1;i <= n;i++){
			v[i].clear(), w[i].clear(), dep[i] = 0, vis[i] = false;
			memset(fa[i], 0, sizeof(fa[i]));
		}
		for(int i = 1;i <= m;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		ans.clear();
		dep[s] = 1, dfs(s);
		q.push({t, 0});//0 1 
		while(!q.empty()){
			int x = q.front().first, y = q.front().second, f = fa[x][0];q.pop();
			if(vis[x] || !f) continue;
			vis[x] = true;
			if(y) ans.push_back({x, f});
			else ans.push_back({f, x});
			q.push({f, y});
			for(int i = 0;i < w[x].size();i++){
				int to = w[x][i];
				if(y) ans.push_back({to, f});
				else ans.push_back({f, to});
				q.push({to, y ^ 1});
			}
		}
		if(ans.size() < m){
			puts("No");
		}else{
			puts("Yes");
			for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
}