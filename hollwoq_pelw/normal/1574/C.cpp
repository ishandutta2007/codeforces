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

#define int long long

int n, m, tot;
set<int> st1, st2;

inline int calc(int x, int y, int t) {
	// choose t to fight with x
	return max(x - t, 0ll) + max(y - (tot - t), 0ll);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, a; i <= n; i++)
		cin >> a, st1.insert(a), tot += a;
	// for (auto v : st1) st2.insert(tot - v);
	cin >> m;
	for (int x, y; m --; ) {
		cin >> x >> y;
		
		int res = 2e18;
		// choose a[i] >= x to kill dragon ?
		{
			auto it = st1.lower_bound(x);
			if (it != st1.end())
				res = min(res, calc(x, y, *it));
			if (it != st1.begin())
				-- it, res = min(res, calc(x, y, *it));
		}
		// choose tot - a[i] >= y to defence dragon
		{
			// auto it = st2.lower_bound(y);

		}
		cout << res << '\n';
	}
}