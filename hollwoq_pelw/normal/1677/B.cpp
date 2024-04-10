#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExcution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 1e6 + 5;

int n, m, vis[N], pre[N], row[N], col[N];
string s;

inline void solve_col() {
	fill(vis, vis + m, 0);
	int cur = 0;

	for (int i = 0; i < n * m; i++) {
		if (s[i] == '1' && !vis[i % m])
			vis[i % m] = 1, cur ++;
		col[i] = cur;
	}
}

inline void solve_row() {
	pre[0] = 0;
	for (int i = 0; i < n * m; i++)
		pre[i + 1] = pre[i] + (s[i] == '1');

	for (int i = 0, p = 0; i < m; i++) {
		row[i] = p = (pre[i + 1] > 0);
		for (int j = i + m, c = p; j < n * m; j += m) {
			c += (pre[j + 1] - pre[j - m + 1]) > 0, row[j] = c;
		}
	}
}

void Hollwo_Pelw(){
	cin >> n >> m >> s;
	solve_col(), solve_row();
	for (int i = 0; i < n * m; i++)
		cout << row[i] + col[i] << " \n"[i == n * m - 1];
}