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

#define int long long

const int N = 2e5 + 5;

int n, tot, a[N];

void Hollwo_Pelw(){
	cin >> n, tot = 0;
	map<int, int> cnt;
	for (int i = 1; i <= n; i++)
		cin >> a[i], tot += a[i], cnt[a[i]] ++;

	map<int, int> l1, l2;
	l1[tot] ++;

	for (int t = 100; t -- && l1.size(); ) {
		l2.clear();
		for (auto &[x, y] : l1) {
			if (cnt[x] > y) {
				cnt[x] -= y;
			} else {
				if (y > cnt[x]) {
					int v = y - cnt[x];
					if (v) {
						l2[x / 2] += v;
						l2[x - x / 2] += v;
					}
				}
				cnt[x] = 0;
			}
		}
		swap(l1, l2);
	}
	for (auto [x, y] : cnt)
		if (y) return cout << "NO\n", (void) 0;
	cout << "YES\n";
}