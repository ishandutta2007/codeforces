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
	cin >> testcases;
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

const int N = 2e5 + 5;

int n, lf[N], lfcnt[N];
vector<int> adj[N], ans;

void pre_dfs(int u, int p) {
	for (auto &v : adj[u]) if (v == p) {
		swap(v, adj[u].back());
		adj[u].pop_back();
		break ;
	}
	for (auto v : adj[u])
		pre_dfs(v, u);
}

bool dfs(int u) {
	vector<int> tmp;
	for (auto v : adj[u]) {
		if (!dfs(v))
			tmp.push_back(v);
	}
	if (tmp.empty()) {
		lf[u] = lfcnt[u] = 1;
	} else {
		int ok = 1;
		lfcnt[u] = 0;
		for (auto v : tmp)
			ok &= lf[v], lfcnt[u] += lfcnt[v];
		if (ok) {
			ans.push_back(lfcnt[u]);
			// cout << u << ' ' << lfcnt[u] << '\n';
			return 1;
		}
	}
	return 0;
}

void Hollwo_Pelw() {
	cin >> n, ans.clear();
	for (int i = 1; i <= n; i++) 
		lf[i] = lfcnt[i] = 0, adj[i].clear();
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1, 0);
	if (!dfs(1))
		ans.push_back(lfcnt[1]);
	// cout << "HEHEH : ";
	// for (auto x : ans) cout << x << ' '; cout << '\n';
	int res = - ((int) ans.size() - 1);
	for (auto x : ans) res += x;
	cout << res << '\n';
}