#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("C.inp", "r")){
		freopen("C.inp", "r", stdin);
		freopen("C.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

#define int long long

void Hollwo_Pelw(){
	int n, q; cin >> n;

	map<int, int> res, cur, lst;

	for (int i = 1, a; i <= n; i++) {
		swap(cur, lst);
		cur.clear();
		cin >> a;

		for (auto [v, c] : lst)
			cur[__gcd(v, a)] += c;
		cur[a] ++;

		for (auto [v, c] : cur)
			res[v] += c;
	}

	cin >> q;
	for (int x; q --; ) {
		cin >> x, cout << res[x] << '\n';
	}
}