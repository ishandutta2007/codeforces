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

int n, r[4], c[4];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> r[i] >> c[i];
	vector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[(r[i] & 1) << 1 | (c[i] & 1)] ++;
	if (count(a.begin(), a.end(), 1) == 4)
		return cout << "NO\n", (void) 0;
	vector<pair<int, int>> f, g;
	for (int i = 0; i < 3; i++)
		f.emplace_back(r[i], c[i]);
	sort(f.begin(), f.end());

	g = {{1, 1}, {1, 2}, {2, 1}};
	sort(g.begin(), g.end());

	if (f == g) {
		if (r[3] == 1 || c[3] == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
		return ;
	}

	g = {{1, n}, {1, n - 1}, {2, n}};
	sort(g.begin(), g.end());

	if (f == g) {
		if (r[3] == 1 || c[3] == n)
			cout << "YES\n";
		else
			cout << "NO\n";
		return ;
	}
	
	g = {{n, 1}, {n, 2}, {n - 1, 1}};
	sort(g.begin(), g.end());

	if (f == g) {
		if (r[3] == n || c[3] == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
		return ;
	}
	
	g = {{n, n}, {n, n - 1}, {n - 1, n}};
	sort(g.begin(), g.end());

	if (f == g) {
		if (r[3] == n || c[3] == n)
			cout << "YES\n";
		else
			cout << "NO\n";
		return ;
	}
	
	cout << "YES\n";
}