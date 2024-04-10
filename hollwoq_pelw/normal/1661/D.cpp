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
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

#define int long long

const int N = 3e5 + 5;

int n, k, a[N], b[N];

void Hollwo_Pelw(){
	cin >> n >> k;
	for (int i = n; i >= 1; i--)
		cin >> a[i];
 
	int val = 0, pre = 0;
 
	for (int i = 1; i <= n; i++) {
		a[i] -= val;
 
		if (a[i] > 0 && i + k <= n + 1)
			b[i] = a[i] / k + (a[i] % k > 0);
 
		a[i] -= b[i] * k;
		
		val += b[i] * k;
		pre += b[i];
		if (i >= k)
			pre -= b[i - k];
		val -= pre;
	}
 
	int res = 0;
 
	for (int i = n, j = 1; j <= k; i --, j ++)
		if (a[i] > 0) res = max(res, a[i] / j + (a[i] % j > 0));
 
	cout << res + accumulate(b + 1, b + n + 1, 0ll) << '\n';
}