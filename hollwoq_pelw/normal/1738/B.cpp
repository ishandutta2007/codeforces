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

const int N = 1e5 + 5;

int n, k, s[N];

void Hollwo_Pelw(){
	cin >> n >> k;
	for (int i = n - k + 1; i <= n; i++)
		cin >> s[i];
	for (int i = n; i > n - k + 1; i--)
		s[i] -= s[i - 1];
	for (int i = n - k + 3; i <= n; i++)
		if (s[i] < s[i - 1])
			return cout << "No\n", (void) 0;
	if (k == 1)
		return cout << "Yes\n", (void) 0;
	int mx = s[n - k + 2], sm = s[n - k + 1], ct = n - k + 1;
	if (sm > mx * ct)
		return cout << "No\n", (void) 0;
	cout << "Yes\n";
}