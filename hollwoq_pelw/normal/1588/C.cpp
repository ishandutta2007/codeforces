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
	cin >> testcases;
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

const int N = 3e5 + 5, L = 19, inf = 1e18;

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
		// return merge(st[j][l], st[j][r - (1 << j) + 1]); // 0 base
		return merge(st[j][l - 1], st[j][r - (1 << j)]); // 1 base
	}
};

int n, a[N], b[N], c[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	map<int, vector<int>> mp;

	mp[0].push_back(0);

	for (int i = 1, cur = 0; i <= n; i++) {
		cur += (i & 1 ? a[i] : - a[i]);
		if (i & 1) {
			b[i] = cur;
			c[i] =-inf;
		} else {
			b[i] = inf;
			c[i] = cur;
		}
		// cout << cur << " \n"[i == n];
		mp[cur].push_back(i);
	}

	rmq<int, min<int>> stmin(b + 1, b + n + 1);
	rmq<int, max<int>> stmax(c + 1, c + n + 1);

	int res = 0;

	for (auto [p, v] : mp) {
		for (int i = 0; i < (int) v.size() - 1; i++) {
			int x = v[i] + 1;

			int l = i + 1, r = (int) v.size() - 1, f = i;

			while (l <= r) {
				int m = l + r >> 1, y = v[m];

				if (stmin.query(x, y) >= p && stmax.query(x, y) <= p) {
					f = m;
					l = m + 1;
				} else {
					r = m - 1;
				}
			}

			res += f - i;
		}
	}

	cout << res << '\n';
}