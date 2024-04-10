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

const int N = 1 << 20;

int n, k, used[N], nxt[N];
string s;

void Hollwo_Pelw() {
	cin >> n >> k >> s;
	int m = min(k, 32 - __builtin_clz(n - k + 2)), zer = k - m;

	nxt[n] = 2e9;
	for (int i = n; i --; )
		nxt[i] = s[i] == '0' ? i : nxt[i + 1];

	fill(used, used + (1 << m), 0);

	for (int i = 0; i < n - k + 1; i++) {
		if (nxt[i] - i < zer) continue ;
		int v = 0;
		for (int j = i + zer; j < i + k; j++)
			v = v << 1 | (s[j] - '0');
		// cout << "osu " << v << '\n';
		used[((1 << m) - 1) ^ v] = 1;
	}

	int res = -1;
	for (int i = 0; i < 1 << m && res == -1; i++)
		if (!used[i]) res = i;

	if (res == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << string(zer, '0');
		for (int j = m; j --; )
			cout << (res >> j & 1);
		cout << '\n';
	}
}