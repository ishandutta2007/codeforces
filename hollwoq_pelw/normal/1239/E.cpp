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

const int N = 55, M = 5e4 + 5;

int n, a[N];
uint8_t dp[N][N * M];
bool choose[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + 2 * n + 1);

	dp[0][0] = 1;

	for (int i = 3; i <= 2 * n; i++) {
		for (int j = n; j --; ) for (int k = N * M; k --; )
			if (dp[j][k] && k + a[i] < N * M && !dp[j + 1][k + a[i]])
				dp[j + 1][k + a[i]] = i;
	}

	int tot = accumulate(a + 3, a + 2 * n + 1, 0), p = -1;

	for (int i = 0; i < N * M; i++) {
		if (dp[n - 1][i] && max(i, tot - i) < max(p, tot - p)) p = i;
	}

	vector<int> f[2];
	f[0].push_back(a[1]);
	f[1].push_back(a[2]);

	for (int i = n - 1; i; i--)
		choose[dp[i][p]] = 1, p -= a[dp[i][p]];

	for (int i = 3; i <= 2 * n; i++)
		f[choose[i]].push_back(a[i]);

	for (int i = 0; i < 2; i++)
		sort(f[i].begin(), f[i].end());
	reverse(f[1].begin(), f[1].end());

	for (int i = 0; i < 2; i++) {
		for (int x : f[i])
			cout << x << ' ';
		cout << '\n';
	}
}