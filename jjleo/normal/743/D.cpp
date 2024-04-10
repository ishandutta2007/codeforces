#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

typedef long long ll;

int n, x, y;
int a[maxn];
vector<int> v[maxn];
ll f[maxn], siz[maxn];
ll ans = -1e18;

void dfs(int i, int fa){
	f[i] = -1e18;
	siz[i] = a[i];
	ll x = -1e18, y = -1e18;
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j] != fa){
			dfs(v[i][j], i);
			f[i] = max(f[i], f[v[i][j]]);
			siz[i] += siz[v[i][j]];
			
			if(f[v[i][j]] >= x) y = x, x = f[v[i][j]];
			else if(f[v[i][j]] > y) y = f[v[i][j]];
		}
	}
	f[i] = max(f[i], siz[i]);
	ans = max(ans, x + y);
} 

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0);
	if(ans <= -1e15) printf("Impossible");
	else printf("%lld", ans);
}