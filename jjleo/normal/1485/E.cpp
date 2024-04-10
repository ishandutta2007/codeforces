#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n;
int a[maxn], x;
vector<int> v[maxn], w[maxn];
int dep[maxn], d;
int mx[maxn], mn[maxn];
ll f[maxn], ans;
int fa[maxn];

void dfs(int i){
	d = max(d, dep[i]);
	mx[dep[i]] = max(mx[dep[i]], a[i]);
	mn[dep[i]] = min(mn[dep[i]], a[i]);
	w[dep[i]].push_back(i);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		dep[to] = dep[i] + 1;
		fa[to] = i;
		dfs(to);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			v[i].clear(), w[i].clear();
			mx[i] = 0, mn[i] = 1e9, f[i] = 0;
		}
		for(int i = 2;i <= n;i++){
			scanf("%d", &x);
			v[x].push_back(i), v[i].push_back(x);
		}
		for(int i = 2;i <= n;i++) scanf("%d", &a[i]);
		d = 0;
		dfs(1);
		for(int D = 1;D <= d;D++){
			ll A = -1e18, B = -1e18;
			for(int x = 0;x < w[D].size();x++){
				int i = w[D][x];
				f[i] = max(f[i], f[fa[i]] + max(abs(a[i] - mn[dep[i]]), abs(a[i] - mx[dep[i]])));
				A = max(A, f[fa[i]] + a[i]), B = max(B, f[fa[i]] - a[i]);
			} 
			for(int x = 0;x < w[D].size();x++){
				int i = w[D][x];
				f[i] = max(f[i], max(A - a[i], B + a[i]));
			} 
		}
		ans = 0;
		for(int i = 1;i <= n;i++) ans = max(ans, f[i]);
		printf("%lld\n", ans);
	}
}