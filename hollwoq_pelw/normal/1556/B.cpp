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
const int N = 1e5 + 5;

int n, a[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++)
		cin >> x, a[i] = x & 1;
	vector<int> v;
	for (int i = 1; i <= n; i++)
		if (a[i]) v.push_back(i);
	int sz = v.size(), res = 1e18;
	if (sz == n / 2 || (n % 2 == 1 && sz == n / 2 + 1)) {
		if (n % 2 == 1) {
			if (sz == n / 2) {
				int cur = 0;
				for (int i = 2, j = 0; i <= n; i += 2, j++)
					cur += abs(v[j] - i);
				res = min(res, cur);
			} else {
				int cur = 0;
				for (int i = 1, j = 0; i <= n; i += 2, j++)
					cur += abs(v[j] - i);
				res = min(res, cur);
			}
		} else {
			{
				int cur = 0;
				for (int i = 1, j = 0; i <= n; i += 2, j++)
					cur += abs(v[j] - i);
				res = min(res, cur);
			}
			{
				int cur = 0;
				for (int i = 2, j = 0; i <= n; i += 2, j++)
					cur += abs(v[j] - i);
				res = min(res, cur);
			}
		}
	} else {
		res = -1;
	}
	cout << res << '\n';
}