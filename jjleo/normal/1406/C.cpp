#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x, y;
vector<int> v[maxn];
int siz[maxn], fa[maxn];

void dfs(int i, int f){
	fa[i] = f, siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == f) continue;
		dfs(to, i);
		siz[i] += siz[to];
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
		dfs(1, 0);
		int id = 0;
		for(int i = 1;i <= n;i++){
			if(n - siz[i] == siz[i]){
				id = i;
				break;
			}
		}
		if(!id){
			printf("%d %d\n%d %d\n", 1, v[1][0], 1, v[1][0]);
			continue;
		}
		for(int i = 0;i < v[id].size();i++){
			int to = v[id][i];
			if(to != fa[id]){
				x = to;
				break;
			}
		}
		printf("%d %d\n%d %d\n", id, x, fa[id], x);
	}
}