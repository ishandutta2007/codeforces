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

const int N = 2e5 + 5, mod = 998244353;

inline int add(int x, int y) {
	return x + y >= mod ? x + y - mod : x + y;
}

int n, x[N], y[N], a[N], pre[N];

int solve(int id) {
	int pid = lower_bound(x + 1, x + id + 1, y[id]) - x;
	long long res = x[id] - y[id];
	res += (pre[id - 1] - pre[pid - 1] + mod);
	return res % mod;
}

void Hollwo_Pelw() {
	cin >> n;
	int res = 0;
	for (int i = 1, s; i <= n; i++) {
		cin >> x[i] >> y[i] >> s;
		a[i] = solve(i);
		pre[i] = add(pre[i - 1], a[i]);
		if (s)
			res = add(res, a[i]);
	}
	cout << add(res, x[n] + 1);
}