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

const int N = 1005;

int n, a[N], p[N], q[N];
string b[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	fill(b, b + n + 1, string(n, '0'));
	iota(p + 1, p + n + 1, 1);
	sort(p + 1, p + n + 1, [&](const int &i, const int &j){
		return a[i] > a[j];
	});
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[p[i]]; j++)
			b[(j + i) % (n + 1)][p[i] - 1] = '1';
	}
	cout << n + 1 << '\n';
	for (int i = 0; i <= n; i++)
		cout << b[i] << '\n';
}