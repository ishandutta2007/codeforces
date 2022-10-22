#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, h[mxn];
std::vector <int> adj[mxn];

std::multiset <int> *rem[mxn];

inline void merge(std::multiset <int> *&a, std::multiset <int> *b) {
	if (!a) { a = b; return ; }
	if (!b) return ;
	if (a->size() < b->size()) std::swap(*a, *b);
	for (int x : *b) a->insert(x);
}

inline void dfs(int u, int p) {
	std::vector <int> son;
	for (int v : adj[u]) if (v != p) son.push_back(v);
	if (son.empty()) {
		rem[u] = new std::multiset <int> ();
		rem[u]->insert(h[u]);
		return ;
	}
	for (int v : son) {
		dfs(v, u);
		merge(rem[u], rem[v]);
	}
	if (*(rem[u]->rbegin()) < h[u]) {
		rem[u]->erase(-- rem[u]->end());
		rem[u]->insert(h[u]);
	}
}

long long sum(std::multiset <int> *a) {
	long long s = 0;
	for (int x : *a) s += x;
	return s;
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &h[i]);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int mx = -1;
	rep(i, n) if (!~mx || h[i] > h[mx]) mx = i;
	if (adj[mx].size() == 1) {
		int u = adj[mx][0];
		dfs(u, mx);
		if (*(rem[u]->rbegin()) < h[mx]) {
			rem[u]->erase(-- rem[u]->end());
			rem[u]->insert(h[mx]);
		}
		printf("%lld\n", sum(rem[u]) + h[mx]);
		return 0;
	}
	long long ans = 0;
	std::vector <int> difs;
	rep(i, adj[mx].size()) {
		int u = adj[mx][i];
		dfs(u, mx);
		difs.push_back(std::max(0, h[mx] - *(rem[u]->rbegin())));
		ans += sum(rem[u]);
	}
	std::sort(difs.begin(), difs.end());
	printf("%lld\n", ans + difs[0] + difs[1]);
	return 0;
}