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

const int N = 2e5 + 5;

int n, a[N], b[N];
vector<pair<int, int>> v[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		v[i].clear();
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = n; i; i--)
		v[a[i]].emplace_back(i, 1);

	for (int i = 1, j = 1; i <= n; i++) {
		for (; j < v[b[i]].back().first; j++) {
			auto p = v[a[j]].back();

			v[a[j]].pop_back();

			if (v[a[j]].empty())
				return cout << "NO\n", (void) 0;

			v[a[j]].back().second += p.second;
		}
		v[b[i]].back().second --;
		if (v[b[i]].back().second == 0)
			v[b[i]].pop_back(), j ++;
	}

	cout << "YES\n";
}