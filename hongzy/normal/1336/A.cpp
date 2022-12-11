#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
int n, k, d[N], p[N], sz[N];
vector<int> G[N];
bool use[N];
void dfs(int u, int fa = 0) {
	d[u] = d[fa] + 1; sz[u] = 1;
	for(int v : G[u]) if(v ^ fa) dfs(v, u), sz[u] += sz[v]; 
}
bool cmp(int x, int y) {
	return - d[x] + sz[x] > - d[y] + sz[y];
}
long long ans;
void dfs2(int u, ll cur = 0, int fa = 0) {
	cur += use[u];
	if(!use[u] && u != 1) ans += cur;
	for(int v : G[u]) if(v ^ fa) dfs2(v, cur, u);
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v); G[u].pb(v); G[v].pb(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i ++) p[i] = i;
	sort(p + 1, p + n + 1, cmp);
	for(int i = 1; i <= n - k; i ++) use[p[i]] = 1; //printf("%d!\n", p[i]);
	dfs2(1);
	printf("%lld\n", ans);
	return 0;
}