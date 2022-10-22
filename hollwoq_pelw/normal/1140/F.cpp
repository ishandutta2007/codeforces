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

const int N = 3e5 + 5, n = 3e5;

#define int long long

struct Query {
	int *o, n;
};

vector<Query> st;

int q, par[N << 1], S[N << 1], x[N << 1], y[N << 1], res;

void init() {
	for (int i = 1; i <= n << 1; i++)
		par[i] = i, S[i] = 1, x[i] = i <= n, y[i] = i > n;
}

int find(int u) {
	return par[u] == u ? u : find(par[u]);
}

bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	if (S[u] < S[v]) swap(v, u);
	st.push_back({par + v, v});
	st.push_back({x + u, x[u]});
	st.push_back({y + u, y[u]});
	st.push_back({S + u, S[u]});
	st.push_back({&res, res});
	S[par[v] = u] += S[v];
	res -= 1ll * x[u] * y[u];
	res -= 1ll * x[v] * y[v];
	x[u] += x[v], y[u] += y[v];
	res += 1ll * x[u] * y[u];
	return 1;
}

void rollback(int k) {
	while (st.size() > k)
		*st.back().o = st.back().n, st.pop_back();
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
	for (auto p : Qry[id])
		merge(p.first, p.second + n);

	if (tl == tr) {
		cout << res << ' ';
	} else {
		int tm = tl + tr >> 1;
		solve(left), solve(right);
	}

	rollback(k);
}

void Hollwo_Pelw() {
	map<pair<int, int>, int> mp;
	cin >> q;
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		if (mp.count({x, y})) {
			update(mp[{x, y}], i - 1, {x, y});
			mp.erase({x, y});
		} else {
			mp[{x, y}] = i;
		}
	}
	for (auto vp : mp)
		update(vp.second, q, vp.first);
	init(), solve();
}