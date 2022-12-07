#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
vector<int> v[maxn];
int deg[maxn];
int k, x;
queue<int> q;

int f[maxn];
bool vis[maxn];

void dfs(int i){
	if(vis[i]) return;
	vis[i] = true, f[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		dfs(to);
		f[i] = max(f[i], f[to] + (i > to));
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear(), vis[i] = false;
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &k);
			deg[i] = k;
			while(k--){
				scanf("%d", &x);
				v[x].push_back(i); 
			}
			if(deg[i] == 0) q.push(i), cnt++;
		}
		while(!q.empty()){
			int x = q.front();q.pop();
			for(int i = 0;i < v[x].size();i++){
				int to = v[x][i];
				deg[to]--;
				if(deg[to] == 0) q.push(to), cnt++;
			}
		}
		if(cnt < n){
			puts("-1");
			continue;
		}
		for(int i = 1;i <= n;i++) dfs(i);
		int ans = 0;
		for(int i = 1;i <= n;i++) ans = max(ans, f[i]);
		printf("%d\n", ans);
	}
}