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

const int N = 5e5 + 5;
const pair<int, int> inf = {1e9, 0};

int n, q, sz, a[N], lst[N], prv[N], res[N];
vector<pair<int, int>> ql[N];

pair<int, int> st[N << 2];

inline void update(int p, pair<int, int> v) {
	for (st[p += sz - 1] = v; p >>= 1; )
		st[p] = min(st[p << 1], st[p << 1 | 1]);
}

inline pair<int, int> query(int l, int r) {
	pair<int, int> res = inf;
	for (l += sz - 1, r += sz; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, st[l ++]);
		if (r & 1) res = min(res, st[-- r]);
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n;
	for (sz = 1; sz < n;) sz <<= 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i], prv[i] = lst[a[i]], lst[a[i]] = i;
	cin >> q;
	for (int i = 1, l, r; i <= q; i++)
		cin >> l >> r, ql[r].emplace_back(l, i);

	fill(st + 1, st + (N << 2), inf);

	for (int i = 1; i <= n; i++) {
		update(i, {prv[i], a[i]});
		if (prv[i]) update(prv[i], inf);

		for (auto [l, p] : ql[i]) {
			auto [lp, v] = query(l, i);
			res[p] = lp < l ? v : 0;
		}
	}

	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}