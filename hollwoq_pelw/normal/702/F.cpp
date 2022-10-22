/*
// is short or still long ?/?
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

namespace treap {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	constexpr int MAX_BUFF = 2e5 + 5;
	static int PTR_BUFF = 0;

	struct node_t; using ptr = node_t*;

	struct data_t {
		int val, res = 0, id = 0;
		int lz_add = 0, lz_res = 0;

		data_t (int _v = 0, int _id = 0) : val(_v), id(_id) {}
	};

	struct node_t {
		ptr l = 0, r = 0;
		data_t T; int f;

		node_t (int _v = 0, int _id = 0) : f(rng()) {
			T = data_t(_v, _id);
		}

	} buffer[MAX_BUFF];

	inline ptr new_node(int _v, int _id) {
		ptr p = buffer + (PTR_BUFF ++);
		return *p = node_t(_v, _id), p;
	}

#define get_data(p) (p ? p -> T : data_t())

	inline void recalc(ptr p) {
		// if (!p) return ;
		// auto &t = p -> T, l = get_data(p -> l), r = get_data(p -> r);
	}

	inline void add(ptr p, int add, int res) {
		if (!p) return ;
		auto &t = p -> T;
		t.val += add;
		t.res += res;
		t.lz_add += add;
		t.lz_res += res;
	}

	inline void push(ptr p) {
		if (!p) return ;
		auto &t = p -> T;

		if (t.lz_add) {
			add(p -> l, t.lz_add, t.lz_res);
			add(p -> r, t.lz_add, t.lz_res);
			t.lz_add = t.lz_res = 0;
		}
	}

	pair<ptr, ptr> split(ptr p, int k) {
		if (!p) return {0, 0};

		push(p);
		if (get_data(p).val >= k) {
			auto [tl, tr] = split(p -> l, k);
			p -> l = tr, recalc(p); return {tl, p};
		} else {
			auto [tl, tr] = split(p -> r, k);
			p -> r = tl, recalc(p); return {p, tr};
		}
	}

	ptr merge(ptr tl, ptr tr) {
		if (!tl) return tr;
		if (!tr) return tl;

		if (tl -> f > tr -> f) {
			push(tl);
			tl -> r = merge(tl -> r, tr);
			return recalc(tl), tl;
		} else {
			push(tr);
			tr -> l = merge(tl, tr -> l);
			return recalc(tr), tr;
		}
	}

#undef get_data
}

using namespace treap;

const int N = 2e5 + 5, inf = 1e9 + 7;

inline int get_l(ptr p) {
	if (!p) return +inf;
	while(p -> l)
		push(p), p = p -> l;
	return (p -> T).val;
}

inline int get_r(ptr p) {
	if (!p) return -inf;
	while(p -> r)
		push(p), p = p -> r;
	return (p -> T).val;
}

struct tshirt {
	int c, q;
	bool operator < (const tshirt &o) const {
		return q == o.q ? c < o.c : q > o.q;
	}
} a[N];

pair<int, int> b[N];

int n, m, res[N];

ptr root = 0;

void solve(ptr p) {
	if (!p) return ;
	push(p);

	auto &t = p -> T;
	res[t.id] = t.res;
	
	solve(p -> l);
	solve(p -> r);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, c, q; i <= n; i++)
		cin >> c >> q, a[i] = {c, q};
	sort(a + 1, a + n + 1);

	cin >> m;
	for (int i = 1, x; i <= m; i++)
		cin >> x, b[i] = {x, i};
	sort(b + 1, b + m + 1);

	for (int i = 1; i <= m; i++) {
		root = merge(root, new_node(b[i].first, b[i].second));
	}

	for (int i = 1; i <= n; i++) {
		auto [tl, tr] = split(root, a[i].c);

		add(tr, - a[i].c, 1);

		if (!tl || !tr) {
			root = merge(tl, tr);
			continue ;
		}

		int l = get_r(tl), r = get_l(tr);
		for (; l > r; l = get_r(tl), r = get_l(tr)) {
			auto [ll, lr] = split(tl, r + 1);
			auto [rl, rr] = split(tr, r + 1); 
			tr = rr;
			tl = merge(merge(ll, rl), lr);
		}

		root = merge(tl, tr);
	}
	solve(root);

	for (int i = 1; i <= m; i++)
		cout << res[i] << ' ';
}