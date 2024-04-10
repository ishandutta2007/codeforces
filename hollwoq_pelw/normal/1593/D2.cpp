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
	FAST_IO("1593D2.inp", "1593D2.out");
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

int n, a[45];
 
void Hollwo_Pelw() {
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i], a[i] += 1e6 + 1;
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int t = abs(a[i] - a[j]);
			for (int j = 1; j * j <= t; j++) {
				if (t % j == 0) {
					s.insert(j);
					s.insert(t / j);
				}
			}
		}
	}
 
	s.insert(1e9);
	vector<int> val(s.begin(), s.end());
	sort(val.rbegin(), val.rend());
 
	for (auto v : val) {
		map<int, int> mp;
		for (int i = 0; i < n; i++)
			mp[a[i] % v] ++;
		bool ok = 0;
		for (auto [v, p] : mp)
			ok |= p >= n / 2;
		if (ok) {
			cout << (v == 1e9 ? -1 : v) << '\n';
			return ;
		}
	}
}