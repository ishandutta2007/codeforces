#include <bits/stdc++.h>
using namespace std;
#define int ll
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
vi g[100005];
int dis[100005];
vector <pii> e;
int que[100005], lb, rb;

void bfs(int S, int T) {
	lb = rb = 0, que[rb ++] = S, dis[S] = 0;
	while (lb < rb) {
		int u = que[lb ++];
		rep(i, g[u].size()) {
			int v = g[u][i];
			if (~dis[v] || (u == S && v == T)) continue;
			dis[v] = dis[u] + 1;
			que[rb ++] = v;
		}
	}
}

int find_loop() {
	int ans = inf;
	rep(i, e.size()) {
		memset(dis, -1, sizeof dis);
		bfs(e[i].first, e[i].second);
		if (~dis[e[i].second]) ans = min(ans, dis[e[i].second] + 1);
	}
	return ans == inf ? -1 : ans;
}

signed main() {
	n = read();
	vi v; rep(i, n) v.pb(read());
	vi vv[60];
	rep(i, n) rep(j, 60) {
		if (v[i] >> j & 1) vv[j].pb(i);
	}
	rep(j, 60) {
		if (vv[j].size() >= 3) {
			puts("3"); return 0;
		} else if (vv[j].size() <= 1) {
		} else {
			g[vv[j][0]].pb(vv[j][1]);
			g[vv[j][1]].pb(vv[j][0]);
			e.pb(mp(vv[j][0], vv[j][1]));
		}
	}
	rep(i, n) {
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
	}
	printf("%d\n", find_loop());
	return 0;
}