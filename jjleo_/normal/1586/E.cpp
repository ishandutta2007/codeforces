#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n, m, q;
int x, y;
vector<int> v[maxn];
int f[maxn], a[maxn], b[maxn];
bool vis[maxn];
int fa[maxn], dep[maxn];

void dfs(int i){
	vis[i] = true, dep[i] = dep[fa[i]] + 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]) continue;
		fa[to] = i, dfs(to);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	scanf("%d", &q);
	for(int i = 1;i <= q;i++) scanf("%d%d", &a[i], &b[i]), f[a[i]]++, f[b[i]]++;
	int sum = 0;
	for(int i = 1;i <= n;i++) sum += f[i] & 1;
	if(sum) return printf("NO\n%d", sum / 2), 0;
	dfs(1);
	puts("YES");
	for(int i = 1;i <= q;i++){
		int x = a[i], y = b[i];
		vector<int> a, b;
		while(x ^ y){
			if(dep[x] > dep[y]) a.push_back(x), x = fa[x];
			else b.push_back(y), y = fa[y];
		}
		a.push_back(x);
		printf("%d\n", a.size() + b.size());
		for(int j = 0;j < a.size();j++) printf("%d ", a[j]);
		for(int j = (int)b.size() - 1;j >= 0;j--) printf("%d ", b[j]);
		puts("");
	}
}