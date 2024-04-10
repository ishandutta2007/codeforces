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

const int N = 505, M = 6e5 + 5;

struct query_t {
	int sx, sy, ex, ey, ans;
} qq[M];

int n, m, q;
char s[N][N];

bitset<N> dpL[N][N], dpR[N][N];

void solve(int l, int r, const vector<int> &id) {
	if (id.empty() || l > r) return ;

	int mid = l + r >> 1;
	vector<int> lid, rid;

	// cout << "SOLVE " << mid << '\n';

	for (int i = mid; i >= l; i--) for (int j = m; j >= 1; j--) {
		dpL[i][j].reset();
		if (s[i][j] == '.') {
			if (j < m)
				dpL[i][j] = dpL[i][j + 1];
			if (i < mid)
				dpL[i][j] |= dpL[i + 1][j];
			else
				dpL[i][j].set(j);
		}
	}

	for (int i = mid; i <= r; i++) for (int j = 1; j <= m; j++) {
		dpR[i][j].reset();
		if (s[i][j] == '.') {
			if (j > 1)
				dpR[i][j] = dpR[i][j - 1];
			if (i > mid)
				dpR[i][j] |= dpR[i - 1][j];
			else
				dpR[i][j].set(j);
		}
	}

	for (int i : id) {
		if (qq[i].ex < mid) {lid.push_back(i); continue ;}
		if (qq[i].sx > mid) {rid.push_back(i); continue ;}

		// cout << "get = " << i << '\n';
		// for (int v = 1; v <= m; v++)
		// 	cout << dpL[qq[i].sx][qq[i].sy][v]; cout << '\n';
		// for (int v = 1; v <= m; v++)
		// 	cout << dpR[qq[i].ex][qq[i].ey][v]; cout << '\n';

		qq[i].ans = (dpL[qq[i].sx][qq[i].sy] & dpR[qq[i].ex][qq[i].ey]).count();
	}

	solve(l, mid - 1, lid);
	solve(mid + 1, r, rid);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> s[i][j];

	cin >> q;
	for (int i = 1, sx, sy, ex, ey; i <= q; i++) {
		cin >> sx >> sy >> ex >> ey;
		qq[i] = {sx, sy, ex, ey, 0};
	}

	vector<int> id(q);
	iota(id.begin(), id.end(), 1);

	solve(1, n, id);

	for (int i = 1; i <= q; i++) {
		cout << (qq[i].ans ? "Yes\n" : "No\n");
	}
}