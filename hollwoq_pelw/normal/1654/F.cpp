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
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
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

const int N = 1 << 18;

int n, f[N];
string s;

void Hollwo_Pelw(){
	cin >> n >> s, n = 1 << n;

	for (int i = 0; i < n; i++)
		f[i] = s[i] - 'a';
	
	vector<pair<int, int>> val, p(n);

	for (int len = 1; len < n; len <<= 1) {
		for (int i = 0; i < n; i += len * 2) {
			for (int j = 0; j < len; j++) {
				p[i + j]       = {f[i + j], f[i + j + len]};
				p[i + j + len] = {f[i + j + len], f[i + j]};
			}
		}
		val = p, sort(val.begin(), val.end());
		val.erase(unique(val.begin(), val.end()), val.end());
		for (int i = 0; i < n; i++)
			f[i] = lower_bound(val.begin(), val.end(), p[i]) - val.begin();
	}

	int x = min_element(f, f + n) - f;
	
	for (int i = 0; i < n; i++)
		cout << s[i ^ x];
}