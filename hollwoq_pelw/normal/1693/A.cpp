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

const int N = 2e5 + 5;

#define int long long

int n, a[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i];
		if (cur < 0) {
			cout << "No\n";
			return ;
		}
		a[i] = cur;
	}
	if (cur) {
		cout << "No\n";
		return ;
	}
	int zer = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0)
			zer = 1;
		if (a[i] && zer) {
			cout << "No\n";
			return ;
		}
	}
	cout << "Yes\n";
}