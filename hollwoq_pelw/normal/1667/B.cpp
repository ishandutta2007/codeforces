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

#define int long long

const int N = 5e5 + 5;

int n, a[N], dp[N], bit1[N], bit2[N], bit3[N], ver1[N], ver2[N], ver3[N], vercnt;

inline void add1(int p, int x) {
	for (; p < N; p += p & -p) {
		if (ver1[p] != vercnt)
			ver1[p] = vercnt, bit1[p] = - 1e9;
		bit1[p] = max(bit1[p], x);
	}
}

inline int query1(int p) {
	int r = - 1e9;
	for (; p > 0; p -= p & -p) {
		if (ver1[p] != vercnt)
			ver1[p] = vercnt, bit1[p] = - 1e9;
		r = max(r, bit1[p]);
	}
	return r;
}

inline void add2(int p, int x) {
	for (; p > 0; p -= p & -p) {
		if (ver2[p] != vercnt)
			ver2[p] = vercnt, bit2[p] = - 1e9;
		bit2[p] = max(bit2[p], x);
	}
}

inline int query2(int p) {
	int r = - 1e9;
	for (; p < N; p += p & -p) {
		if (ver2[p] != vercnt)
			ver2[p] = vercnt, bit2[p] = - 1e9;
		r = max(r, bit2[p]);
	}
	return r;
}

inline void add3(int p, int x) {
	if (ver3[p] != vercnt)
		ver3[p] = vercnt, bit3[p] = - 1e9;
	bit3[p] = max(bit3[p], x);
}

inline int query3(int p) {
	if (ver3[p] != vercnt)
		ver3[p] = vercnt, bit3[p] = - 1e9;
	return bit3[p];
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1];
	vector<int> v(a, a + n + 1);
	v.emplace_back(- 1e18);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i <= n; i++)
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();

	vercnt ++;

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		add1(a[i], dp[i] - i);
		add2(a[i], dp[i] + i);
		add3(a[i], dp[i]);

		dp[i + 1] = max({
			query1(a[i + 1] - 1) + i + 1,
			query2(a[i + 1] + 1) - i - 1,
			query3(a[i + 1])
		});
	}

	cout << dp[n] << '\n';
}