/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/


#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
#pragma GCC target ("avx,avx2,fma,sse,sse2,sse3,sse4")

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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

int q, t, l, r, x, a[100001][2], upd = 0;
long long res;

void Hollwo_Pelw() {
    cin >> q; while (q --) {
		cin >> t >> l >> r;
		if (t == 1) {
			upd = 1;
			cin >> x;
			if (x < 0)
				x = -x, t = 0;
			for (int i = l; i < r; i++)
				a[i][t] = !a[i][t] || a[i][t] > x ? x : a[i][t];
		} else {
			res = 0;
			if (upd) for (int i = l; i < r; i++)
				res += a[i][0] && a[i][1] ? a[i][0] + a[i][1] : 0;
			cout << res << '\n'; 
		}
	}
}