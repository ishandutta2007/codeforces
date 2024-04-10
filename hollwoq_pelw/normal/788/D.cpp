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
	if (fopen("A.inp", "r"))
		assert(freopen("A.inp", "r", stdin)), assert(freopen("A.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int lim = 1e8;

mt19937_64 rng(*(new char));

inline int rnd(int l = -lim, int r = lim) {
	return rng() % (r - l + 1) + l;
}

inline int ask(int x, int y) {
	cout << "0 " << x << ' ' << y << endl; 
	int r; cin >> r; return assert(r != -1), r;
}

vector<int> xs, ys;

void Hollwo_Pelw(){
	int nx = rnd(), ny = rnd();
	while (!ask(nx, ny))
		nx = rnd(), ny = rnd();

	// (nx, ny) -> among us

	auto is_x = [&](int a) -> bool { return !ask(a, ny); };
	auto is_y = [&](int a) -> bool { return !ask(nx, a); };

	int cur = - lim - 1;

	while (1) {
		int l = 0, r = 28;
		while (l < r) {
			int m = (l + r) >> 1, a = cur + (1 << m);

			if (a <= lim && ask(a, a) == (1 << m))
				l = m + 1;
			else
				r = m;
		}

		if (cur + (1 << l) > lim) break ;

		int add = ask(cur + (1 << l), cur + (1 << l));

		cur += (1 << l) + add;

		if (is_x(cur)) xs.push_back(cur);
		if (is_y(cur)) ys.push_back(cur);
	
	}

	cout << "1 " << xs.size() << ' ' << ys.size() << '\n';
	for (int x : xs) cout << x << ' '; cout << '\n';
	for (int y : ys) cout << y << ' '; cout << '\n';
}