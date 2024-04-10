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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 5, mod = 998244353;

int n, res[N], sz[N];
vector<int> adj[N];

inline int sub(int a, int b) {
	return a - b < 0 ? a - b + mod : a - b;
}

void dfs(int u, int p) {
	sz[u] = 1;
	for (int &v : adj[u]) if (v != p)
		dfs(v, u), sz[u] += sz[v];
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) res[i] = i == 1, adj[i].clear();
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u), res[1] = 2ll * res[1] % mod;
	dfs(1, 1);
	for (int i = 2, j; i < n; i++) if ((n - 1) % i == 0) {
		for (res[i] = j = 1; j <= n && res[i]; j++)
			if (sz[j] % i != 0 && sz[j] % i != 1) res[i] = 0;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 2 * i; j <= n; j += i)
			res[i] = sub(res[i], res[j]);
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << " \n"[i == n];
}