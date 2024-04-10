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

const int N = 3e5 + 5;

int n, a[N], b[N];

pair<int, int> dp[N];
pair<int, int> st[N << 2];
 
#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void update(int l, int r, pair<int, int> v, int id = 1, int tl = 0, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) {
		st[id] = min(st[id], v);
		return ;
	}
	update(l, r, v, left), update(l, r, v, right);
}

pair<int, int> query(int p, int id = 1, int tl = 0, int tr = n) {
	pair<int, int> res = st[id];
	if (tl != tr) {
		if (p <= tm)
			res = min(res, query(p, left));
		else
			res = min(res, query(p, right));
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	memset(dp, 0x3f, sizeof dp);
	memset(st, 0x3f, sizeof st);

	dp[n] = {0, -1};
	update(n - a[n], n, {dp[n].first + 1, n});

	for (int i = n - 1; i >= 0; i--) {
		dp[i] = query(i);
		if (dp[i].first >= N) continue ;

		int np = i + b[i];
		update(np - a[np], np, {dp[i].first + 1, i});
	}

	if (dp[0].first >= N) {
		cout << -1;
	} else {
		cout << dp[0].first << '\n';
		vector<int> res;
		for (int x = 0; x != n; x = dp[x].second)
			res.push_back(x);
		reverse(res.begin(), res.end());
		for (auto v : res) cout << v << ' ';
	}
}