#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
int q, n;
int f[N][21], d[N], dl[N], dr[N], idx;
vector<int> G[N];
void dfs(int u, int _f) {
	d[u] = d[f[u][0] = _f] + 1; dl[u] = ++ idx;
	for(int i = 1; i <= 20; i ++)
		f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = 0; i < G[u].size(); i ++) {
		int v = G[u][i];
		if(v != _f) dfs(v, u);
	}
}

int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	int c = d[u] - d[v];
	for(int i = 20; ~ i; i --)
		if(c >> i & 1) u = f[u][i];
	if(u == v) return u;
	for(int i = 20; ~ i; i --) if(f[u][i] ^ f[v][i]) 
		u = f[u][i], v = f[v][i];
	return f[u][0];
}
int dis(int u, int v) {
	return d[u] + d[v] - 2 * d[lca(u, v)];
}
bool ok(int x, int y) {
	return x <= y && (y - x) % 2 == 0;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
	}
	dfs(1, 0);
	scanf("%d", &q);
	for(int i = 1; i <= q; i ++) {
		int x, y, a, b, k;
		scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
		int d = dis(a, b); bool tag = 0;
		if(ok(d, k)) tag = 1;
		if(ok(dis(a, x) + dis(b, y) + 1, k)) tag = 1;
		if(ok(dis(a, y) + dis(b, x) + 1, k)) tag = 1;
		puts(tag ? "YES" : "NO");
	}
	return 0;
}