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

inline bool check(vector<int> a, int v, int tot) {
	int ov = tot - v * 2, n = a.size() - 2;
	if (a[n] == v) {
		swap(a[n], a[n + 1]);
	}
	for (int i = 0; i <= n; i++)
		if (a[i] == ov) {
			for (int j = 0; j <= n; j++)
				if (i ^ j) cout << a[j] << ' ';
			cout << '\n';
			return 1;
		}
	return 0;
}

void Hollwo_Pelw() {
	int n; cin >> n;
	vector<int> a(n + 2);
	int tot = 0;
	for (auto &v : a)
		cin >> v, tot += v;
	sort(a.begin(), a.end());
	if (check(a, a[n + 0], tot)) return ;
	if (check(a, a[n + 1], tot)) return ;
	cout << "-1\n";
}