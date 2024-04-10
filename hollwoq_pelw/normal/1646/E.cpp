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

#define int long long

const int N = 1e6 + 5;

int n, m, vis[N], cnt[25], cur = 0, have[N * 25], res = 1;

void Hollwo_Pelw(){
	cin >> n >> m;

	for (int i = 2; i <= n; i++) if (!vis[i]) {
		int p = 0;
		for (int j = i; j <= n; j *= i)
			vis[j] = 1, p ++;
		cnt[p] ++;
	}

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= m; j++)
			cur += have[i * j] == 0, have[i * j] = 1;
		res += cur * cnt[i];
	}

	cout << res << '\n';
}