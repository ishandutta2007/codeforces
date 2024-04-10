#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n;
int a[maxn], sum;
int x, y;
vector<int> v[maxn], w[maxn];
int siz[maxn];
bool vis[maxn];

void dfs(int i, int fa){
	siz[i] = a[i];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		if(siz[to] >= 2 || a[to]) w[to].push_back(i);
		if(sum - siz[to] >= 2 || a[i]) w[i].push_back(to);
		siz[i] += siz[to];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x); 
	}
	dfs(1, 0);
	queue<int> q;
	for(int i = 1;i <= n;i++) if(a[i]) vis[i] = true, q.push(i);
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int i = 0;i < w[x].size();i++){
			int to = w[x][i];
			if(!vis[to]) vis[to] = true, q.push(to);
		}
	}
	for(int i = 1;i <= n;i++) printf("%d ", vis[i]);
}