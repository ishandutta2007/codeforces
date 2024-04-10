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
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
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

const int N = 2e5 + 5;

int n, a[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	int tot = accumulate(a + 1, a + n + 1, 0ll);

	if (a[n] * (n - 2) + tot < 0 || a[1] * (n - 2) + tot > 0)
		return cout << "INF\n", (void) 0;
	
	int fa = a[n] * (n - 2) + tot, fb = - (n - 1) * a[n] * a[n]; // a * t + b

	int res = fb;
	for (int i = n; i > 1; i--) {
		fb += fa * (a[i] - a[i - 1]);
		res = max(res, fb);
		fa += a[1] - a[n];
	}

	cout << res << '\n';
}