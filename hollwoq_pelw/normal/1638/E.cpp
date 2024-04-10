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

const int N = 1e6 + 5;

#define int long long

int n, q, a[N], lz[N], bit[N];

inline void add(int p, int x) {
	for (; p < N; p += p & -p)
		bit[p] += x;
}

inline void add(int l, int r, int x) {
	add(l, x), add(r + 1, -x);
}

inline int query(int p) {
	int r = 0;
	for (; p > 0; p -= p & -p)
		r += bit[p];
	return r;
}

struct node_t {
	int l, r, c;
	node_t (int _l = 0, int _r = 0, int _c = 0) : l(_l), r(_r), c(_c) {}
	bool operator < (const node_t &o) const {
		return pair<int, int>(l, r) < pair<int, int>(o.l, o.r);
	}
};

set<node_t> st;

void Hollwo_Pelw() {
	cin >> n >> q;
	st.emplace(0, 0, 0);
	st.emplace(1, n, 1);
	st.emplace(n + 1, n +1, 0);

	for (string s; q --; ) {
		cin >> s;
		if (s[0] == 'C') {
			int l, r, ll, rr, cl, cr, c;
			cin >> l >> r >> c;
			auto itl = -- st.upper_bound(node_t(l, N, N));
			auto itr = -- st.upper_bound(node_t(r, N, N));

			ll = itl -> l, cl = itl -> c;
			rr = itr -> r, cr = itr -> c;

			{
				auto it = -- st.upper_bound(node_t(r, N, N));
				do {
					// cout << "erase\n";
					// cout << it -> l << ' ' << it -> r << ' ' << it -> c << '\n';
					add(it -> l, it -> r, + lz[it -> c]);
					st.erase(it);
				} while ((it = -- st.upper_bound(node_t(r, N, N))) -> l >= ll);
			}

			if (ll < l) {
				auto it = st.emplace(ll, l - 1, cl).first;
				// cout << "add\n";
				// cout << it -> l << ' ' << it -> r << ' ' << it -> c << '\n';
				add(it -> l, it -> r, - lz[it -> c]);
			}

			if (rr > r) {
				auto it = st.emplace(r + 1, rr, cr).first;
				// cout << "add\n";
				// cout << it -> l << ' ' << it -> r << ' ' << it -> c << '\n';
				add(it -> l, it -> r, - lz[it -> c]);
			}

			auto it = st.emplace(l, r, c).first;
			// cout << "add\n";
			// cout << it -> l << ' ' << it -> r << ' ' << it -> c << '\n';
			add(it -> l, it -> r, - lz[it -> c]);

			// for (auto [l, r, c] : st)
			// 	cout << '(' << l << ',' << r << ',' << c << "), ";
			// cout << '\n';
		}
		if (s[0] == 'A') {
			int c, x;
			cin >> c >> x, lz[c] += x;
		}
		if (s[0] == 'Q') {
			int p; cin >> p;
			cout << query(p) + lz[(-- st.upper_bound(node_t(p, N, N))) -> c] << '\n';
		}
	}
}