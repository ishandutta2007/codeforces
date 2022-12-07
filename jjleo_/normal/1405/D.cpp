#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, a, b, da, db;
vector<int> v[maxn];
int x, y;
int dia, dep[maxn];

int dfs(int i, int fa){
	dep[i] = dep[fa] + 1;
	int mx = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		int val = dfs(to, i) + 1;
		dia = max(dia, mx + val);
		mx = max(mx, val);
	}
	return mx;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dia = 0;
		dfs(a, 0);
		puts(2 * da >= min(db, dia) || da >= dep[b] - 1 ? "Alice" : "Bob");
	}
}