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

const int N = 2e5 + 5, M = 1e6 + 5;

int n, m, x[N], p[N];

void Hollwo_Pelw(){
	cin >> n >> m;

	vector<pair<int, int>> vp, cl;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> p[i];
		vp.emplace_back(x[i] - p[i], 1);
		vp.emplace_back(x[i], - 2);
		vp.emplace_back(x[i] + p[i], 1);
	}

	sort(vp.begin(), vp.end());

	map<int, int> val, resl, resr;

	for (int i = 1, cur = 0, slp = 0; i < (int) vp.size(); i++) {
		slp += vp[i - 1].second;
		cur += slp * (vp[i].first - vp[i - 1].first);
		val[vp[i].first] = cur; 
	}

	for (int i = 1; i <= n; i++) {
		if (val[x[i]] > m) {
			cl.emplace_back(x[i], val[x[i]] - m);
		} else {
			cl.emplace_back(x[i], -1e18);
		}
	}

	int v1 = -1e18, v2 = -1e18;

	for (int j = 0; j < (int) cl.size(); j ++) {
		v1 = max(v1, cl[j].second - cl[j].first);
		v2 = max(v2, cl[j].second + cl[j].first);
	}

	for (int i = 1; i <= n; i++) {
		if (p[i] - x[i] < v1 || p[i] + x[i] < v2)
			cout << "0";
		else
			cout << "1";
	}
	cout << '\n';
}