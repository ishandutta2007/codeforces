#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, x, y;
vector<int> v[maxn];
int ans;
int dep[maxn], f[maxn];

void dfs(int i, int fa){
	dep[i] = dep[fa] + 1;
	bool tag = false;
	if(i == 1){
		f[i] = 0;
		int I = 0;
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j];
			if(to == fa) continue;
			tag = true;
			dfs(to, i);
			if(f[to] > f[i]){
				f[i] = f[to];
				I = to;
			}
		}
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j];
			if(to == fa) continue;
			if(I != to) ans = max(ans, f[to] - dep[i] + 1); 
		} 
		return;
	}
	f[i] = 1e9;
	int I = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		tag = true;
		dfs(to, i);
		if(f[to] < f[i]){
			f[i] = f[to];
			I = to;
		}
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		if(I != to) ans = max(ans, f[to] - dep[i] + 1); 
	} 
	if(!tag){
		f[i] = dep[i];
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x); 
		}
		ans = 0;
		dep[0] = -1;
		dfs(1, 0);
		printf("%d\n", max(ans, f[1]));
	}
}