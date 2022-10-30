#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
vector<int> v[maxn];
int fa[maxn][25], dep[maxn], lg[maxn];

void dfs(int i){
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i][0]) continue;
		fa[to][0] = i, dep[to] = dep[i] + 1, dfs(to);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;i >= 0;i--) if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

inline int dis(int x, int y){
	return dep[x] + dep[y] - (dep[lca(x, y)] << 1);
}

int x, y, a, b, k;
int d, o;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1);
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d%d%d", &a, &b, &x, &y, &k);
		d = dis(x, y);
		if(d <= k && !((k - d) & 1)){
			puts("YES");
			continue;
		}
		o = dis(a, b) + 1;
		d = dis(x, a) + dis(a, y);
		if(d <= k && !((k - d) & 1)){
			puts("YES");
			continue;
		}
		if(d <= k && d + o <= k && !((k - (d + o)) & 1)){
			puts("YES");
			continue;
		}
		d = dis(x, b) + dis(b, y);
		if(d <= k && !((k - d) & 1)){
			puts("YES");
			continue;
		}
		if(d <= k && d + o <= k && !((k - (d + o)) & 1)){
			puts("YES");
			continue;
		}
		d = dis(x, a) + 1 + dis(b, y);
		if(d <= k && !((k - d) & 1)){
			puts("YES");
			continue;
		}
		if(d <= k && d + o <= k && !((k - (d + o)) & 1)){
			puts("YES");
			continue;
		}
		d = dis(x, b) + 1 + dis(a, y);
		if(d <= k && !((k - d) & 1)){
			puts("YES");
			continue;
		}
		if(d <= k && d + o <= k && !((k - (d + o)) & 1)){
			puts("YES");
			continue;
		}
		puts("NO");
	} 
}