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
	FAST_IO(".inp", ".out");
#endif
	int testcases = 1;
	cin >> testcases;
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

const int N = 15, inf = 2e9;

int n, a[N + 5], pos[N + 5], tot[1 << N], popcnt[1 << N];

struct __initial__ {
	__initial__ () {
		for (int i = 0; i < 1 << N; i++)
			for (int j = 0; j < n; j++)
				popcnt[i] += i >> j & 1;
	}
} __init__;

struct item {
	int val, lst, tr;
	
	void init(int s = 0) {
		val = lst = s, tr = 0;
	}
	
	item nxt(int nval, int nlst) {
		return {val + nval, nlst, 0};
	}

	void chkmin(const item &o, int ntr) {
		if (pair<int, int> (o.val, o.lst) < 
			pair<int, int> (val, lst)) *this = o, tr = ntr;
	}


} dp[N + 5][1 << N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 1 << n; i++) {
		tot[i] = 0;
		for (int j = 0; j < n; j++)
			if (i >> j & 1) tot[i] += a[j];
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 1 << n; j++)
			dp[i][j].init(inf);
	dp[0][0].init();

	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < 1 << n; mask ++) {
			dp[i + 1][mask].chkmin(dp[i][mask], mask);
			if (!(mask >> i & 1)) {
				int oth = mask ^ (1 << n) - 1;
				for (int sub = oth; sub; sub = sub - 1 & oth) if (sub >> i & 1) {
					if (dp[i][mask].lst < tot[sub]) 
						dp[i + 1][mask | sub].chkmin(dp[i][mask].nxt(popcnt[sub] - 1, tot[sub]), mask);
				}
			}
		}
	}
	vector<pair<int, int>> ans, res;
	for (int i = n, mask = (1 << n) - 1; i; mask = dp[i][mask].tr, i --) {
		if (mask != dp[i][mask].tr)
			ans.emplace_back(i - 1, dp[i][mask].tr ^ mask);
	}
	for (int i = 0; i < n; i++) pos[i] = i + 1;
	for (auto x : ans) {
		int p = x.first, mask = x.second;
		for (int i = 0; i < n; i++) {
			if ((mask >> i & 1) && i != p) {

				res.emplace_back(pos[i], pos[p]);

				for (int j = i; j < n; j++)
					pos[j] --;
			}
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) 
		cout << x.first << ' ' << x.second << '\n';
}