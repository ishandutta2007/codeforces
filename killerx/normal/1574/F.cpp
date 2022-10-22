#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n, m, K;
	scanf("%d %d %d", &n, &m, &K);
	std::set <std::pair <int, int> > edges;
	std::vector <std::vector <int> > adj(K), eadj(K);
	std::vector <int> in(K), out(K);
	auto adde = [&] (int u, int v) {
		if (edges.find({u, v}) != edges.end()) return ;
		edges.insert({u, v});
		adj[u].push_back(v);
		eadj[u].push_back(v);
		eadj[v].push_back(u);
		out[u] ++;
		in[v] ++;
	};
	rep(i, n) {
		int c;
		scanf("%d", &c);
		int last = -1;
		rep(j, c) {
			int a;
			scanf("%d", &a);
			-- a;
			if (j) adde(last, a);
			last = a;
		}
	}
	std::vector <bool> vis(K);
	std::vector <int> vec;
	std::function <void(int)> dfs;
	dfs = [&] (int u) {
		vis[u] = true;
		vec.push_back(u);
		for (int v : eadj[u]) {
			if (!vis[v]) {
				dfs(v);
			}
		}
	};
	std::map <int, int> times;
	rep(x, K) if (!vis[x]) {
		vec.clear();
		dfs(x);
		if (vec.size() == 1) {
			times[1] ++;
			continue;
		}
		int us = -1, ut = -1, cnt_mid = 0;
		for (int u : vec) {
			if (in[u] == 1 && out[u] == 0) {
				if (ut != -1) {
					ut = -1;
					break;
				}
				ut = u;
			}
			if (in[u] == 0 && out[u] == 1) {
				if (us != -1) {
					us = -1;
					break;
				}
				us = u;
			}
			if (in[u] == 1 && out[u] == 1) {
				++ cnt_mid;
			}
		}
		if (us != -1 && ut != -1 && cnt_mid == (int) vec.size() - 2) {
			times[vec.size()] ++;
		}
	}
	const int mod = 998244353;
	std::vector <int> ans(m + 1);
	ans[0] = 1;
	for (int i = 1; i <= m; ++ i) {
		for (auto pr : times) {
			if (i - pr.first >= 0) {
				ans[i] = (ans[i] + 1LL * ans[i - pr.first] * pr.second) % mod;
			}
		}
	}
	printf("%d\n", ans[m]);
	return 0;
}