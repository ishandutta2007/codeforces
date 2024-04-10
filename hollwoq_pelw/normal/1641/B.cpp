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

const int N = 505;

int n, m, a[N], pos[N];
vector<pair<int, int>> opt;
vector<int> res;

void do_insert(int p, int c) {
	opt.emplace_back(p, c);
}

void Hollwo_Pelw() {
	map<int, int> mp;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mp[a[i]] ++, pos[i] = i;

	for (auto [x, y] : mp)
		if (y & 1) return cout << "-1\n", (void) 0;

	opt.clear();
	res.clear();

	int m = n, ext = 0;

	for (int i = 1; i <= n; i += 2) {
		int j = i + 1;
		vector<int> toadd;
		while (j <= n && a[j] != a[i]) 
			toadd.push_back(a[j ++]);

		int f = j + ext;

		for (int v : toadd)
			do_insert(f ++, v);

		m += 2 * toadd.size();
		ext += 2 * toadd.size();
		res.push_back(toadd.size() + 1);

		reverse(a + i + 1, a + j + 1);

		// for (int j = 1; j <= n; j++)
		// 	cout << a[j] << " \n"[j == n];
	}

	cout << opt.size() << '\n';
	for (auto [x, y] : opt)
		cout << x << ' ' << y << '\n';

	cout << res.size() << '\n';
	for (int v : res) cout << v * 2 << ' ';
	cout << '\n';
}