/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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
	FAST_IO(".inp", ".out");
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

const int N = 1e5 + 5;

int n, m, q, res[N], par[N];
set<int> ind[N];

struct edge {
	int u, v;
};
vector<edge> edges[N], st;

int find(int u) {
	while (u != par[u])
		u = par[u];
	return u;
}

inline void add(int u, int x, int v = 0) {
	if (ind[u].count(x))
		ind[u].erase(x), res[x] += v;
	else
		ind[u].insert(x);
}

void merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return ;
	if (ind[u].size() < ind[v].size()) swap(u, v);
	par[v] = u;
	for (auto x : ind[v])
		add(u, x, 1);
	st.push_back({u, v});
}

void rollback() {
	while (!st.empty()) {
		int u = st.back().u, v = st.back().v;
		par[v] = v;
		for (auto x : ind[v])
			add(u, x);
		st.pop_back();
	}
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, u, v, c; i <= m; i++)
		cin >> u >> v >> c, edges[c].push_back({u, v});
	for (int i = 1; i <= n; i++) par[i] = i;
	cin >> q;
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		ind[u].insert(i);
		ind[v].insert(i);
	}
	for (int i = 1; i <= m; i++) {
		if (edges[i].empty()) continue ;
		for (auto uv : edges[i])
			merge(uv.u, uv.v);
		rollback();
	}
	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}