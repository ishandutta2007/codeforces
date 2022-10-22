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

const int N = 1e5 + 5;

int n, b[N];
vector<int> occ[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 0; i <= n + 1; i++)
		occ[i].clear();
	int l = 0, r = n;
	for (int i = 1; i <= n; i++)
		cin >> b[i], occ[b[i]].push_back(i);

	for (int i = 1; i <= n; i++) {
		if (b[i] < i)
			r = min(r, b[i]);
		else
			l = max(l, i);
	}

	cout << l << '\n';

	int st = n + 1;
	if (occ[n + 1].empty()) st = 0;

	vector<int> a;

	while (st != -1) {
		int nt = -1;
		for (int x : occ[st]) {
			if (!occ[x].empty())
				nt = x;
			else
				a.push_back(x);
		}
		if (nt != -1)
			a.push_back(nt);
		st = nt;
	}

	for (auto x : a)
		cout << x << ' ';
	cout << '\n';
}