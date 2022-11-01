#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n;
vector<pair<int, int> > v[maxn];
int a[maxn], b[maxn];

void dfs(int i, int fa, int dep){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, co = v[i][j].second;
		if(to == fa) continue;
		if(dep & 1){
			b[co] = to - 1;
			a[to] = to + n - 1;
		}else{
			b[co] = to + n - 1;
			a[to] = to - 1;
		}
		dfs(to, i, dep + 1);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n = 1 << n;
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back({y, i}), v[y].push_back({x, i});
		}
		dfs(1, 0, 0);
		printf("%d\n%d ", 1, n);
		for(int i = 2;i <= n;i++) printf("%d ", a[i]);puts("");
		for(int i = 1;i < n;i++) printf("%d ", b[i]);puts("");
	}
}