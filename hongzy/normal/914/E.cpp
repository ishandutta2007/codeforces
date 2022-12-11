#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
const int M = 1 << 20;
const int mo = 1e9 + 7;
int n, lim, size, rt, sz[N], f[N], a[N];
vector<int> G[N];
char s[N], sol[N];
ll ans[N], cur[N], tmp;
void findrt(int u, int fa = 0) {
	f[u] = 0; sz[u] = 1;
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i];
		if(v == fa || sol[v]) continue ;
		findrt(v, u); sz[u] += sz[v];
		f[u] = max(f[u], sz[v]);
	}
	f[u] = max(f[u], size - sz[u]);
	if(!rt || f[u] < f[rt]) rt = u;
}
int son[N], sl, nu, cnt[M], li[N];
void dfs(int u, int fa, int st) {
	st ^= 1 << s[u]; li[++ li[0]] = st; cur[u] = 0;
	for(int i = -1; i < lim; i ++) { //x = y ^ st
		int y = ~ i ? 1 << i : 0;
		cur[u] += cnt[st ^ (1 << s[nu]) ^ y];
	}
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i];
		if(v != fa && !sol[v]) {
			dfs(v, u, st);
			cur[u] += cur[v];
		}
	}
	ans[u] += cur[u]; //fprintf(stderr, "cur %d = %d\n", u, cur[u]);
}
void solve(int u) {
	nu = u; sol[u] = 1; sl = 0; tmp = 0; //fprintf(stderr, "solving %d\n", u);
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i];
		if(!sol[v]) son[++ sl] = v;
	} 
	cnt[0] = 1; li[0] = 0;
	for(int i = 1; i <= sl; i ++) {
		int v = son[i], t = li[0]; dfs(v, u, 0);
		for(int j = t + 1; j <= li[0]; j ++) cnt[li[j]] ++;
	}
	for(int i = 1; i <= sl; i ++) tmp += cur[son[i]];
	cnt[0] = 0;
	for(int i = li[0]; i >= 1; i --) cnt[li[i]] = 0;
	
	cnt[0] = 0; li[0] = 0;
	for(int i = sl; i >= 1; i --) {
		int v = son[i], t = li[0]; dfs(v, u, 0);
		for(int j = t + 1; j <= li[0]; j ++) cnt[li[j]] ++;
	}
	for(int i = -1; i < lim; i ++) {
		int y = ~ i ? 1 << i : 0;
		tmp += cnt[(1 << s[u]) ^ y];
	}
	for(int i = sl; i >= 1; i --) tmp += cur[son[i]];
	cnt[0] = 0;
	for(int i = li[0]; i >= 1; i --) cnt[li[i]] = 0;
	ans[u] += tmp >> 1;
	for(int i = 0; i < (int) G[u].size(); i ++) {
		int v = G[u][i];
		if(!sol[v]) {
			rt = 0; size = sz[v]; findrt(v, u); solve(rt);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int u, v, i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i ++) s[i] -= 'a';
	lim = 1 + *max_element(s + 1, s + n + 1);
	rt = 0; size = n; findrt(1, 0); solve(rt);
	for(int i = 1; i <= n; i ++) {
		printf("%lld%c", ans[i] + 1, " \n"[i == n]);
	}
	return 0;
}