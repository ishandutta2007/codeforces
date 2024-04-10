#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 1005;
int n, m, k, w;
string s[N], tmp;

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator < (const Edge& c) const {
		return w < c.w;
	}
} e[N * N];
int en;
int fa[N];
int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

vector<pii> out;
vi g[N];

void dfs(int u, int p) {
	if (u) printf("%d %d\n", u, p);
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &w);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			s[i] += tmp;
		}
	}
	for (int i = 1; i <= k; i++) {
		e[en++] = Edge(0, i, n * m);
		for (int j = i + 1; j <= k; j++) {
			int cnt = 0;
			for (int x = 0; x < n * m; x++) cnt += (s[i][x] != s[j][x]);
			e[en++] = Edge(i, j, cnt * w);
		}
	}
	sort(e, e + en);
	int ans = 0;
	for (int i = 0; i <= k; i++) fa[i] = i;
	for (int i = 0; i < en; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v) {
			fa[u] = v;
			g[e[i].u].pb(e[i].v);
			g[e[i].v].pb(e[i].u);
			ans += e[i].w;
		}
	}
	printf("%d\n", ans);
	dfs(0, 0);
	return 0;
}