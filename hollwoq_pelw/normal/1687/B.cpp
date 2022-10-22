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

#define int long long

const int N = 1005;

int n, m, w[N];

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s(m, '0');
		s[i] = '1';
		cout << "? " << s << endl;
		cin >> w[i];		
	}
	vector<int> ids(m);
	iota(ids.begin(), ids.end(), 0);
	sort(ids.begin(), ids.end(), [&](const int &i, const int &j){
		return w[i] < w[j];
	});

	string cur(m, '0');
	int mst = 0;

	for (int i : ids) {
		string tmp = cur;
		tmp[i] = '1';
		cout << "? " << tmp << endl;
		int val; cin >> val;
		if (val == mst + w[i]) {
			cur = tmp;
			mst = val;
		}
	}

	cout << "! " << mst << endl;
}