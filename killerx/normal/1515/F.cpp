#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 3e5 + 5;

void no() {
	printf("NO\n");
	exit(0);
}

int n, m, lim;
ll a[mxn];
int fa[mxn];
std::set <std::pair <int, int> > adj[mxn];
std::vector <std::pair <int, int> > nadj[mxn];
std::map <std::pair <int, int>, int> edges;
std::set <std::pair <ll, int> > ver;

inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

inline bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return 0;
	if (adj[x].size() > adj[y].size()) std::swap(x, y);
	ver.erase({a[x], x});
	ver.erase({a[y], y});
	for (auto pr : adj[x]) {
		adj[pr.first].erase({x, pr.second});
		if (pr.first == y) continue;
		auto it = adj[y].lower_bound(std::make_pair(pr.first, -1));
		if (it == adj[y].end() || it->first != pr.first) {
			adj[pr.first].insert({y, pr.second});
			adj[y].insert({pr.first, pr.second});
		}
	}
	adj[x].clear();
	a[y] = a[x] + a[y] - lim;
	fa[x] = y;
	ver.insert({a[y], y});
	return 1;
}

std::vector <int> ans;
bool vis[mxn];
int pa[mxn];
int deg[mxn];
int que[mxn], ql, qr;

void dfs(int u, int p = -1) {
	vis[u] = 1;
	pa[u] = p;
	for (auto pr : nadj[u]) if (!vis[pr.first]) {
		++ deg[u];
		edges[std::make_pair(u, pr.first)] = pr.second;
		dfs(pr.first, u);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &lim);
	rep(i, n) scanf("%lld", &a[i]);
	rep(i, m) {
		int u, v; scanf("%d %d", &u, &v); -- u, -- v;
		adj[u].insert({v, i});
		adj[v].insert({u, i});
	}
	ll tot = 0;
	rep(i, n) tot += a[i];
	if (tot < 1LL * (n - 1) * lim) no();
	rep(i, n) fa[i] = i;
	rep(i, n) ver.insert({a[i], i});
	while (ver.size() > 1 && ver.rbegin()->first >= lim) {
		int i = ver.rbegin()->second;
		int j = adj[i].begin()->first, id = adj[i].begin()->second;
		if (merge(i, j)) ans.push_back(id);
	}
	rep(i, n) for (auto pr : adj[i]) {
		int j = pr.first;
		if (find(i) != find(j)) {
			nadj[find(i)].push_back({find(j), pr.second});
		}
	}
	int sz = 0;
	rep(i, n) if (find(i) == i) ++ sz;
	int rt = -1;
	rep(i, n) if (find(i) == i) { rt = i; break; }
	dfs(rt);
	rep(i, n) if (find(i) == i && deg[i] == 0) que[qr ++] = i;
	std::vector <int> stk;
	while (ql < qr) {
		int u = que[ql ++];
		if (pa[u] != -1) {
			stk.push_back(edges[std::make_pair(pa[u], u)]);
			if (-- deg[pa[u]] == 0) que[qr ++] = pa[u];
		}
	}
	ans.insert(ans.end(), stk.rbegin(), stk.rend());
	printf("YES\n");
	rep(i, ans.size()) printf("%d\n", ans[i] + 1);
	return 0;
}