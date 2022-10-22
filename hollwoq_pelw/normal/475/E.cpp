#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("D.inp", "r")){
		freopen("D.inp", "r", stdin);
		freopen("D.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2005;

int n, m, tin[N], low[N], timer;
vector<int> adj[N], nadj[N];
int st[N], top;
int comp[N], cnt[N], sub[N], val[N], nnode;

void tarjan(int u, int p) {
	low[u] = tin[u] = ++ timer;
	st[++ top] = u;
	for (int v : adj[u]) if (v != p) {
		if (tin[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] >= tin[u]) {
		++ nnode;
		while (st[top] != u)
			comp[st[top --]] = nnode, cnt[nnode] ++;
		comp[st[top --]] = nnode, cnt[nnode] ++;
	}
}

int res;

void pre_dfs(int u, int p) {
	sub[u] = cnt[u];
	for (int v : nadj[u]) if (v != p) {
		pre_dfs(v, u);
		sub[u] += sub[v];
		val[u] += val[v];
	}
	val[u] += cnt[u] * sub[u];
}

inline void _reroot(int u, int v) { // u -> v
	val[u] -= cnt[u] * sub[v] + val[v];
	sub[u] -= sub[v];
	sub[v] += sub[u];
	val[v] += cnt[v] * sub[u] + val[u];
}

void re_root(int u, int p) {
	bitset<N> dp;
	dp[0] = 1;

	for (int v : nadj[u]) {
		dp |= dp << sub[v];
	}

	for (int i = 0; i <= n; i++)
		if (dp[i]) res = max(res, i * (n - cnt[u] - i) + val[u]);

	for (int v : nadj[u]) if (v != p) {
		_reroot(u, v);
		re_root(v, u);
		_reroot(v, u);
	}
}

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int u, v; m --; )
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	tarjan(1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j : adj[i])
			if (comp[i] != comp[j])
				nadj[comp[i]].push_back(comp[j]);
	}

	pre_dfs(1, 0);
	re_root(1, 0);

	cout << res << '\n';
}