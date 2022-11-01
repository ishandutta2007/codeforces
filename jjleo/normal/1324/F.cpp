#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

int n, a[maxn], f[maxn], ans[maxn];
vector<int> v[maxn];
int x, y;

void dfs1(int i, int fa){
	f[i] = a[i];
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j] != fa){
			dfs1(v[i][j], i);
			if(f[v[i][j]] > 0) f[i] += f[v[i][j]];
		}
	}
}

void dfs2(int i, int fa){
	ans[i] = f[i];
	if(i ^ 1) ans[i] += max(ans[fa] - (f[i] > 0 ? f[i] : 0), 0);
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j] != fa) dfs2(v[i][j], i);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		if(!a[i]) a[i] = -1;
	}
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
}