#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
int x, y;
vector<int> v1[maxn], v2[maxn];
bool ins[maxn];
bool vis[maxn], vis1[maxn], vis2[maxn];
bool e[maxn];
int ans;

void dfs(int i){
	vis[i] = ins[i] = true;
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(ins[to]){
			printf("-1");
			exit(0);
		}
		if(!vis[to]) dfs(to);
	}
	ins[i] = false;
}

void dfs1(int i){
	vis1[i] = true;
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(!vis1[to]) dfs1(to);
	}
}

void dfs2(int i){
	vis2[i] = true;
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j];
		if(!vis2[to]) dfs2(to);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	ans = n;
	for(int i = 1;i <= m;i++) scanf("%d%d", &x, &y), v1[x].push_back(y), v2[y].push_back(x);
	for(int i = 1;i <= n;i++) if(!vis[i]) dfs(i);
	for(int i = 1;i <= n;i++){
		if(vis1[i]) e[i] = true;
		else dfs1(i);
		if(vis2[i]) e[i] = true;
		else dfs2(i);
		if(e[i]) ans--;
	}
	printf("%d\n", ans);
	for(int i = 1;i <= n;i++) printf("%c", e[i] ? 'E' : 'A');
}