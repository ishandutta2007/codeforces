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
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

int n, a[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int l = 0, r = - 1, b = 0;
	
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && (a[i] == 0) == (a[j] == 0)) j ++;
		if (a[i] == 0) continue ;

		int cnt = 0, s = 1;
		for (int k = i; k < j; k ++) {
			cnt += abs(a[k]) == 2;
			if (a[k] < 0) s = - s;
		}

		if (s > 0) {
			if (b < cnt)
				l = i, r = j - 1, b = cnt;
		} else {
			{
				int c0 = cnt;
				for (int k = i; k < j; k ++) {
					c0 -= abs(a[k]) == 2;
					if (a[k] < 0) {
						if (b < c0)
							l = k + 1, r = j - 1, b = c0;
					}
				}
			}
			{
				int c0 = cnt;
				for (int k = j - 1; k >= i; k --) {
					c0 -= abs(a[k]) == 2;
					if (a[k] < 0) {
						if (b < c0)
							l = i, r = k - 1, b = c0;
					}
				}
			}
		}
	}

	cout << l << ' ' << n - 1 - r << '\n';
}