#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n;
int a[mxn];
std::unordered_map <int, int> ia;
std::unordered_set <int> node, imp;
std::unordered_map <int, std::set <int> > adj;
std::unordered_map <int, int> maxdep, maxdepi;
int ans = -0x3f3f3f3f;
int ansi = -1, ansj = -1;

void dfs(int u) {
	std::set <std::pair <int, int> > ovo;
	for (int v : adj[u]) {
		dfs(v);
		ovo.emplace(maxdep[v] + 1, maxdepi[v]);
		while (ovo.size() > 2) ovo.erase(ovo.begin());
	}
	if (imp.find(u) != imp.end()) ovo.emplace(0, u);
	maxdep[u] = ovo.empty() ? -0x3f3f3f3f : ovo.rbegin()->first;
	maxdepi[u] = ovo.empty() ? -1 : ovo.rbegin()->second;
	if (ovo.size() >= 2) {
		auto it = -- ovo.end();
		auto a = *std::prev(it);
		auto b = *it;
		if (a.first + b.first > ans) {
			ans = a.first + b.first;
			ansi = a.second;
			ansj = b.second;
		}
	}
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]), ia[a[i]] = i + 1;
	node.insert(0);
	rep(i, n) {
		imp.insert(a[i]);
		int x = a[i];
		while (x) {
			node.insert(x);
			int y = x;
			int l = 32 - __builtin_clz(x);
			if (x <= 1 << (l - 1)) -- l;
			x = (1LL << l) - x;
			adj[x].insert(y);
		}
	}
	dfs(0);
	printf("%d %d %d\n", ia[ansi], ia[ansj], ans);
	return 0;
}