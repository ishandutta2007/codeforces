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

void Hollwo_Pelw() {
	long long n; cin >> n;
	vector<pair<int, long long>> v;
	for (long long i = 2; i * i <= n; i++)
		if (n % i == 0) {
			int c = 0;
			while (n % i == 0)
				n /= i, c ++;
			v.emplace_back(c, i);
		}
	if (n > 1)
		v.emplace_back(1, n);
	sort(v.begin(), v.end());

	vector<long long> res(v.back().first, 1);
	for (auto [f, x] : v)
		for (int i = 0; i < f; i++)
			res[i] *= x;
	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto x : res) cout << x << ' ';
	cout << '\n';
}