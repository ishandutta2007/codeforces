#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
vector<pair<int, int> > v[maxn];
vector<int> w[maxn];
int opt, x, y;
bool vis[maxn];
int col[maxn], deg[maxn];
int a[maxn]; 

void dfs(int i){
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(!vis[to]) col[to] = col[i] ^ 1, dfs(to);
		if(col[to] ^ col[i] ^ 1) printf("NO"), exit(0);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d%d", &opt, &x, &y);
		v[x].push_back({y, opt}), v[y].push_back({x, opt});
	}
	for(int i = 1;i <= n;i++) if(!vis[i]) dfs(i);
	for(int i = 1;i <= n;i++) for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, co = v[i][j].second;
		if(col[i] == 0 && co == 1 || col[i] == 1 && co == 2) w[i].push_back(to), deg[to]++;
	}
	queue<int> q;
	for(int i = 1;i <= n;i++) if(deg[i] == 0) q.push(i);
	m = 0;
	while(!q.empty()){
		int x = q.front();q.pop();
		a[x] = ++m;
		for(int i = 0;i < w[x].size();i++){
			int to = w[x][i];
			deg[to]--;
			if(deg[to] == 0) q.push(to);
		}
	}
	if(m < n) return printf("NO"), 0;
	puts("YES");
	for(int i = 1;i <= n;i++) printf("%c %d\n", col[i] == 0 ? 'L' : 'R', a[i]);
}