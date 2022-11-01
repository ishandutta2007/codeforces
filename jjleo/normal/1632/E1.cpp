#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t, n;
vector<int> v[maxn];
int x, y;
int f[maxn];

int dfs(int i, int fa, int dep){
	int mx = dep;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		int val = dfs(to, i, dep + 1);
		f[min(mx, val)] = max(f[min(mx, val)], mx + val - 2 * dep);
		mx = max(mx, val);
	}
	return mx;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear(), f[i] = 0;
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x); 
		}
		int mx = dfs(1, 0, 0);
		for(int i = n - 1;i;i--) f[i] = max(f[i], f[i + 1]);
		int x = 1;
		for(int i = 1;i <= n;i++){
			while(x < mx && (f[x + 1] + 1) / 2 + i > x) x++;
			printf("%d ", x);
		}
		puts("");
	}	
}