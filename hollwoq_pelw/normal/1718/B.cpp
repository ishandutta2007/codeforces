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

const int N = 105;

#define int long long

int n, a[N], b[N][N], fib[60], p[60];

void Hollwo_Pelw(){
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 55; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	for (int i = 0; i <= 55; i++)
		p[i] = fib[i] + (i ? p[i - 1] : 0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int tot = accumulate(a + 1, a + n + 1, 0ll);

	int c = 0;
	while (p[c] < tot) c ++;
	if (p[c] != tot)
		return cout << "NO\n", (void) 0;

	map<int, int> mp;
	for (int i = 1; i <= n; i++)
		mp[a[i]] ++;

	for (int j = c, P = -1; j >= 0; j--) {
		auto it = -- mp.end();

		if (it -> first < fib[j])
			return cout << "NO\n", (void) 0;

		if (it -> second == 1 && it -> first == P)
			break;

		if ((-- it -> second) == 0)
			mp.erase(it);

		mp[(P = it -> first - fib[j])] ++;
	}
	mp.erase(0);

	cout << (mp.empty() ? "YES\n" : "NO\n");
}