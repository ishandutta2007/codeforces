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

const int N = 2e5 + 5;

vector<int> a[N], b[N];
int n, m;

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		a[i].resize(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[j][i];
		}
	
	for (int i = 0; i < m; i++)
		b[i] = a[i];
	
	sort(b, b + m);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (b[j - 1][i] > b[j][i])
				return cout << "-1\n", (void) 0;
		}
	}

	vector<int> diff;

	for (int i = 0; i < m; i++) {
		if (a[i] != b[i])
			diff.push_back(i + 1);
	}

	if (diff.empty()) {
		cout << "1 1\n";
	} else if ((int) diff.size() == 2) {
		cout << diff[0] << ' ' << diff[1] << '\n';
	} else {
		cout << "-1\n";
	}
}