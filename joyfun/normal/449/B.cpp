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

const int N = 100005;
const ll inf = (1ll<<60);
int n, m, k;
vector<pii> g[N];
ll d[N];
int vis[N], v2[N];
int ans;

void spfa() {
	for (int i = 1; i <= n; i++) d[i] = inf;
	queue<int> Q; Q.push(1); d[1] = 0; vis[1] = 1;
	int x, y;
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &x, &y);
		if (d[x] > y) {
			d[x] = y;
			if (!v2[x]) {
				Q.push(x);
				vis[x] = 1;
				v2[x] = 1;
			} else ans++;
		} else ans++;
	}
	while (!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = 0;
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i].fi, w = g[u][i].se;
			if (d[v] >= d[u] + w) {
				if (v2[v]) {
					ans++;
					v2[v] = 0;
				}
				d[v] = d[u] + w;
				if (!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int u, v, w;
	while (m--) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
	}
	spfa();
	printf("%d\n", ans);
	return 0;
}