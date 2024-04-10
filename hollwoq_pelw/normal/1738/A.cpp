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

int n, a[N];
vector<int> p[2];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	p[0].clear();
	p[1].clear();

	int res = 0;
	for (int i = 1, b; i <= n; i++)
		cin >> b, p[a[i]].push_back(b), res += b;
	
	sort(p[0].rbegin(), p[0].rend());
	sort(p[1].rbegin(), p[1].rend());

	int ans = 0;
	
	for (int i = 0; i < 2; i++) if (!p[i].empty()) {
		int n = p[i].size() - 1, m = p[i ^ 1].size();
		int cur = res;
		for (int j = 0; j < min(n, m); j++)
			cur += (p[i ^ 1][j] + p[i][j]);
		if (min(n, m) < m) cur += p[i ^ 1][min(n, m)];
		ans = max(ans, cur);
	}

	cout << ans << '\n';
}