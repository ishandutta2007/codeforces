/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

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
	cin >> testcases;
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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const int N = 4e5 + 5, mod = 998244353;

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

int n, m, fac[N], ifac[N];

struct __init__ {
	__init__() {
		fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
		for (int i = 2; i < N; i++)
			ifac[i] = mod - mul(mod / i, ifac[mod % i]);
		for (int i = 2; i < N; i++)
			fac[i] = mul(fac[i - 1], i), ifac[i] = mul(ifac[i - 1], ifac[i]);
	}
} __init__;

int C(int n, int k) {
	// cout << n << ' ' << k << '\n';
	if (k > n || k < 0) return 0;
	return mul(fac[n], mul(ifac[k], ifac[n - k]));
}


struct fenwick {
	vector<pair<int, int>> opt;
	int bit[N];
	
	inline void _add(int x, int v) {
		for (; x <= n; x += x & -x)
			bit[x] += v;
	}

	inline int _query(int x) {
		int r = 0;
		for (; x; x -= x & -x)
			r += bit[x];
		return r;
	}

	inline void clear() {
		for (auto vp : opt)
			_add(vp.first, vp.second);
		opt.clear();
	}
	// type 1
	inline void add(int l, int r, int v) {
		_add(l, v), _add(r + 1, v);
		opt.emplace_back(l, -v);
		opt.emplace_back(r + 1, -v);
	}

	inline int query(int p) {
		return _query(p);
	}
	// type 2
	inline void add(int p, int v) {
		// cout << p << ' ' << v << '\n';
		_add(p, v);
		opt.emplace_back(p, -v);
	}

	inline int query(int l, int r) {
		return _query(r) - _query(l - 1);
	}
} bit;

int x[N], y[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	int k = m;

	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
	}

	vector<pair<int, int>> p;

	for (int i = m; i >= 1; i--) {
		int l = y[i], r = n;
		while (l < r) {
			int m = l + r >> 1;
			if (m - bit.query(m) >= y[i]) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		p.emplace_back(l, x[i]);
		bit.add(l, 1);
	}
	sort(p.begin(), p.end());
	for (int i = 1; i < m; i++) {
		if (p[i - 1].first + 1 == p[i].first && p[i - 1].second < p[i].second) k --;
	}

	bit.clear();
	cout << C(n * 2 - 1 - k, n) << '\n';
}