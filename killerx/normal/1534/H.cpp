#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;

int n;
std::vector <int> adj[mxn];
int idp[mxn], odp[mxn];
int fop[mxn];
int ans;
int dfn[mxn], ed[mxn];

void dfs0(int u, int p) {
	static int tim = 0;
	dfn[u] = tim ++;
	fop[u] = u;
	std::vector <std::pair <int, int> > vec;
	for (int v : adj[u]) {
		if (v != p) {
			dfs0(v, u);
			vec.emplace_back(idp[v], v);
		}
	}
	std::sort(vec.rbegin(), vec.rend());
	if (!vec.empty()) fop[u] = fop[vec[0].second];
	rep(i, vec.size()) idp[u] = std::max(idp[u], vec[i].first + i);
	idp[u] = std::max(idp[u], (int) vec.size());
	if (vec.empty()) idp[u] = 1;
	ed[u] = tim ++;
}

void dfs1(int u, int p) {
	std::vector <int> vec;
	for (int v : adj[u]) {
		if (v != p) {
			vec.push_back(idp[v]);
		}
	}
	if (u) vec.push_back(odp[u]);
	std::sort(vec.rbegin(), vec.rend());
	std::vector <int> pre(vec.size()), suf(vec.size());
	rep(i, vec.size()) pre[i] = std::max(i ? pre[i - 1] : -0x3f3f3f3f, vec[i] + i);
	for (int i = (int) vec.size() - 1; ~i; -- i) suf[i] = std::max(i + 1 < (int) vec.size() ? suf[i + 1] : -0x3f3f3f3f, vec[i] + i - 1);
	for (int v : adj[u]) {
		if (v != p) {
			int ps = std::lower_bound(vec.begin(), vec.end(), idp[v], std::greater <int> ()) - vec.begin();
			if (ps) odp[v] = std::max(odp[v], pre[ps - 1]);
			if (ps + 1 < (int) vec.size()) odp[v] = std::max(odp[v], suf[ps + 1]);
			odp[v] = std::max(odp[v], (int) vec.size() - 1);
		}
	}
	/*
	eprintf("%d : ", u + 1);
	for (int x : vec) eprintf("%d ", x);
	eprintf("\n");
	*/
	rep(i, vec.size()) {
		if (i) ans = std::max(ans, vec[0] + vec[i] + i - 1);
	}
	rep(i, vec.size()) {
		ans = std::max(ans, vec[i] + i);
	}
	ans = std::max(ans, (int) vec.size());
	for (int v : adj[u]) {
		if (v != p) {
			dfs1(v, u);
		}
	}
}

int query(int u) {
	printf("? %d\n", u + 1);
	fflush(stdout);
	int v;
	scanf("%d", &v);
	-- v;
	return v;
}

void report(int u, int v) {
	printf("! %d %d\n", u + 1, v + 1);
	fflush(stdout);
	exit(0);
}

int interact(int u, int p) {
	if (adj[u].size() == 1) return query(u);
	std::vector <std::pair <int, int> > vec;
	for (int v : adj[u]) if (v != p) {
		vec.emplace_back(idp[v], v);
	}
	std::sort(vec.rbegin(), vec.rend());
	for (auto pr : vec) {
		int v = pr.second;
		int s = interact(v, u);
		if (s == u) continue;
		return s;
	}
	return u;
}

void interact(int r) {
	std::vector <std::pair <int, int> > vec;
	for (int v : adj[r]) {
		vec.emplace_back(idp[v], v);
	}
	std::sort(vec.rbegin(), vec.rend());
	std::pair <int, int> ans(-1, -1);
	for (auto pr : vec) {
		int v = pr.second;
		int s = interact(v, r);
		if (s == r) continue;
		if (ans.first == -1) ans.first = s;
		else { ans.second = s; break; }
	}
	if (ans.first == -1) ans.first = r;
	if (ans.second == -1) ans.second = r;
	report(ans.first, ans.second);
}

int main() {
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n == 1) {
		printf("%d\n", 0);
		fflush(stdout);
		report(0, 0);
	}
	dfs0(0, -1);
	dfs1(0, -1);
	printf("%d\n", ans);
	fflush(stdout);
	int f;
	scanf("%d", &f);
	-- f;
	dfs0(f, -1);
	interact(f);
	return 0;
}