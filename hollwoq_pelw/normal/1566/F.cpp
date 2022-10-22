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
	cin >> testcases;
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

#define int long long
const int N = 2e5 + 5, inf = 1e18;

inline void smin(int &a, int b) {
	a = a > b ? b : a;
}

int n, m, a[N], cost[N][4], dp[N][2]; // 0 -> remain, 1 -> moved
vector<pair<int, int>> b[N];

// 0 => x1 x1
// 1 => x2 x1
// 2 => x1 x2
// 3 => x2 x2

void solve(int id, int l, int r) {
	sort(b[id].begin(), b[id].end());
	vector<pair<int, int>> tmp;
	for (int i = 0, j = 0; i < b[id].size(); i = j) {
		while (j < b[id].size() && b[id][j].first == b[id][i].first) j++;
		// i -> j - 1
		tmp.push_back(b[id][i]);
	}
	vector<int> valr(tmp.size() + 1);
	valr[tmp.size()] = 0;
	for (int i = (int) tmp.size() - 1; i >= 0; i--)
		valr[i] = max(valr[i + 1], r - tmp[i].second);
	tmp.insert(tmp.begin(), {l, r});


	for (int i = 0; i < 4; i++) cost[id][i] = inf;

	for (int i = 0; i < tmp.size(); i++) {
		int vl = tmp[i].first - l, vr = valr[i];
		if (vl > 1e10 || vr > 1e10) continue ;
		smin(cost[id][0], vl + vr);
		smin(cost[id][1], vl * 2 + vr);
		smin(cost[id][2], vl + vr * 2);
		smin(cost[id][3], vl * 2 + vr * 2);
	}
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n + 1; i++)
		b[i].clear();
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	a[0] = -inf, a[n + 1] = inf;
	for (int i = 1, l, r; i <= m; i++) {
		cin >> l >> r;
		int v = lower_bound(a, a + n + 1, l) - a;
		if (a[v] > r) b[v].emplace_back(l, r);
	}
	++ n;
	for (int i = 1; i <= n; i++) {
		solve(i, a[i - 1], a[i]);
	}
	for (int i = 1; i <= n; i++)
		dp[i][0] = dp[i][1] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		smin(dp[i][0], dp[i - 1][0] + cost[i][2]);
		smin(dp[i][0], dp[i - 1][1] + cost[i][3]);
		smin(dp[i][1], dp[i - 1][0] + cost[i][0]);
		smin(dp[i][1], dp[i - 1][1] + cost[i][1]);
	}
	cout << min(dp[n][0], dp[n][1]) << '\n';
}