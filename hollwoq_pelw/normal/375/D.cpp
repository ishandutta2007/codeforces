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
	FAST_IO("tcq.inp", "tcq.out");
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

const int N = 1e5 + 5, B = 400;

struct query_t {
	int l, r, k, id;
	query_t (int _l = 0, int _r = 0, int _k = 0, int _id = 0)
		: l(_l), r(_r), k(_k), id(_id) {}
	bool operator < (const query_t &o) const {
		if (l / B != o.l / B)
			return l < o.l;
		return l / B & 1 ? r > o.r : r < o.r;
	}
};

vector<query_t> qr;

int sub, n, q, a[N], c[N];
int cnt[N], pre[N], res[N];
int tin[N], tout[N], timer;
vector<int> adj[N];

void pre_dfs(int u, int p) {
	tin[u] = ++ timer;
	a[timer] = c[u];

	for (auto v : adj[u])
		if (v != p) pre_dfs(v, u);

	tout[u] = timer;
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1, 0);
	qr.resize(q);
	for (int i = 0, u, k; i < q; i++) {
		cin >> u >> k;
		qr[i] = {tin[u], tout[u], k, i};
	}
	sort(qr.begin(), qr.end());

	int tl = 1, tr = 0;
	for (auto [l, r, k, id] : qr) {
		while (tl > l)
			pre[++ cnt[a[-- tl]]] ++;
		while (tr < r)
			pre[++ cnt[a[++ tr]]] ++;
		while (tl < l)
			pre[cnt[a[tl ++]] --] --;
		while (tr > r)
			pre[cnt[a[tr --]] --] --;
		res[id] = pre[k];
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << '\n';
}