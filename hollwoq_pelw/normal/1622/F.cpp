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

mt19937_64 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

int n, p[N];
uint64_t val[N], hsh[N], tot;

inline void print(int n, vector<int> del) {
	cout << n - del.size() << '\n';
	for (int i = 1; i <= n; i++) {
		bool ok = 1;
		for (auto v : del)
			if (v == i) ok = 0;
		if (ok) cout << i << ' ';
	}
}

void Hollwo_Pelw() {
	cin >> n;
	iota(p + 1, p + n + 1, 1);
	for (int i = 2; i <= n; i++) if (p[i] == i)
		for (int j = 2 * i; j <= n; j += i) p[j] = i;

	for (int i = 2; i <= n; i++) 
		if (p[i] == i) val[i] = rng();

	for (int i = 2; i <= n; i++) {
		hsh[i] = hsh[i / p[i]] ^ val[p[i]];
	}
	for (int i = 2; i <= n; i++) {
		hsh[i] ^= hsh[i - 1];
		tot ^= hsh[i];
	}

	if (tot == 0)
		return print(n, {});

	for (int i = 1; i <= n; i++)
		if (tot == hsh[i])
			return print(n, {i});

	if (n % 2 == 0)
		return print(n, {2, n / 2});

	map<uint64_t, int> mp;
	for (int i = 1; i <= n; i++) {
		if (mp.count(hsh[i]))
			return print(n, {i, mp[hsh[i]]});
		mp[tot ^ hsh[i]] = i;
	}

	-- n;
	print(n, {2, n / 2});
}