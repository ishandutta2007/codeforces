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

int n, cnt[3][2];

char s[303][303];

bool solve(int lineX, int lineO, int tot) {
	if (lineX == lineO) return 0;
	if (cnt[lineX][1] + cnt[lineO][0] > tot / 3) return 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] != '.') {
				if ((i + j) % 3 == lineO) s[i][j] = 'O';
				if ((i + j) % 3 == lineX) s[i][j] = 'X';
			}
			cout << s[i][j];
		}
		cout << '\n';
	}
	return 1;
}

void Hollwo_Pelw() {
	cin >> n;
	int tot = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
			if (s[i][j] == 'X')
				cnt[(i + j) % 3][0] ++, tot ++; 
			if (s[i][j] == 'O')
				cnt[(i + j) % 3][1] ++, tot ++; 
		}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j ++) {
			if (solve(i, j, tot)) return ;
		}
	}
}