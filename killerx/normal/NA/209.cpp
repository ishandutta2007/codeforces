#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef std::pair <int, int> pii;

const int mxn = 1e4 + 5;

int n, m;
std::set <pii> adj[mxn], oadj[mxn];
bool vis[mxn];
int deg[mxn];
std::vector <int> tour;
std::vector <int> nodes;
std::set <int> cant;

struct UF {
	int fa[mxn];

	UF() { rep(i, mxn) fa[i] = i; }

	int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

	void merge(int x, int y) { fa[find(x)] = find(y); }
} uf;

void dfs(int u) {
	while (!adj[u].empty()) {
		int v = adj[u].begin()->first;
		int i = adj[u].begin()->second;
		if (vis[i] || cant.count(v)) {
			adj[u].erase(pii(v, i));
			adj[v].erase(pii(u, i));
			continue;
		}
		vis[i] = 1;
		adj[u].erase(pii(v, i));
		adj[v].erase(pii(u, i));
		dfs(v);
		nodes.push_back(v);
		tour.push_back(i);
	}
}

void euler(int S) {
	rep(i, n) oadj[i] = adj[i];
	tour.clear();
	dfs(S);
	nodes.push_back(S);
	std::reverse(tour.begin(), tour.end());
	std::reverse(nodes.begin(), nodes.end());
	rep(i, n) adj[i] = oadj[i];
}

int main() {
#ifndef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &m);
	n = 10000;
	std::vector <int> vec;
	rep(i, m) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[u].insert(pii(v, i));
		adj[v].insert(pii(u, i));
		deg[u] ++;
		deg[v] ++;
		vec.push_back(u);
		vec.push_back(v);
		uf.merge(u, v);
	}
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	std::set <int> qwq;
	rep(i, vec.size()) {
		qwq.insert(uf.find(vec[i]));
	}
	if (qwq.size() > 2) {
		puts("-1");
		return 0;
	}
	if (qwq.size() == 2) {
		std::vector <int> on0, on1;
		rep(i, vec.size()) if (uf.find(vec[i]) == *qwq.begin())
			on0.push_back(vec[i]);
		else
			on1.push_back(vec[i]);
		std::vector <int> odd0, odd1;
		rep(i, on0.size()) {
			if (deg[on0[i]] % 2 == 1) {
				odd0.push_back(on0[i]);
			}
		}
		rep(i, on1.size()) {
			if (deg[on1[i]] % 2 == 1) {
				odd1.push_back(on1[i]);
			}
		}
		std::vector <int> ans0, ans1;
		if (odd0.size() == 0) {
			euler(on0[0]);
			ans0 = tour;
		} else if (odd0.size() == 2) {
			euler(odd0[0]);
			ans0 = tour;
		} else {
			puts("-1");
			return 0;
		}
		if (odd1.size() == 0) {
			euler(on1[0]);
			ans1 = tour;
		} else if (odd1.size() == 2) {
			euler(odd1[0]);
			ans1 = tour;
		} else {
			puts("-1");
			return 0;
		}
		printf("%d\n", (int)(ans0.size()));
		rep(i, ans0.size()) printf("%d\n", ans0[i] + 1);
		printf("%d\n", (int)(ans1.size()));
		rep(i, ans1.size()) printf("%d\n", ans1[i] + 1);
		return 0;
	}
	if (m == 1) {
		puts("-1");
		return 0;
	}
	std::vector <int> odd;
	rep(i, n) {
		if (deg[i] % 2 == 1) {
			odd.push_back(i);
		}
	}
	if (odd.size() == 0) {
		euler(vec[0]);
		if (tour.size() != m) {
			puts("-1");
			return 0;
		}
		rep(i, tour.size()) {
			if (i == 0) printf("%d\n", 1);
			printf("%d\n", tour[i] + 1);
			if (i == 0) printf("%d\n", (int)(tour.size()) - 1);
		}
		return 0;
	}
	if (odd.size() == 2) {
		euler(odd[0]);
		if (tour.size() != m) {
			puts("-1");
			return 0;
		}
		rep(i, tour.size()) {
			if (i == 0) printf("%d\n", 1);
			printf("%d\n", tour[i] + 1);
			if (i == 0) printf("%d\n", (int)(tour.size()) - 1);
		}
		return 0;
	}
	if (odd.size() == 4) {
		adj[odd[0]].insert(pii(odd[1], m));
		adj[odd[1]].insert(pii(odd[0], m));
		adj[odd[2]].insert(pii(odd[3], m + 1));
		adj[odd[3]].insert(pii(odd[2], m + 1));
		euler(odd[0]);
		if (tour.size() != m + 2) {
			puts("-1");
			return 0;
		}
		int p0 = -1, p1 = -1;
		rep(i, m + 2) if (tour[i] == m) {
			p0 = i; break;
		}
		rep(i, m + 2) if (tour[i] == m + 1) {
			p1 = i; break;
		}
		if (p0 > p1) std::swap(p0, p1);
		memset(vis, 0, sizeof(vis));
		std::vector <int> ans0, ans1;
		for (int i = p0 + 1; i < p1; ++ i) {
			ans0.push_back(tour[i]);
			vis[tour[i]] = 1;
		}
		adj[odd[0]].erase(pii(odd[1], m));
		adj[odd[1]].erase(pii(odd[0], m));
		adj[odd[2]].erase(pii(odd[3], m + 1));
		adj[odd[3]].erase(pii(odd[2], m + 1));
		euler(odd[0]);
		ans1 = tour;
		if (ans0.size() + ans1.size() != m) {
			puts("-1");
			return 0;
		}
		printf("%d\n", (int)(ans0.size()));
		rep(i, ans0.size()) printf("%d\n", ans0[i] + 1);
		printf("%d\n", (int)(ans1.size()));
		rep(i, ans1.size()) printf("%d\n", ans1[i] + 1);
		return 0;
	}
	puts("-1");
	return 0;
}