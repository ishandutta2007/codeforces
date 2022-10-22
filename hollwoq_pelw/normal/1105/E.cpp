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

map<string, int> comp;
int cnt, a[N], n, m;

inline int get(string s) {
	return !comp.count(s) ? comp[s] = cnt++ : comp[s];
}

map<long long, int> dp;
long long smask[40];

int solve(long long mask) {
	if (!mask) return 0;
	if (dp.count(mask))
		return dp[mask];
	int bt = __lg(mask & -mask);
	return dp[mask] = max({
		solve(mask ^ 1ll << bt),
		1 + solve(mask & ~smask[bt])
	});
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		if (x == 2) {
			string s; 
			cin >> s;
			a[i] = get(s);
		} else {
			a[i] = -1;
		}
	}
	for (int i = 1, j; i <= n; i = j) {
		j = i + 1;
		while (j <= n && a[j] >= 0) j++;
		long long mask = 0;
		for (int k = i + 1; k < j; k++)
			mask |= 1ll << a[k];
		for (int k = i + 1; k < j; k++)
			smask[a[k]] |= mask;
	}
	cout << solve((1ll << m) - 1);
}