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

const int N = 5005;

int n, a[N], p[N][N], s[N][N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		p[i][1] = 0;
		for (int j = 1; j < i; j++)
			p[i][j + 1] = p[i][j] + (a[j] < a[i]);
	}

	for (int i = n; i >= 1; i--) {
		s[i][n] = 0;
		for (int j = n; j > i; j--)
			s[i][j - 1] = s[i][j] + (a[j] < a[i]);
	}

	long long res = 0;

	for (int b = 1; b <= n; b++)
		for (int c = b + 1; c <= n; c++)
			res += 1ll * p[c][b] * s[b][c];

	cout << res << '\n';
}