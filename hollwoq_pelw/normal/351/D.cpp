/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 5;

int n, q, res[N], prv[N], cur[N], dp[N];

vector<pair<int, int>> qr[N];

struct fenwick {
	int bit[N];
	inline void add(int x, int v) {
		for (; x; x -= x & -x)
			bit[x] += v;
	}
	inline int query(int x) {
		int r = 0;
		for (; x <= n; x += x & -x)
			r += bit[x];
		return r;
	}
} val, ok;

inline void update(int p, int v) {
	val.add(p, v), ok.add(dp[p], -v), ok.add(p, v);
}

inline int query(int p) {
	return val.query(p) + !ok.query(p);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x, prv[i] = cur[x], cur[x] = i;
		dp[i] = i - prv[i] == prv[i] - prv[prv[i]] ? dp[prv[i]] : prv[prv[i]];
	}
	cin >> q;
	for (int i = 1, l, r; i <= q; i++)
		cin >> l >> r, qr[r].emplace_back(l, i);
	for (int i = 1; i <= n; i++) {
		if (prv[i])
			update(prv[i], -1);
		update(i, +1);
		for (auto lid : qr[i])
			res[lid.second] = query(lid.first);
	}
	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}