#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<int> v[maxn];
int f[maxn], g[maxn];

void dfs(int i){
	g[i] = 1;
	for(auto to : v[i]){
		dfs(to);
		f[i] += f[to];
		g[i] = max(g[i], g[to] + 1);
	}
	f[i] = max(f[i], g[i]);
}

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++){
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	dfs(1);
	printf("%d", f[1]);
}