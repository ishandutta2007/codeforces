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

// #define int long long

const int N = 2e5 + 5, B = 450;

int n, m, x[N], y[N], last[N];
vector<pair<int, int>> seg[N];

// work x days, then maintain y days ...

int rem[B + 5][B + 5], tot[N];

vector<pair<int, int>> do_add[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1, op, k; i <= m; i++) {
		cin >> op >> k;
		if (op == 1) {
			last[k] = i;
		} else {
			seg[k].emplace_back(last[k], i - 1);
			last[k] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		if (last[i]) seg[i].emplace_back(last[i], m);
	for (int i = 1; i <= n; i++) {

		// if (1) {
		if (x[i] + y[i] >= B) {
			// brute then add
			for (auto lr : seg[i]) {
				int l = lr.first, r = lr.second;
				for (int j = l + x[i]; j <= r; j += x[i] + y[i]) {
					int k = min(r, j + y[i] - 1);
					tot[j] ++, tot[k + 1] --;
				}
			}
		} else {
			// add lazy
			for (auto lr : seg[i]) {
				int l = lr.first, r = lr.second;
				if (l + x[i] <= r) {
					do_add[l + x[i]].emplace_back(i, l + x[i]);
					do_add[r + 1].emplace_back(i, -(l + x[i]));
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		tot[i] += tot[i - 1];
		int res = tot[i];

		for (auto vp : do_add[i]) {
			int id = vp.first, v = vp.second, t = x[id] + y[id];
			for (int j = 0; j < y[id]; j++)
				rem[t][(abs(v) + j) % t] += v > 0 ? 1 : -1;
		}

		for (int j = 1; j < B; j++)
			res += rem[j][i % j];

		cout << res << '\n';
	}
}