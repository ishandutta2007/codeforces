/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
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
	return 0;
}

const int N = 2e5 + 5;

int n, dp[N], a[N], prv[N];
int st[N << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void update(int p, int v, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return st[id] = v, (void) 0;
	(p > tm ? update(p, v, right)
			: update(p, v, left));
	st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return -1e9;
	if (l <= tl && tr <= r) return st[id];
	return max(query(l, r, left), query(l, r, right));
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset(st, - 0x3f, sizeof st);

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (!prv[a[i]]) {
			prv[a[i]] = i;
		} else {
			dp[i] = max(dp[i], query(prv[a[i]], i - 1) + i - 1);
		}
		update(i, dp[i] - i);
	}
	cout << dp[n];
}