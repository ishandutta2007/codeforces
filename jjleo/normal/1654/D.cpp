#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int t, n;
vector<tuple<int, int, int> > v[maxn];
int prm[maxn], cnt;
bool tag[maxn];
int f[maxn];
int inv[maxn], g[maxn];
int a[maxn], mx[maxn];
bool vis[maxn];
vector<int> w;

void dfs(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = get<0>(v[i][j]), x = get<1>(v[i][j]), y = get<2>(v[i][j]);
		if(to == fa) continue;
		g[to] = 1ll * g[i] * x % p * inv[y] % p; 
		while(x ^ 1) a[f[x]]--, x /= f[x];
		while(y ^ 1){
			a[f[y]]++, mx[f[y]] = max(mx[f[y]], a[f[y]]);
			if(!vis[f[y]]) vis[f[y]] = true, w.push_back(f[y]);
			y /= f[y];
		}
		dfs(to, i);
		x = get<1>(v[i][j]), y = get<2>(v[i][j]);
		while(x ^ 1) a[f[x]]++, x /= f[x];
		while(y ^ 1) a[f[y]]--, y /= f[y];
	}
}

int main(){
	for(int i = 2;i < maxn;i++){
		if(!tag[i]) prm[++cnt] = i, f[i] = i;
		for(int j = 1;j <= cnt && prm[j] * i < maxn;j++){
			tag[prm[j] * i] = true;
			f[prm[j] * i] = prm[j];
			if(i % prm[j] == 0) break;
		}
	}
	inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	scanf("%d", &t);
	while(t--){
		for(int i = 0;i < w.size();i++) vis[w[i]] = false, mx[w[i]] = 0, a[w[i]] = 0;
		w.clear();
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int I = 1;I < n;I++){
			int i, j, x, y;
			scanf("%d%d%d%d", &i, &j, &x, &y);
			v[i].push_back(make_tuple(j, y, x));
			v[j].push_back(make_tuple(i, x, y));
		}
		g[1] = 1;
		dfs(1, 0);
		int ans = 0;
		for(int i = 1;i <= n;i++) ans = (ans + g[i]) % p;
		for(int i = 0;i < w.size();i++) for(int j = 1;j <= mx[w[i]];j++) ans = 1ll * ans * w[i] % p;
		printf("%d\n", ans);
	}
}