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

const int N = 3e5 + 5;
 
int n, m, dp[N], tr[N], cnt;
vector<pair<int, int>> q[N];
pair<int, int> st[N << 3], lz[N << 3];

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void apply(int id, pair<int, int> v) {
	lz[id] = max(lz[id], v);
	st[id] = max(st[id], v);
}

void push(int id) {
	apply(id << 1, lz[id]), apply(id << 1 | 1, lz[id]);
}

void update(int l, int r, pair<int, int> v, int id = 1, int tl = 1, int tr = cnt) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) 
		return apply(id, v);
	int tm = tl + tr >> 1; push(id);
	update(l, r, v, left), update(l, r, v, right);
	st[id] = max(st[id << 1], st[id << 1 | 1]);
}

pair<int, int> query(int l, int r, int id = 1, int tl = 1, int tr = cnt) {
	if (l > tr || tl > r) return {0, 0};
	if (l <= tl && tr <= r) return st[id];
	int tm = tl + tr >> 1; push(id);
	return max(query(l, r, left), query(l, r, right));
}

int chk[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	map<int, int> mp;
	for (int i = 1, v, l, r; i <= m; i++) {
		cin >> v >> l >> r, mp[l], mp[r], q[v].emplace_back(l, r);
	}
	for (auto &vp : mp) vp.second = ++ cnt;

	for (int i = 1; i <= n; i++) for (auto &v : q[i]) 
		v.first = mp[v.first], v.second = mp[v.second];

	for (int i = 1; i <= n; i++) {
		pair<int, int> tmp = {0, 0};
		for (auto lr : q[i])
			tmp = max(tmp, query(lr.first, lr.second));
		dp[i] = tmp.first + 1, tr[i] = tmp.second;
		for (auto lr : q[i])
			update(lr.first, lr.second, {dp[i], i});
		// cout << dp[i] << '\n';
	}
	int pos = max_element(dp + 1, dp + n + 1) - dp;
	while (pos) {
		chk[pos] = 1, pos = tr[pos];
	}
	vector<int> res;
	for (int i = 1; i <= n; i++)
		if (!chk[i]) res.push_back(i);
	cout << res.size() << '\n';
	for (auto v : res) cout << v << ' '; 
}