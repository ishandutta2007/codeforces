/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

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

const int N = 2e5 + 5;

int n, m, q, p[N], pos[N], lst[N], prv[18][N], ans[N];

inline int lastval(int p) {
	return p == 1 ? n : p - 1;
}

inline int lift(int v, int d) {
	for (int j = 17; j >= 0; j--)
		if (d >> j & 1)
			v = prv[j][v];
	return v;
}

void Hollwo_Pelw() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		cin >> p[i], pos[p[i]] = i;
	for (int i = 1, a; i <= m; i++) {
		cin >> a, prv[0][i] = lst[p[lastval(pos[a])]], lst[a] = i;
	}
	for (int i = 1; i < 18; i ++)
		for (int j = 1; j <= m; j++)
			prv[i][j] = prv[i - 1][prv[i - 1][j]];
	for (int i = 1; i <= m; i++)
		ans[i] = max(ans[i - 1], lift(i, n - 1));
	for (int i = 1, l, r; i <= q; i++) 
		cin >> l >> r, cout << (ans[r] >= l);
}