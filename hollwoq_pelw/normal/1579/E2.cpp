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

const int N = 2e5 + 5;

int n, a[N], bit[N];

inline void add(int x, int v) {
	for (; x <= n; x += x & -x)
		bit[x] += v;
}

inline int query(int x) {
	int r = 0;
	for (; x; x -= x & -x)
		r += bit[x];
	return r;
}

void Hollwo_Pelw() {
	map<int, int> mp;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mp[a[i]] = 0;
	int cnt = 0;
	for (auto &vp : mp) 
		vp.second = ++ cnt;
	fill(bit + 1, bit + cnt + 1, 0);

	for (int i = 1; i <= n; i++) {
		a[i] = mp[a[i]], add(a[i], 1);
	}

	int64_t res = 0;

	for (int i = n; i >= 1; i--) {
		int sml = query(a[i] - 1);
		int lrg = i - query(a[i]);

		res += min(sml, lrg);

		add(a[i], -1);
	}
	cout << res << '\n';
}