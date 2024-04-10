#include <bits/stdc++.h>
#define maxn 6086

using namespace std;

int t;
int n, m;
int l[maxn], r[maxn];
vector<int> a, v[maxn];
int f[maxn][maxn];

int dfs(int l, int r){
	if(l > r) return 0;
	if(f[l][r] != -1) return f[l][r];
	f[l][r] = dfs(l + 1, r);
	int x = 0;
	for(int i = 0;i < v[l].size();i++){
		//printf("%d %d %d %d %d--\n", l, r, f[l][r], x, v[l][i]);
		if(v[l][i] > r) continue;
		if(v[l][i] == r) x++;
		else f[l][r] = max(f[l][r], dfs(l, v[l][i]) + dfs(v[l][i] + 1, r));
		
	}
	
	return f[l][r] += x; 
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d%d", &l[i], &r[i]);
			a.push_back(l[i]), a.push_back(r[i]);
		}
		sort(a.begin(), a.end());
		m = unique(a.begin(), a.end()) - a.begin();
		for(int i = 1;i <= m;i++) v[i].clear();
		for(int i = 1;i <= n;i++){
			v[lower_bound(a.begin(), a.begin() + m, l[i]) - a.begin() + 1].push_back(lower_bound(a.begin(), a.begin() + m, r[i]) - a.begin() + 1);
		}
		for(int i = 1;i <= m;i++) for(int j = 1;j <= m;j++) f[i][j] = -1;
		printf("%d\n", dfs(1, m));
	}
}