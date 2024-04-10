#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, x, y;
vector<int> v[maxn], w[maxn];
int fa[maxn];
int a[maxn];

void dfs(int i, int dep){
	if(dep) w[dep].push_back(i);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		fa[to] = i, dfs(to, dep + 1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0);
	int cnt = 0;
	for(int i = 1;i <= n;i++) for(int j = 0;j < w[i].size();j++) a[++cnt] = w[i][j];
	printf("? %d ", n);
	for(int i = 1;i <= n;i++) printf("%d ", i);
	puts(""), fflush(stdout);
	int mx;
	scanf("%d", &mx);
	int l = 1, r = cnt, mid;
	while(l < r){
		mid = l + r >> 1;
		printf("? %d 1 ", mid + 1);
		for(int i = 1;i <= mid;i++) printf("%d ", a[i]);
		puts(""), fflush(stdout);
		scanf("%d", &x);
		if(x == mx) r = mid;
		else l = mid + 1;
	}
	printf("! %d %d", a[l], fa[a[l]]);
}