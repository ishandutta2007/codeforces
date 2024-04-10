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

const int N = 5e4 + 5;

vector<pair<int, int>> opt;

int n, m, a[N];

void solve(int n, int p) {
	if (n <= 2) {
		for (int i = 1; i <= n; i++)
			a[m ++] = p * i;
		return ;
	}
	int q = 1 << __lg(n), i = 1;

	a[m ++] = p * q;

	if (n == q)
		return solve(n - 1, p);

	for (; q + i <= n; i++) {
		a[m ++] = p * (q << 1);
		opt.emplace_back(p * (q - i), p * (q + i));
	}

	solve(i - 1, p << 1);
	solve(q - i, p);
}

void Hollwo_Pelw() {
	cin >> n, m = 0;
	solve(n, 1);
	
	assert(m == n);
	sort(a, a + n);

	if (n <= 2)
		return cout << "-1\n", (void) 0;

	for (int i = 1; i < n; i++) {
		if (a[i - 1] == a[i]) {
			opt.emplace_back(a[i], a[i]);
			a[i] <<= 1, a[i - 1] = 0; break ;
		}
	}

	for (int i = 0; i < n; i++)
		while (a[i] && a[i] < n) {
			opt.emplace_back(0, a[i]);
			opt.emplace_back(a[i], a[i]);
			a[i] <<= 1;
		}
	opt.emplace_back(a[n - 1], 0);

	cout << opt.size() << '\n';
	for (auto [x, y] : opt)
		cout << x << ' ' << y << '\n';
	opt.clear();
}