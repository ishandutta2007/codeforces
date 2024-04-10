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

const int N = 110;

int r, c, k, tot;
char s[N * N], a[N * N];

char tochar(int x) {
	if (x < 26) return 'a' + x;
	if (x < 52) return 'A' + x - 26;
	return '0' + x - 52;
}

void Hollwo_Pelw() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		cin >> (s + i * c);
		if (i & 1)
			reverse(s + i * c, s + (i + 1) * c);
	}
	tot = 0;
	for (int i = 0; i < r * c; i++)
		if (s[i] == 'R') tot ++;

	for (int t = 0, i = 0; t < k; t++) {
		int x = tot / (k - t);
		tot -= x;
		while (i < r * c && x) {
			if (s[i] == 'R') x --;
			a[i ++] = tochar(t);
		}
		if (t == k - 1)
			while (i < r * c)
				a[i ++] = tochar(t);
	}

	for (int i = 0; i < r; i++) {
		if (i & 1)
			reverse(a + i * c, a + (i + 1) * c);
		for (int j = 0; j < c; j++)
			cout << a[i * c + j];
		cout << '\n';
	}
}