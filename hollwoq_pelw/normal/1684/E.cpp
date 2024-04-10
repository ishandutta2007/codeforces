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

int n, k, a[N], vis[N];

void Hollwo_Pelw(){
	cin >> n >> k;
	fill(vis, vis + n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= n)
			vis[a[i]] = 1;
	}
	int mex = 0;
	for (int f = k; mex < n && (f || vis[mex]); mex++)
		if (!vis[mex]) f --;

	map<int, int> mp;

	for (int i = 1; i <= n; i++) 
		if (a[i] >= mex) mp[a[i]] ++;

	vector<pair<int, int>> v;
	for (auto [p, c] : mp)
		v.emplace_back(c, p);
	
	sort(v.begin(), v.end());

	int res = v.size();

	for (auto [c, p] : v) {
		if (c <= k) {
			k -= c;
			res --;
		}
	}

	cout << res << '\n';
}