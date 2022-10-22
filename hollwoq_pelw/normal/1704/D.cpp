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
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 2e5 + 5;

int n, m;
__int128 a[N];

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
		for (int j = 1, x, t = 0; j <= m; j++)
			cin >> x, t += x, a[i] += t;
	}
	cout << (min_element(a + 1, a + n + 1) - a) << ' ' << (int) (*max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1)) << '\n';
}