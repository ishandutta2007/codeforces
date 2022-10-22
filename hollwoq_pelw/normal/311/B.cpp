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
const long long inf = 1e18;

int n, m, p, dist[N], cost[N];

long long pcost[N], dp[N], ldp[N];

inline long long rng_cost(int l, int r) {
	return 1ll * cost[r] * (r - l + 1) - (pcost[r] - pcost[l - 1]);
}

inline bool chkmin(long long &a, long long b) {
	return a > b ? a = b, 1 : 0;
}

void solve(int l, int r, int opl, int opr) {
	if (l > r) return ;

	int m = l + r >> 1, opm = -1;

	for (int i = opl; i <= min(opr, m); i++)
		if (chkmin(dp[m], rng_cost(i, m) + ldp[i - 1])) opm = i;

	solve(l, m - 1, opl, opm);
	solve(m + 1, r, opm, opr);
}

void Hollwo_Pelw() {
	cin >> m >> n >> p;
	for (int i = 2; i <= m; i++)
		cin >> dist[i], dist[i] += dist[i - 1];

	for (int i = 1, h, t; i <= n; i++)
		cin >> h >> t, cost[i] = t - dist[h];
	
	sort(cost + 1, cost + n + 1);
	for (int i = 1; i <= n; i++)
		pcost[i] = pcost[i - 1] + cost[i];

	for (int i = 1; i <= n; i++)
		dp[i] = rng_cost(1, i);
	
	long long res = rng_cost(1, n);
	for (int i = 2; i <= p; i++) {
		for (int j = 1; j <= n; j++)
			ldp[j] = dp[j], dp[j] = inf;
		
		solve(1, n, 1, n);
		chkmin(res, dp[n]);
	}
	cout << res;
}