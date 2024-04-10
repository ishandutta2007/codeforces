/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

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
	FAST_IO(".inp", ".out");
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

void Hollwo_Pelw() {
	int k, n, m;
	cin >> k >> n >> m;
	vector<int> a(n), b(m), res;
	for (auto &v : a) cin >> v;
	for (auto &v : b) cin >> v;
	for (int i = 0, j = 0; i < n || j < m; ) {
		if (i < n && a[i] <= k) {
			k += a[i] == 0; 
			res.push_back(a[i ++]);
			continue ; 
		}
		if (j < m && b[j] <= k) {
			k += b[j] == 0;
			res.push_back(b[j ++]);
			continue ;
		}
		break ;
	}
	if (res.size() < n + m)
		cout << -1 << '\n';
	else {
		for (auto v : res)
			cout << v << ' ';
		cout << '\n';
	}
}