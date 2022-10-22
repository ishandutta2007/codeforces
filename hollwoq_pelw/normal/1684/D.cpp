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

int n, k, a[N], b[N], jump[N];

void Hollwo_Pelw(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], b[i] = i, jump[i] = 0;
	sort(b + 1, b + n + 1, [&](const int &i, const int &j){
		return a[i] + i > a[j] + j;
	});

	for (int i = 1; i <= k; i++)
		jump[b[i]] = 1;

	int res = 0;

	for (int i = 1, f = 0; i <= n; i++) {
		if (jump[i]) {
			f ++;
		} else {
			res += a[i] + f;
		}
	}

	cout << res << '\n';
}