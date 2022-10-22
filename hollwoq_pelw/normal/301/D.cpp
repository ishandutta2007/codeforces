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
	FAST_IO("301D.inp", "301D.out");
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

const int N = 2e5 + 5;

int n, m, p[N];
vector<int> d[N];
vector<pair<int, int>> q[N];
int64_t res[N], bit[N];

inline void add(int p, int v) {
	for (; p; p -= p & -p)
		bit[p] += v;
}

inline int64_t query(int p) {
	int64_t r = 0;
	for (; p <= n; p += p & -p)
		r += bit[p];
	return r;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, x; i <= n; i++)
		cin >> x, p[x] = i;
	for (int i = 1; i <= n; i++) if (p[i])
		for (int j = i; j <= n; j += i) if (p[j])
			d[max(p[j], p[i])].push_back(min(p[j], p[i]));
	for (int i = 1, l, r; i <= m; i++)
		cin >> l >> r, q[r].emplace_back(l, i);

	for (int i = 1; i <= n; i++) {
		for (auto x : d[i]) add(x, 1);
		for (auto lx : q[i])
			res[lx.second] = query(lx.first);
	}
	for (int i = 1; i <= m; i++)
		cout << res[i] << '\n';
}