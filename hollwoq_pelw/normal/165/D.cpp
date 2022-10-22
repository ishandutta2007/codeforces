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
	FAST_IO("165D.inp", "165D.out");
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

vector<pair<int, int>> adj[N];

int n, m, rt, val[N], d[N];
int head[N], timer, tin[N];

void dfs(int u, int p) {
	tin[u] = ++ timer;
	
	for (auto vid : adj[u]) {
		int v = vid.first, id = vid.second;
		if (v != p) {
			val[id] = v;
			
			head[v] = u == rt ? v : head[u];
	
			d[v] = d[u] + 1;
			dfs(v, u);
		}
	}
}

int bit[N];

inline void update(int x, int v) {
	for (; x <= n; x += x & -x)
		bit[x] += v;
}

inline int query(int x) {
	int r = 0;
	for (; x; x -= x & -x)
		r += bit[x];
	return r;
}

inline int query(int l, int r) {
	return query(r) - query(l - 1);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);

	for (int i = 1; i <= n; i++)
		if (adj[i].size() > adj[rt].size()) rt = i;

	dfs(rt, -1);

	cin >> m;

	for (int t, u, v; m --; ) {
		cin >> t;
		if (t == 3) {
			cin >> u >> v;

			if (u == v) {
				cout << "0\n";
			} else if (head[u] == head[v] || u == rt || v == rt) {
				if (d[u] > d[v]) swap(u, v);
				// u -> v
				if (u == rt) {
					if (query(tin[head[v]], tin[v]))
						cout << "-1\n";
					else
						cout << d[v] << '\n';
				} else {
					if (query(tin[u] + 1, tin[v]))
						cout << "-1\n";
					else
						cout << d[v] - d[u] << '\n';
				}
			} else {
				if (query(tin[head[u]], tin[u]) || query(tin[head[v]], tin[v]))
					cout << "-1\n";
				else
					cout << d[v] + d[u] << '\n';
			}
		} else {
			cin >> v;
			update(tin[val[v]], t == 1 ? -1 : 1);
		}
	}
}