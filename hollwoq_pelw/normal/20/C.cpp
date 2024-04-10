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

const int N = 1e5 + 5;

int n, m, pre[N];
int64_t dist[N];

vector<pair<int, int>> adj[N];
priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;

void Hollwo_Pelw() {
	cin >> n >> m;
	fill(dist + 1, dist + n + 1, 1e18);
	for (int u, v, w; m --; )
		cin >> u >> v >> w, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	pq.emplace(dist[1] = 0, 1);
	while (!pq.empty()) {
		int u = pq.top().second; int64_t d = pq.top().first; pq.pop();
		if (d != dist[u]) continue ;
		for (auto vw : adj[u]) {
			int v = vw.first, w = vw.second;
			if (dist[v] > d + w) {
				pre[v] = u;
				pq.emplace(dist[v] = d + w, v);
			}
		}
	}
	if (dist[n] > 1e16)
		return cout << -1, (void) 0;
	vector<int> tr;
	for (int x = n; x; x = pre[x])
		tr.push_back(x);
	reverse(tr.begin(), tr.end());
	for (auto v : tr) cout << v << ' ';
}