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

int n, d[5], ok[5], val[5];
 
inline int query(int a, int b, int c) {
	cout << "? " << val[a] << ' ' << val[b] << ' ' << val[c] << endl;
	int res; cin >> res; return res;
}
 
inline pair<int, int> solve(int v1, int v2, int v3, int v4) {
	val[1] = v1;
	val[2] = v2;
	val[3] = v3;
	val[4] = v4;
	d[4] = query(1, 2, 3);
	d[3] = query(1, 2, 4);
	d[2] = query(1, 3, 4);
	d[1] = query(2, 3, 4);
 
	int x = *max_element(d + 1, d + 5), f = 0, s = 0, o = 0;
 
	fill(ok + 1, ok + 5, 1);
 
	for (int i = 1, c = 0; i <= 4 && c < 2; i++) {
		if (d[i] == x) ok[i] = 0, c ++, o = i;
	}
 
	for (int i = 1; i <= 4; i++) {
		if (ok[i] && !f) { f = i; continue ; }
		if (ok[i] && !s) { s = i; continue ; }
	}
 
	return {val[f], val[s]};
}
 
void Hollwo_Pelw() {
	cin >> n;
 
	auto [f, s] = solve(1, 2, 3, 4);
 
	for (int i = 5; i < n; i += 2)	{
		auto [nf, ns] = solve(f, s, i, i + 1);
		f = nf, s = ns;
	}
 
	if (n & 1) {
		for (int i = 1; i < n; i++)
			if (i != f && i != s) {
				auto [nf, ns] = solve(f, s, i, n);
				f = nf, s = ns;
				break ;
			}
	}
 
	cout << "! " << f << ' ' << s << endl;
}