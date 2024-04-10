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
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

#define int long long

int n, a[4][N], res;

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	
	int ca = 0, cb = 0;
	for (int i = 0; i < n; i++) {
		ca += a[0][i] - a[2][i];
		cb += a[1][i] - a[3][i];

		if (ca > 0 && cb < 0)
			ca --, cb ++, res ++;
		if (ca < 0 && cb > 0)
			ca ++, cb --, res ++;

		res += abs(ca) + abs(cb);
	}

	cout << (ca + cb ? -1 : res) << '\n';
}