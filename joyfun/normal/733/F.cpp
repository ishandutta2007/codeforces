#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<long long,int> pii;
typedef vector<long long> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(long long i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (long long)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 200005;

struct Edge {
	int u, v, w, c, id;
	bool operator < (const Edge &c) const {
		return w < c.w;
	}
} e[N];
bool cmp(Edge a, Edge b) {return a.w < b.w;}
bool cmpid(Edge a, Edge b) {return a.id < b.id;}
int n, m, s;
int fa[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

vector<Edge> g[N];
int dep[N], f[N][20];
Edge dp[N][20];

void dfs(int u, int p, int d) {
	dep[u] = d; if (u != 1) dp[u][0] = e[p];
	for (int i = 1; i < 20; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
		dp[u][i] = max(dp[u][i - 1], dp[f[u][i - 1]][i - 1]);
	}
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i].id == p) continue;
		f[g[u][i].v][0] = u;
		dfs(g[u][i].v, g[u][i].id, d + 1);
	}
}

Edge get(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	Edge ans; ans.w = -1;
	for (int i = 0; i < 20; i++) {
		if ((dep[b] - dep[a])>>i&1) {
			ans = max(ans, dp[b][i]);
			b = f[b][i];
		}
	}
	if (a == b) return ans;
	for (int i = 19; i >= 0; i--) {
		if (f[b][i] == f[a][i]) continue;
		ans = max(ans, dp[a][i]);
		ans = max(ans, dp[b][i]);
		a = f[a][i];
		b = f[b][i];
	}
	ans = max(ans, dp[a][0]);
	ans = max(ans, dp[b][0]);
	return ans;
}

int vis[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d", &e[i].w);
	for (int i = 1; i <= m; i++) scanf("%d", &e[i].c);
	for (int i = 1; i <= m; i++) scanf("%d%d", &e[i].u, &e[i].v);
	for (int i = 1; i <= m; i++) e[i].id = i; scanf("%d", &s);
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + m + 1, cmp);
	long long sum = 0;
	for (int i = 1; i <= m; i++) {
		int pu = find(e[i].u);
		int pv = find(e[i].v);
		if (pu != pv) {
			vis[e[i].id] = 1;
			Edge ee = e[i];
			g[e[i].u].push_back(ee);
			swap(ee.u, ee.v);
			g[e[i].v].push_back(ee);
			fa[pu] = pv;
			sum += e[i].w;
		}
	}
	sort(e + 1, e + m + 1, cmpid);
	f[1][0] = 1;
	dfs(1, -1, 0);
	long long ans = (1LL<<60);
	int a, b;
	for (int i = 1; i <= m; i++) {
		Edge ee = get(e[i].u, e[i].v);
		long long tmp = sum - ee.w + (e[i].w - s / e[i].c);
		if (ans > tmp) {
			ans = tmp;
			a = ee.id;
			b = i;
		}
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= m; i++) {
		if (!vis[i] || i == a || i == b) continue;
		printf("%d %d\n", i, e[i].w);
	}
	printf("%d %d\n", b, e[b].w - s / e[b].c);
	return 0;
}