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
	FAST_IO("1612E.inp", "1612E.out");
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

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

const int N = 2e5;

int n, resa = 0, resb = 1;
vector<int> a[N], res;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x, k; i <= n; i++)
		cin >> x >> k, a[x - 1].push_back(k);

	for (int k = 1; k <= 20; k++) {
		vector<pair<int, int>> b(N);

		for (int i = 0; i < N; i++) {
			int v = 0;
			for (auto t : a[i])
				v += min(t, k);
			b[i] = {v, i + 1};
		}

		sort(b.rbegin(), b.rend());
		b.resize(k);

		vector<int> s;

		int sa = 0, sb = k;
		for (auto [v, c] : b)
			sa += v, s.push_back(c);

		if (sa * resb > resa * sb)
			resa = sa, resb = sb, res = s;
	}

	cout << res.size() << '\n';
	for (int v : res) cout << v << ' ';
}