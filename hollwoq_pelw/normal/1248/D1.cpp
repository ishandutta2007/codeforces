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

const int N = 505;

int n, mx, fi, fj;
char s[N];

void Hollwo_Pelw() {
	int c = 0;
	cin >> n >> (s + 1);
	for (int i = 1; i <= n; i++)
		c += (s[i] == '(' ? 1 : -1);
	if (c) return cout << "0\n1 1", (void) 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			swap(s[i], s[j]);

			int c = 0, mn = 1e9, cnt = 0;
			for (int k = 1; k <= n; k++) {
				c += (s[k] == '(' ? 1 : -1);
				if (c < mn)
					mn = c, cnt = 1;
				else if (mn == c)
					cnt ++;
			}
			if (cnt > mx)
				mx = cnt, fi = i, fj = j;
			swap(s[i], s[j]);
		}
	cout << mx << '\n' << fi << ' ' << fj;
}