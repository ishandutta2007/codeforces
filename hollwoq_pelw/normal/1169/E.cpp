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

const int N = 3e5 + 5;

int n, q, a[N], cur[19], nxt[N][19];

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j <= 18; j++)
		cur[j] = nxt[n][j] = n;
	for (int i = n - 1; ~i; i--) {
		for (int j = 0; j <= 18; j++)
			nxt[i][j] = n;
		for (int j = 0; j <= 18; j++)
			if (a[i] >> j & 1) {
				for (int k = 0; k <= 18; k++)
					nxt[i][k] = min(nxt[i][k], nxt[cur[j]][k]);
				cur[j] = nxt[i][j] = i;
			}
	}
	for (int i = 0, x, y; i < q; i++) {
		cin >> x >> y, -- x, -- y;
		bool ok = 0;
		for (int j = 0; j <= 18; j++)
			ok |= (a[y] >> j & 1) && nxt[x][j] <= y;
		cout << (ok ? "Shi\n" : "Fou\n");
	}
}