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

const int N = 2e5 + 5;

int n, m, q, a[N];

int st1[N], top1;
int st2[N], top2;

int vis[N]; // have both larger, smaller
set<int> st;

int lst_max[N], lst_min[N];

int p3[N], p4[N], res3[N][3], res4[N][4];

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	st.insert(0);
	for (int i = 1; i <= n; i++) {
		while (top1 && a[i] < a[st1[top1]]) {
			if (++ vis[st1[top1]] == 2)
				st.insert(- st1[top1]);
			-- top1;
		}
		st1[++ top1] = i;

		while (top2 && a[i] > a[st2[top2]]) {
			if (++ vis[st2[top2]] == 2)
				st.insert(- st2[top2]);
			-- top2;
		}
		st2[++ top2] = i;

		int pos_min = *prev(lower_bound(st1 + 1, st1 + top1 + 1, i,
				[](const int& x, const int& y) { return a[x] < a[y]; }));
		int pos_max = *prev(lower_bound(st2 + 1, st2 + top2 + 1, i,
				[](const int& x, const int& y) { return a[x] > a[y]; }));
		
		// cout << pos_max << ' ' << pos_min << '\n';

		if (lst_max[pos_min] >= lst_min[pos_max]) {
			res3[i][0] = p3[i] = lst_max[pos_min];
			res3[i][1] = pos_min,  res3[i][2] = i;
		} else {
			res3[i][0] = p3[i] = lst_min[pos_max];
			res3[i][1] = pos_max,  res3[i][2] = i;
		}

		res4[i][0] = p4[i] = - *st.lower_bound(- min(pos_min, pos_max));
		int val1 = *lower_bound(st1 + 1, st1 + top1 + 1, p4[i]);
		int val2 = *lower_bound(st2 + 1, st2 + top2 + 1, p4[i]);

		// cout << p4[i] << ' ' << val1 << ' ' << val2 << '\n';

		res4[i][1] = min(val1, val2), res4[i][2] = max(val1, val2), res4[i][3] = i;

		lst_max[i] = pos_max, lst_min[i] = pos_min;
	}

	for (int i = 1; i <= n; i++) {
		if (p3[i] < p3[i - 1]) {
			p3[i] = p3[i - 1];
			for (int j = 0; j < 3; j++)
				res3[i][j] = res3[i - 1][j];
		}
		if (p4[i] < p4[i - 1]) {
			p4[i] = p4[i - 1];
			for (int j = 0; j < 4; j++)
				res4[i][j] = res4[i - 1][j];
		}
	}

	for (int l, r; q --; ) {
		cin >> l >> r;
		if (p4[r] >= l) {
			cout << "4\n";
			for (int i = 0; i < 4; i++)
				cout << res4[r][i] << " \n"[i == 3];
			continue ;
		}
		if (p3[r] >= l) {
			cout << "3\n";
			for (int i = 0; i < 3; i++)
				cout << res3[r][i] << " \n"[i == 2];
			continue ;
		}
		cout << "0\n\n";
	}
}