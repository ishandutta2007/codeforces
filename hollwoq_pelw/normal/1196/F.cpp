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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5;

struct dst {
	int u, v; int64_t d;
	bool operator < (const dst &o) const {
		return d > o.d;
	}
};

priority_queue<dst> pq;
int n, m, k;

vector<pair<int, int64_t>> adj[N];
set<pair<int, int>> dist;

inline int64_t comp(int u, int v) {
	if (u > v) swap(u, v);
	return 1ll * u * N + v;
}

void Hollwo_Pelw() {
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w, pq.push({u, v, w});
	int64_t res = 0, d;
	while (k && !pq.empty()) {
		int u = pq.top().u, v = pq.top().v; d = pq.top().d, pq.pop();
		if (dist.count({u, v})) continue ;
		for (auto vw : adj[u]) pq.push({v, vw.first, d + vw.second});
		for (auto vw : adj[v]) pq.push({u, vw.first, d + vw.second});
		dist.emplace(u, v);
		dist.emplace(v, u);
		adj[u].emplace_back(v, d);
		adj[v].emplace_back(u, d);
		res = d, -- k;
	}
	cout << res;
}