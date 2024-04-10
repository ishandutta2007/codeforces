#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, m;
vector<int> v[maxn];
int d[maxn];
queue<int> q;
int ans[maxn];
int x, y;
bool vis[maxn];

void dfs(int i){
	if(vis[i]) return;
	vis[i] = true;
	ans[i] = d[i];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(d[to] == d[i] + 1){
			dfs(to);
			ans[i] = min(ans[i], ans[to]);
		}else if(d[to] < d[i]){
			ans[i] = min(ans[i], d[to]);
		}
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), d[i] = n, vis[i] = false;
		while(m--){
			scanf("%d%d", &x, &y);
			v[x].push_back(y); 
		}
		d[1] = 0;q.push(1);
		while(!q.empty()){
			int x = q.front();q.pop();
			for(int i = 0;i < v[x].size();i++){
				int to = v[x][i];
				if(d[to] > d[x] + 1){
					q.push(to);
					d[to] = d[x] + 1;
				}
			}
		}
		dfs(1);
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
		puts("");
	}
}