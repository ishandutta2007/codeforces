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

const int N = 300005;
const int inf = 0x3f3f3f3f;

struct Edge {
	int v, w, id;
	Edge() {}
	Edge(int v, int w, int id) : v(v), w(w), id(id) {}
};

vector<Edge> g[N];
int n, m, w[N];

pair<ll, int> d[N];
int vis[N];
queue<int> Q;
int fa[N];

void spfa(int s) {
	for (int i = 1; i <= n; i++) d[i] = mp(1ll<<60, inf);
	d[s] = mp(0, 0); Q.push(s); vis[s] = 1;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = 0;
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i].v;
			int w = g[u][i].w;
			if (d[v] > mp(d[u].fi + w, w)) {
				d[v] = mp(d[u].fi + w, w);
				fa[v] = g[u][i].id;
				if (!vis[v]) {
					Q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w[i]);
		g[u].pb(Edge(v, w[i], i));
		g[v].pb(Edge(u, w[i], i));
	}
	int s; scanf("%d", &s);
	spfa(s);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i == s) continue;
		sum += w[fa[i]];
	}
	printf("%lld\n", sum);
	for (int i = 1; i <= n; i++) {
		if (i == s) continue;
		printf("%d ", fa[i]);
	}
	printf("\n");
	return 0;
}