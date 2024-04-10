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

const int N = 1e5 + 5, B = 400;

int n, a[N], b[N], cnt[N * (B + 10) * 2], res = 1;

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		int l = max(1, i - N / B), r = min(n, i + N / B);
		for (int j = l; j <= r; j++) if (i != j) {
			if ((a[i] - a[j]) % (i - j) == 0) {
				int v = (a[i] - a[j]) / (i - j) + N * B;
				cnt[v] ++;
			}
		}
		for (int j = l; j <= r; j++) if (i != j) {
			if ((a[i] - a[j]) % (i - j) == 0) {
				int v = (a[i] - a[j]) / (i - j) + N * B;
				res = max(res, cnt[v] + 1);
			}
		}
		for (int j = l; j <= r; j++) if (i != j) {
			if ((a[i] - a[j]) % (i - j) == 0) {
				int v = (a[i] - a[j]) / (i - j) + N * B;
				cnt[v] --;
			}
		}
	}
	
	for (int i = -B; i <= B; i++) {
		for (int j = 1; j <= n; j++) {
			int v = a[j] - j * i + (i < 0 ? 0 : N * B);
			cnt[v] ++;
		}
		for (int j = 1; j <= n; j++) {
			int v = a[j] - j * i + (i < 0 ? 0 : N * B);
			res = max(res, cnt[v]);
		}
		for (int j = 1; j <= n; j++) {
			int v = a[j] - j * i + (i < 0 ? 0 : N * B);
			cnt[v] --;
		}
	}


	cout << n - res << '\n';
}