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

const int N = 2e5 + 5;

int n, a, b, ok[N];

void solve(int wa, int wb, int pa, int pb) {
	for (int i = 0; i <= wa; i++) {
		int a0 = i; // a win a
		int a1 = wa - i; // a win b
		int b0 = pb - a1; // b win b
		int b1 = wb - b0; // b win a
		if (b0 < 0 || b1 < 0) continue ;
		ok[a1 + b1] = 1;
	}
}

void Hollwo_Pelw() {
	cin >> a >> b, n = a + b;
	for (int i = 0; i <= n; i++) ok[i] = 0;
	solve(a, b, n / 2, n - n / 2);
	solve(a, b, n - n / 2, n / 2);
	int c = 0;
	for (int i = 0; i <= n; i++) 
		if (ok[i]) c++;
	cout << c << '\n';
	for (int i = 0; i <= n; i++)
		if (ok[i]) cout << i << ' ';
	cout << '\n';
}