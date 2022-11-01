// 
#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n, x, y;
vector<int> v[maxn];
int lg[maxn];
int fa[maxn][25], dep[maxn], siz[maxn];

void dfs(int i){
	dep[i] = dep[fa[i][0]] + 1, siz[i] = 1;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i][0]) continue;
		fa[to][0] = i, dfs(to);
		siz[i] += siz[to];
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

inline int dis(int x, int y){
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

inline pair<int, int> merge(int a, int b, int c){
	int ab = dis(a, b), ac = dis(a, c), bc = dis(b, c);
	if(ab + ac == bc) return {b, c};
	if(ac + bc == ab) return {a, b};
	if(bc + ab == ac) return {a, c};
	return {0, 0};
}

inline ll cal(int x, int y){
	if(x == y){
		ll ans = 0, sum = 1;
		for(int i = 0;i < v[x].size();i++){
			int to = v[x][i];
			if(to == fa[x][0]) continue;
			ans += sum * siz[to];
			sum += siz[to];
		}
		ans += sum * (n - siz[x]);
		return ans;
	}
	int z = lca(x, y);
	if(y == z) swap(x, y);
	if(x == z){
		int val = dep[y] - dep[x] - 1, s = siz[y];
		for(int i = 0;i <= 20;i++) if(val & (1 << i)) y = fa[y][i];
		return 1ll * s * (n - siz[y]);
	}else{
		return 1ll * siz[x] * siz[y];
	}
}

ll ans[maxn];

int main(){
	scanf("%d", &t);
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			x++, y++;
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs(1);
		ans[0] = 1ll * n * (n - 1) / 2 - cal(1, 1);
		for(int i = 1;i <= n;i++) ans[i] = 0;
		for(int i = 1;i <= n;i++){
			pair<int, int> p;
			if(i == 1) p = {1, 1}, x = y = 1;
			else{
				p = merge(x, y, i);
				if(!p.first) break;
			}
			ans[i] += cal(p.first, p.second);
			x = p.first, y = p.second;
			if(i < n) {
				p = merge(x, y, i + 1);
				if(p.first) ans[i] -= cal(p.first, p.second);
			}
		}
		for(int i = 0;i <= n;i++) printf("%lld ", ans[i]);puts("");
	}
}