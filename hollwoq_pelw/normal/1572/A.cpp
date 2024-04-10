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

int n, deg[N];
vector<int> adj[N];

int vis[N], ok = 0;

void dfs(int u) {
	vis[u] = 1;
	for (auto v : adj[u]) {
		if (vis[v] == 1)
			ok = 1;
		else if (vis[v] == 0)
			dfs(v);
	}
	vis[u] = 2;
}

bool check_cycle() {
	fill(vis + 1, vis + n + 1, 0), ok = 0;
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0) dfs(i);
	return ok;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		deg[i] = 0, adj[i].clear();

	for (int i = 1, k; i <= n; i++) {
		cin >> k, deg[i] = k;
		for (int j; k --; ) {
			cin >> j, adj[j].push_back(i);
		}
	}

	if (check_cycle()) {
		return cout << "-1\n", (void) 0;
	}
	
	set<int> st;
	for (int i = 1; i <= n; i++)
		if (!deg[i]) st.insert(i);
	int res = 1, cur = 0;

	while (!st.empty()) {
		auto it = st.upper_bound(cur);
		if (it == st.end()) {
			it = st.begin(), ++ res;
		}
		st.erase(cur = *it);
		for (auto v : adj[cur]) {
			deg[v] --;
			if (!deg[v]) st.insert(v);
		}
	}
	cout << res << '\n';
}