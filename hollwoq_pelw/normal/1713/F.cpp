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
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

vector<int> solve(int n, vector<int> b) {
	if (n == 1) return b;
	int ne = n - n / 2, no = n / 2;

	vector<int> be(ne), bo(no), a(n);

	for (int i = 0; i < n; i++) {
		if (i & 1) 
			bo[i >> 1] = b[i];
		else
			be[i >> 1] = b[i];
	}

	vector<int> ae = solve(ne, be);
	if (ne > no) { // ae.back() == a[n - 1]
		a.back() = ae.back();
		for (int i = 0; i < no; i++) {
			if ((i << 1 | 1) & (n - 1)) 
				continue;
			bo[i] ^= a.back();
		}
	}
	
	vector<int> ao = solve(no, bo);
	for (int i = 0; i < no; i++) {
		a[i << 1] = ao[i];
		a[i << 1 | 1] = ae[i] ^ ao[i];
	}

	return a;
}

void Hollwo_Pelw(){
	int n; cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<int> a = solve(n, b);

	for (int i = n; i --; )
		cout << a[i] << ' ';
}