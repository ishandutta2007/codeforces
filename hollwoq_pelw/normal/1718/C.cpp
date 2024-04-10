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
	cerr << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

#define int long long

int n, m, q, a[N];

void Hollwo_Pelw(){
	cin >> n >> q;
	vector<vector<int>> sum;
	vector<multiset<int>> best;
	vector<int> d(1, 1), p(n, 1);
	for (int i = 2; i < n; i++) if (p[i]) {
		if (n % i == 0) d.push_back(n / i);
		for (int j = i * 2; j < n; j += i) p[j] = 0;
	}
	sum.resize(m = d.size());
	best.resize(m);

	for (int i = 0; i < m; i++)
		sum[i].resize(d[i]);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum[j][i % d[j]] += a[i];

	int res = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < d[i]; j++)
			best[i].insert(sum[i][j]);
		res = max(res, (*best[i].rbegin()) * d[i]);
	}

	cout << res << '\n';

	for (int p, x; q --; ) {
		cin >> p >> x, p --;
		int res = 0;
		for (int j = 0; j < m; j++) {
			
			best[j].erase(best[j].find(sum[j][p % d[j]]));
			sum[j][p % d[j]] += x - a[p];
			best[j].insert(sum[j][p % d[j]]);

			res = max(res, (*best[j].rbegin()) * d[j]);
		}
		a[p] = x;
		cout << res << '\n';
	}
}