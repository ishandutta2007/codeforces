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
	FAST_IO("1107G.inp", "1107G.out");
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


#define int long long

const int N = 3e5 + 5, L = 19;

template<class T, const T& merge(const T&, const T&)> struct rmq {
	vector<T> st[L];
	rmq () {}
	rmq (const vector<T> &a) {
		st[0] = a; int n = a.size(); __build__(n);
	}
	rmq (T * __first, T * __last) {
		st[0] = vector<T> (__first, __last);
		int n = __last - __first; __build__(n);
	}

	inline void __build__(int n) {
		for (int j = 1; 1 << j <= n; j++) {
			st[j].resize(n - (1 << j) + 1);
			for (int i = 0; i + (1 << j) <= n; i++)
				st[j][i] = merge(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
		}
	}

	inline T query(int l, int r) {
		int j = __lg(r - l + 1);
		return merge(st[j][l], st[j][r - (1 << j) + 1]); // 0 base
		// return merge(st[j][l - 1], st[j][r - (1 << j)]); // 1 base
	}
};

int n, a, d[N], p[N], c[N], res;

inline int dist(int x) {
	return 1ll * (d[x] - d[x + 1]) * (d[x] - d[x + 1]);
}

const int& _max_pos(const int &a, const int &b) {
	return dist(a) > dist(b) ? a : b;
}

rmq<int, max<int>> stmax;
rmq<int, min<int>> stmin;
rmq<int, _max_pos> pos;

void solve(int l, int r) {
	if (l == r)
		return res = max(res, c[l] - c[l - 1]), (void) 0;
	int m = pos.query(l, r - 1);
	res = max(res, stmax.query(m + 1, r) - stmin.query(l - 1, m - 1) - dist(m));
	solve(l, m), solve(m + 1, r);
}

void Hollwo_Pelw() {
	cin >> n >> a;
	for (int i = 1, b; i <= n; i++)
		cin >> d[i] >> b, c[i] = (a - b) + c[i - 1];
	iota(p + 1, p + n, 1);

	stmax = rmq<int, max<int>>(c, c + n + 1);
	stmin = rmq<int, min<int>>(c, c + n + 1);
	pos = rmq<int, _max_pos>(p, p + n);

	solve(1, n), cout << res;
}