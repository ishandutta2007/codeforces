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
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExcution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

int n, m, q, p[N], pos[N], a[N];
string s;

void Hollwo_Pelw(){
	cin >> n >> q >> s;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1])
			p[++ m] = s[i] == '1' ? 1 : -1;
		pos[i + 1] = m;
	}
	for (int i = 1; i <= m; i++)
		p[i] += p[i - 1];

	for (int l, r; q --; ) {
		cin >> l >> r, l = pos[l], r = pos[r];
		cout << 1 + (r - l + abs(p[r] - p[l])) / 2 << '\n';
	}
}