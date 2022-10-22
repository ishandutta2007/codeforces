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

const int N = 6006;

int n, cnt[16];
bool f[16][16]; // = 0 if odd, 1 if even

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0, x, y; i < n; i++)
		cin >> x >> y, cnt[(x % 4) * 4 + y % 4] ++;

	for (int i = 0; i < 16; i++) {
		int x1 = i / 4, y1 = i % 4;
		for (int j = 0; j < 16; j++) {
			int x2 = j / 4, y2 = j % 4;

			int sx = abs(x1 - x2), sy = abs(y1 - y2);
			f[j][i] = f[i][j] = (1 + (sx + 1) % 4 * (sy + 1) % 4 + __gcd(sx, sy)) % 4 == 2;
		}
	}

	long long res = 0;
	for (int i = 0; i < 16; i++) if (cnt[i]) {
		int v1 = cnt[i];
		cnt[i] --;
		for (int j = 0; j < 16; j++) if (cnt[j]) {
			int v2 = cnt[j];
			cnt[j] --;
			for (int k = 0; k < 16; k++) if (cnt[k]) {
				if (f[i][j] ^ f[j][k] ^ f[k][i])
					res += 1ll * v1 * v2 * cnt[k];
			}
			cnt[j] ++;
		}
		cnt[i] ++;
	}
	cout << res / 6 << '\n';
}