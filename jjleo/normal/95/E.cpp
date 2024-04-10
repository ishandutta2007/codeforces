#include <bits/stdc++.h>
#define maxn 300086
using namespace std;

int n, m;
int a[maxn], cnt;
int b[maxn], tot;
int c[maxn];
int W[maxn], V[maxn], n0;

void Dfs(int d, int x){
	if(d > 5) return;
	Dfs(d + 1, a[++cnt] = x * 10 + 4), Dfs(d + 1, a[++cnt] = x * 10 + 7);
}

bool vis[maxn];
vector<int> v[maxn];
int x, y;

void dfs(int i, int x){
	vis[i] = true, ++b[x];
	for(int j = 0;j < v[i].size();j++) if(!vis[v[i][j]]) dfs(v[i][j], x);
}

int f[maxn];
int ans = 0x3f3f3f3f;

int main(){
	scanf("%d%d", &n, &m);
	Dfs(1, 0);
	sort(a + 1, a + 1 + cnt);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) if(!vis[i]) dfs(i, ++tot);
	for(int i = 1;i <= n;i++) ++c[b[i]];
	for(int i = 1;i <= n;i++){
		if(!c[i]) continue;
		int j = 1;
		while(c[i] - j > 0){//debug:W V W  V 
			W[++n0] = i * j, V[n0] = j;
			c[i] -= j, j <<= 1;
		}
		W[++n0] = i * c[i], V[n0] = c[i];
	}
	memset(f, 0x3f, sizeof(f)), f[0] = 0;
	for(int i = 1;i <= n0;i++){
		for(int j = n;j;j--){
			if(j - W[i] >= 0) f[j] = min(f[j], f[j - W[i]] + V[i]);
		}
	}
	for(int i = 1;i <= cnt;i++){
		if(a[i] > n) break;
		ans = min(ans, f[a[i]] - 1);
	}
	printf("%d", ans >= n ? -1 : ans);
}