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

const int N = 5e4 + 5;

int n, a[N][5];

bool comp(int i, int j) {
	int c = 0;
	for (int x = 0; x < 5; x++)
		c += a[i][x] > a[j][x];
	return c >= 3;
}

bool check(int c) {
	for (int i = 1; i <= n; i++)
		if (i != c && !comp(i, c))
			return 0;
	return 1;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++)
			cin >> a[i][j];
	int cur = 1;
	for (int i = 2; i <= n; i++)
		if (comp(cur, i)) cur = i;
	if (!check(cur))
		cur = -1;
	cout << cur << '\n';
}