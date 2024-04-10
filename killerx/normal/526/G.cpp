#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
const int mxlg = 17;
const int inf = 0x3f3f3f3f;

int n, q, tp;
std::vector <std::pair <int, int> > adj[mxn];

inline std::pair <int, int> find_far(int u, int p, int d) {
	auto ans = std::make_pair(d, u);
	rep(i, adj[u].size()) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (v == p) continue;
		ans = std::max(ans, find_far(v, u, d + w));
	}
	return ans;
}

struct solver {
	int rt;

	int fa[mxn], faw[mxn];
	int dep[mxn], hei[mxn];
	int son[mxn];
	int top[mxn];
	std::vector <std::pair <int, int> > ch;
	int tim[mxn];
	int sum[mxn];
	int jmp[mxlg][mxn], mnt[mxlg][mxn];

	inline void dfs(int u, int p) {
		fa[u] = p;
		hei[u] = 0;
		son[u] = -1;
		rep(i, adj[u].size()) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if (v == p) continue;
			faw[v] = w;
			dep[v] = dep[u] + w;
			dfs(v, u);
			if (hei[v] + w > hei[u]) {
				hei[u] = hei[v] + w;
				son[u] = v;
			}
		}
	}

	inline void hld(int u, int p, int d) {
		top[u] = ~p && u == son[p] ? top[p] : u;
		if (!~son[u]) {
			ch.push_back({d, u});
			return ;
		}
		hld(son[u], u, d + faw[son[u]]);
		rep(i, adj[u].size()) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if (v == p || v == son[u]) continue;
			hld(v, u, w);
		}
	}

	inline void init(int _rt) {
		rt = _rt;
		dfs(rt, -1);
		ch.clear();
		hld(rt, -1, 0);
		std::sort(ch.rbegin(), ch.rend());
		rep(i, ch.size()) {
			sum[i + 1] = sum[i] + ch[i].first;
			int u = ch[i].second;
			for (; ~u && !tim[u]; u = fa[u]) tim[u] = i + 1;
		}
		rep(i, n) jmp[0][i] = fa[i], mnt[0][i] = i == rt ? tim[i] : std::min(tim[i], tim[fa[i]]);
		rep(j, mxlg - 1) rep(i, n) if (~jmp[j][i])
			jmp[j + 1][i] = jmp[j][jmp[j][i]], mnt[j + 1][i] = std::min(mnt[j][i], mnt[j][jmp[j][i]]);
		else
			jmp[j + 1][i] = -1, mnt[j + 1][i] = mnt[j][i];
	}

	inline int query(int x, int k) {
		k = k * 2 - 1;
		if (k == 1) return dep[x] + hei[x];
		if (k >= (int) ch.size()) return sum[ch.size()];
		if (tim[x] <= k) return sum[k];
		int u = x;
		for (int i = mxlg - 1; ~i; -- i)
			if (mnt[i][u] > k) u = jmp[i][u];
		u = fa[u];
		int ans = sum[k - 1] + dep[x] - dep[u] + hei[x];
		ans = std::max(ans, sum[k] - hei[u] + dep[x] - dep[u] + hei[x]);
		return ans;
	}
} su, sv;

int main() {
	scanf("%d %d", &n, &q);
	tp = 1;
	rep(i, n - 1) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int U = find_far(0, -1, 0).second;
	int V = find_far(U, -1, 0).second;
	su.init(U);
	sv.init(V);
	int lastans = 0;
	while (q --) {
		int u, k;
		scanf("%d %d", &u, &k);
		u = (u + tp * lastans - 1) % n;
		k = (k + tp * lastans - 1) % n + 1;
		printf("%d\n", lastans = std::max(su.query(u, k), sv.query(u, k)));
	}
	return 0;
}