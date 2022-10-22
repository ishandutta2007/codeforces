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

const int N = 1e5 + 5;


int n, q, par[N], dis[N], sz[N], res = 1;
vector<pair<int*, int>> st;

void init() {
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}

pair<int, int> find(int u) {
	int d = 0;
	while (par[u] ^ u)
		d ^= dis[u], u = par[u];
	return {u, d};
}

bool merge(int u, int v) {
	auto ud = find(u), vd = find(v);
	u = ud.first, v = vd.first;
	int d = ud.second ^ vd.second ^ 1; // u -> v, w = d
	if (u == v) {
		st.emplace_back(&res, res);
		return res &= d ^ 1, 0;
	}
	if (sz[u] < sz[v]) swap(u, v);
	st.emplace_back(par + v, v);
	st.emplace_back(dis + v, dis[v]);
	st.emplace_back(sz + u, sz[u]);
	sz[par[v] = u] += sz[v], dis[v] = d;
	return 1;
}

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

vector<pair<int, int>> Qry[N << 2];

void update(int l, int r, pair<int, int> v, int id = 1, int tl = 1, int tr = q) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r)
		return Qry[id].push_back(v);
	int tm = tl + tr >> 1;
	update(l, r, v, left), update(l, r, v, right);
}

void solve(int id = 1, int tl = 1, int tr = q) {
	int k = st.size();
	for (auto x : Qry[id])
		merge(x.first, x.second);

	if (tl == tr) {
		cout << (res ? "YES\n" : "NO\n");
	} else {
		int tm = tl + tr >> 1;
		solve(left), solve(right);
	}

	while (st.size() > k)
		*st.back().first = st.back().second, st.pop_back();
}

void Hollwo_Pelw() {
	cin >> n >> q;
	map<pair<int, int>, int> mp;
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		if (mp.count({u, v})) {
			update(mp[{u, v}], i - 1, {u, v});
			mp.erase({u, v});
		} else {
			mp[{u, v}] = i;
		}
	}
	for (auto vp : mp)
		update(vp.second, q, vp.first);
	init(), solve();
}