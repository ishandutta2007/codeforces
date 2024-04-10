#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n, k;
vector<int> v[maxn], w[maxn], V[maxn], ans;
int x, y;
int to[maxn];
int cnt, tot;
int col[maxn], id[maxn];
int fa[maxn];
int deg[maxn];

void dfs(int i){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		dfs(to);
	} 
}

queue<int> q;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &fa[i]), v[fa[i]].push_back(i);
	while(k--){
		scanf("%d%d", &x, &y);
		to[x] = y;
		deg[y]++;
	}
	for(int i = 1;i <= n;i++){
		if(deg[i]) continue;
		++cnt;
		x = i;
		while(1){
			if(col[x]) return printf("0"), 0;
			id[x] = ++tot;
			col[x] = cnt;
			w[cnt].push_back(x);
			if(!to[x]) break;
			x = to[x];
		}
	}
	if(tot < n) return printf("0"), 0;
	for(int i = 1;i <= cnt;i++) deg[i] = 0;
	for(int i = 1;i <= n;i++) if(!fa[i]) dfs(i);
	for(int i = 1;i <= n;i++){
		if(!fa[i] || (col[i] == col[fa[i]] && id[i] > id[fa[i]])) continue;
		V[col[fa[i]]].push_back(col[i]);
		deg[col[i]]++;
	}
	for(int i = 1;i <= cnt;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x = q.front();
		ans.push_back(x);
		q.pop();
		for(int i = 0;i < V[x].size();i++){
			int to = V[x][i];
			deg[to]--;
			if(!deg[to]) q.push(to);
		} 
	}
	if(ans.size() < cnt) return printf("0"), 0;
	for(int i = 0;i < ans.size();i++){
		x = ans[i];
		for(int j = 0;j < w[x].size();j++) printf("%d ", w[x][j]);
	}
}