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
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int MAXN = 2.5e5 + 5;
 
multiset<long long> st[MAXN];
long long sum[MAXN], dp[MAXN][2];
int deg[MAXN], vis[MAXN];
vector<pair<int, int>> adj[MAXN];
 
inline void upd(int u, long long v, int op) {
	sum[u] += op * v;
	if (op == +1) 
		st[u].insert(v);
	if (op == -1)
		st[u].erase(st[u].find(v));
}
 
void solve(int u) {
	vector<long long> add, del;
	long long tot = 0;
 
	int X = vis[u], lim = deg[u] - X; // need to del
 
	while ((int)st[u].size() > max(lim, 0))
		upd(u, *st[u].rbegin(), -1);

	for (auto [v, w] : adj[u]) {
		if (deg[v] <= X) break;
		if (vis[v] == X) continue;
		vis[v] = X;
 
		solve(v);
		tot += dp[v][0];

		long long val = dp[v][1] + w - dp[v][0];
		if (val > 0) {
			add.push_back(val), upd(u, val, +1);
		} else {
			tot += val, lim --;
		}
	}

	for (int i = 0; i < 2; i++) {
		while ((int)st[u].size() > max(lim - i, 0))
			del.push_back(*st[u].rbegin()), upd(u, *st[u].rbegin(), -1);
		dp[u][i] = tot + sum[u];
	}

	for (auto v : del) upd(u, v, +1);
	for (auto v : add) upd(u, v, -1);
}
 
vector<long long> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W) {
	for (int i = 0; i < N - 1; i++) {
		deg[U[i]] ++, deg[V[i]] ++;
		adj[U[i]].emplace_back(V[i], W[i]);
		adj[V[i]].emplace_back(U[i], W[i]);
	}
	for (int i = 0; i < N; i++)
		sort(adj[i].begin(), adj[i].end(), [&](const pair<int, int> &x, const pair<int, int> &y){ return deg[x.first] > deg[y.first]; });
 
	vector<long long> res(N);
 
	res[0] = accumulate(W.begin(), W.end(), 0ll);
 
	vector<int> p(N);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](const int &i, const int &j){
		return deg[i] < deg[j];
	});
 
	for (int X = 1, i = 0; X < N; X++) {
		for (; i < N && deg[p[i]] == X; i++) {
			for (auto [v, w] : adj[p[i]]) {
				if (deg[v] <= X) break;
				upd(v, w, 1);
			}
		}
 
		long long ans = 0;
 
		for (int j = i; j < N; j++)
			if (vis[p[j]] != X) {
				vis[p[j]] = X;
				solve(p[j]);
				ans += dp[p[j]][0];
			}
 
		res[X] = ans;
	}
 
	return res;
}

void Hollwo_Pelw(){
	int N; cin >> N;
	vector<int> U(N - 1), V(N - 1), W(N - 1);
	for (int i = 0; i < N - 1; i++)
		cin >> U[i] >> V[i] >> W[i], -- U[i], -- V[i];
	auto res = minimum_closure_costs(N, U, V, W);
	for (auto v : res)
		cout << v << ' ';
}