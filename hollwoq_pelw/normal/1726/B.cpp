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

int n, m;

void Hollwo_Pelw(){
	cin >> n >> m;
	if (m < n)
		return cout << "No\n", (void) 0;

	vector<int> a;
	while (n > 2) {
		n -= 2, m -= 2;
		a.push_back(1);
		a.push_back(1);
	}

	if (n == 2 && m % 2 != 0)
		return cout << "No\n", (void) 0;		

	cout << "Yes\n";
	if (n == 2)
		a.push_back(m / 2), a.push_back(m / 2);
	else
		a.push_back(m);
	for (int x : a)
		cout << x << ' ';
	cout << '\n';
}