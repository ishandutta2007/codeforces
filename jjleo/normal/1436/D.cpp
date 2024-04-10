#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
vector<int> v[maxn];
int siz[maxn], a[maxn];
ll f[maxn], g[maxn];
int x;

void dfs(int i){
	siz[i] = v[i].empty();
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		dfs(to);
		if(f[to] > f[i]){
			g[i] += siz[i] * (f[to] - f[i]);
			f[i] = f[to];
		}else{
			g[i] += siz[to] * (f[i] - f[to]);
		}
		g[i] += g[to];
		siz[i] += siz[to];
	}
	if(a[i] <= g[i]){
		g[i] -= a[i];
	}else{
		a[i] -= g[i];
		f[i] += (a[i] + siz[i] - 1) / siz[i];
		g[i] = a[i] % siz[i] ? (siz[i] - a[i] % siz[i]) : 0;
	}
	//printf("%d %lld %lld--\n", i, f[i], g[i]);
}

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++) scanf("%d", &x), v[x].push_back(i);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	dfs(1);
	printf("%lld", f[1]);
}