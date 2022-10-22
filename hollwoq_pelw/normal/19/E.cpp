/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
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
	return 0;
}

const int N = 1e4 + 5;

// dsu with roll back
int n, m, par[N], siz[N], dis[N], res = 1;

struct disjoint_set {
	vector<pair<int*, int>> roll;

	disjoint_set(int n = N - 1) {
		iota(par + 1, par + n + 1, 1);
		fill(siz + 1, siz + n + 1, 1);
	}

	pair<int, int> find(int u) {
		int d = 0;
		while (par[u] != u)
			d ^= dis[u], u = par[u];
		return {u, d};
	}

	void merge(int u, int v) {
		pair<int, int> ud = find(u), vd = find(v);
		int du = ud.second, dv = vd.second;

		if ((u = ud.first) == (v = vd.first)) {
			if (du == dv)
				roll.emplace_back(&res, res), res = 0;
			return ;
		}

		if (siz[u] < siz[v]) swap(u, v);
		roll.emplace_back(par + v, par[v]);
		roll.emplace_back(siz + u, siz[u]);
		roll.emplace_back(dis + v, dis[v]);
		par[v] = u;
		siz[u] += siz[v];
		dis[v] = du ^ dv ^ 1;
	}

	void rollback(int k) { // roll back till siz = k
		while (roll.size() > k)
			*roll.back().first = roll.back().second, roll.pop_back();
	}

} dsu;

pair<int, int> edges[N];
vector<int> ans;

void solve(int l, int r) {
	if (l > r) return ;
	if (l == r) {
		if (res) 
			ans.push_back(l);
		return ;
	}
	int k = dsu.roll.size(), m = l + r >> 1; // save val
	
	for (int i = m + 1; i <= r; i++)
		dsu.merge(edges[i].first, edges[i].second);
	solve(l, m), dsu.rollback(k);

	for (int i = l; i <= m; i++)
		dsu.merge(edges[i].first, edges[i].second);
	solve(m + 1, r), dsu.rollback(k);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, edges[i] = {u, v};
	solve(1, m);
	cout << ans.size() << '\n';
	for (auto v : ans) cout << v << ' ';
}