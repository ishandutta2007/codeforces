#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n, m;
vector<int> v[maxn];
bool vis[maxn];
int f[maxn];
int sum, x, y;
queue<int> q;
vector<int> ans;

void dfs(int i){
	if(vis[i]) return;
	sum += vis[i] = true;
	for(int j = 0;j < v[i].size();j++) dfs(v[i][j]);
}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), vis[i] = false;
		while(m--){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		sum = 0, dfs(1);
		if(sum ^ n){
			puts("NO");
			continue;
		}
		for(int i = 1;i <= n;i++) vis[i] = false;
		ans.clear();
		f[1] = 1, q.push(1), vis[1] = true;
		while(!q.empty()){
			int x = q.front();q.pop();
			if(f[x]) ans.push_back(x);
			for(int i = 0;i < v[x].size();i++){
				int to = v[x][i];
				if(!f[x] && vis[to]) continue;
				if(!vis[to]) q.push(to), vis[to] = true;
				f[to] = f[x] ^ 1;
			}
		}
		printf("YES\n%d\n", ans.size());
		for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
		puts("");
	}
}