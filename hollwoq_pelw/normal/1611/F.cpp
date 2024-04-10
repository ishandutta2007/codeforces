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

const int N = 2e5 + 5, L = 18;

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

int64_t pre[N];
int n, s;

void Hollwo_Pelw() {
	cin >> n >> s;
	for (int i = 1, a; i <= n; i++)
		cin >> a, pre[i] = pre[i - 1] + a;
	
	rmq<int64_t, min<int64_t>> st(pre, pre + n + 1);

	int l = 0, r = 0;

	for (int i = 0, j = 0; i <= n; i++) {
		while (j <= n && st.query(i, j) - pre[i] + s >= 0) j++;
		if (r - l < j - i - 1)
			l = i, r = j - 1;
	}
	if (l == r)
		cout << -1 << '\n';
	else
		cout << l + 1 << ' ' << r << '\n';
}