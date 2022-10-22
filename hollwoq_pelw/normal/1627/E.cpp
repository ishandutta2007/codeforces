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

const int N = 1e5 + 5;

int n, m, k, x[N];
struct ladder {
	int a, b, c, d, h;
} lad[N];
long long dp[N];

vector<int> up[N], dw[N];

void Hollwo_Pelw() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> x[i], up[i].clear(), dw[i].clear();

	for (int i = 1, a, b, c, d, h; i <= k; i++) {
		cin >> a >> b >> c >> d >> h;
		lad[i] = {a, b, c, d, h};
		up[a].push_back(i);
		dw[c].push_back(i);
		dp[i] = 1e18;
	}
	
	vector<long long> st;
	for (int i = 1, p = 0; i <= n; i++) {
		sort(up[i].begin(), up[i].end(), [](const int &x, const int &y){
			return lad[x].b < lad[y].b;
		});
		sort(dw[i].begin(), dw[i].end(), [](const int &x, const int &y){
			return lad[x].d < lad[y].d;
		});

		st.clear(), p = 0;
		if (i == 1) 
			st.push_back(- x[i]);

		for (auto id : up[i]) {
			for (; p < dw[i].size() && lad[dw[i][p]].d <= lad[id].b; p ++) {
				long long val = dp[dw[i][p]] - 1ll * lad[dw[i][p]].d * x[i];
				while (!st.empty() && st.back() >= val)
					st.pop_back();
				st.push_back(val);
			}
			if (!st.empty())
				dp[id] = min(dp[id], st[0] + 1ll * lad[id].b * x[i] - lad[id].h);
		}

		reverse(up[i].begin(), up[i].end());
		reverse(dw[i].begin(), dw[i].end());
		st.clear(), p = 0;

		for (auto id : up[i]) {
			for (; p < dw[i].size() && lad[dw[i][p]].d >= lad[id].b; p ++) {
				long long val = dp[dw[i][p]] + 1ll * lad[dw[i][p]].d * x[i];
				while (!st.empty() && st.back() >= val)
					st.pop_back();
				st.push_back(val);
			}
			if (!st.empty())
				dp[id] = min(dp[id], st[0] - 1ll * lad[id].b * x[i] - lad[id].h);
		}
	}

	long long res = 1e18;

	for (auto id : dw[n])
		res = min(res, dp[id] + 1ll * x[n] * (m - lad[id].d));

	if (res > 1e17)
		cout << "NO ESCAPE\n";
	else
		cout << res << '\n';
}