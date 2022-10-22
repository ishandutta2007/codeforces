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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 5, mod = 998244353;

int n, k, dp[N][2]; // 0 -> 2 ends equal, 1 -> not equal

inline int get(int l, int r, int c) {
	if (!l || !r) {
		if (!c) return 1;
		int res = !l && !r ? k : k - 1;
		while (-- c) res = 1ll * res * (k - 1) % mod;
		return res;
	}
	return dp[c][l != r];
}

int solve(const vector<int> &v) {
	int res = 1, lst = 0, c = 0;
	for (auto x : v) {
		if (~x) res = 1ll * res * get(lst, x, c) % mod, lst = x, c = 0; else ++ c;
	}
	return res;
}

vector<int> v[2];

void Hollwo_Pelw() {
	cin >> n >> k;
	dp[0][0] = 0, dp[0][1] = 1;
	for (int i = 1; i < N; i++) {
		dp[i][0] = 1ll * (k - 1) * dp[i - 1][1] % mod;
		dp[i][1] = (1ll * (k - 2) * dp[i - 1][1] + dp[i - 1][0]) % mod;
	}
	for (int i = 0, x; i < n; i++)
		cin >> x, v[i & 1].push_back(x);
	v[0].push_back(0), v[1].push_back(0);
	cout << 1ll * solve(v[0]) * solve(v[1]) % mod;
}