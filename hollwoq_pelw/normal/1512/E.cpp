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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define int long long

void Hollwo_Pelw() {
	int n, l, r, s, c = 0;
	cin >> n >> l >> r >> s;
	vector<int> p(r - l + 1);
	iota(p.begin(), p.end(), 1);
	for (auto &v : p) s -= v;
	if (s < 0)
		return cout << "-1\n", (void) 0;
	for (int i = r - l, j = n; ~i; i--, j--) {
		int v = min(j - p[i], s);
		s -= v, p[i] += v;
	}
	if (s > 0)
		return cout << "-1\n", (void) 0;
	set<int> st(p.begin(), p.end());
	for (int i = 1; i <= n; i++) {
		if (i < l || i > r) {
			for (int v = 1, ok = 0; v <= n && !ok; ++v)
				if (!st.count(v)) {
					cout << v << ' ', ok = 1;
					st.insert(v);
				}
		} else {
			cout << p[i - l] << ' ';
		}
	}
	cout << '\n';
}