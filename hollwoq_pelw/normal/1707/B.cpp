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

void Hollwo_Pelw(){
	int n; cin >> n;
	vector<int> a(n);
	for (int &v : a) cin >> v;

	vector<pair<int, int>> cur;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[i] == a[j])
			j ++;
		cur.emplace_back(a[i], j - i);
	}

	for (int i = 1; i < n; i++) {
		map<int, int> nxt;
		for (auto [v, p] : cur)
			if (p > 1) nxt[0] += p - 1;
		for (int j = 1; j < (int) cur.size(); j++)
			nxt[cur[j].first - cur[j - 1].first] ++;
		cur.clear();
		for (auto [v, p] : nxt)
			cur.emplace_back(v, p);
	}
	cout << cur[0].first << '\n';
}