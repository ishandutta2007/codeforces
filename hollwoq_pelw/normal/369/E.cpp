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
	// cin >> testcases;
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

const int N = 1e6 + 5, M = 3e5 + 5;

int n, m, bit[N], last[M], res[M];
vector<int> q[N], v[N];

inline void add(int p, int v) {
	for (; p < N; p += p & -p)
		bit[p] += v;
}

inline int query(int p) {
	int r = 0;
	for (; p > 0; p -= p & -p)
		r += bit[p];
	return r;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, l, r; i <= n; i++)
		cin >> l >> r, v[r].push_back(l);

	fill(res + 1, res + m + 1, n);

	for (int i = 1, j, k; i <= m; i++) {
		q[0].push_back(i);
		q[N - 1].push_back(i);
		for (cin >> k; k --; )
			cin >> j, q[j].push_back(i);
	}

	for (int i = 1; i < N; i++) {
		for (auto x : q[i]) {
			res[x] -= query(i - 1) - query(last[x]);
			last[x] = i;
		}
		for (auto x : v[i])
			add(x, 1);
	}

	for (int i = 1; i <= m; i++)
		cout << res[i] << "\n";
}