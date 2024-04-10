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
vector<int> pos[N], cyc[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 0; i <= n; i++)
		pos[i].clear(), cyc[i].clear();
	for (int i = 1; i <= n; i++)
		cin >> a[i], pos[a[i]].push_back(i);

	vector<int> f(n);
	iota(f.begin(), f.end(), 1);
	sort(f.begin(), f.end(), [&](const int &i, const int &j){
		return pos[i].size() < pos[j].size();
	});

	for (int i : f) {
		for (int j = 0; j < (int) pos[i].size(); j++)
			cyc[j].push_back(pos[i][j]);
	}

	for (int i = 0; i < n; i++) if (cyc[i].size()) {
		for (int j = 1; j < (int) cyc[i].size(); j++)
			b[cyc[i][j]] = a[cyc[i][j - 1]];
		b[cyc[i][0]] = a[cyc[i].back()];
	}

	for (int i = 1; i <= n; i++)
		cout << b[i] << " \n"[i == n];
}