#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
int x, y;
vector<int> v[maxn];
int dep[maxn], son[maxn];

void dfs1(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		if(!son[i] || dep[to] > dep[son[i]]) son[i] = to;
	}
	if(son[i]) dep[i] = dep[son[i]] + 1;
}

int *f[maxn], ans[maxn];
int buf[maxn], *now = buf;

void dfs2(int i, int fa){
	f[i][0] = 1;
	if(son[i]){
		f[son[i]] = f[i] + 1;
		dfs2(son[i], i);
		ans[i] = ans[son[i]] + 1;
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa || to == son[i]) continue;
		f[to] = now, now += dep[to] + 1;
		dfs2(to, i);
		for(int k = 1;k <= dep[to] + 1;k++){
			f[i][k] += f[to][k - 1];
			if(f[i][k] > f[i][ans[i]] || f[i][k] == f[i][ans[i]] && k < ans[i]) ans[i] = k;
		}
	}
	if(f[i][ans[i]] == 1) ans[i] = 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs1(1, 0);
	f[1] = now, now += dep[1] + 1;
	dfs2(1, 0);
	for(int i = 1;i <= n;i++) printf("%d\n", ans[i]);
}