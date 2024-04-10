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
	FAST_IO("19D.inp", "19D.out");
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

int q, resx, resy;

char t[10];
struct query {
	int tp, x, y;
} qry[N];

set<int> st_y[N];
int n, st[N << 2], list_num[N];

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void update(int p, int id = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr)
		return st[id] = st_y[p].empty() ? 0 : *st_y[p].rbegin(), (void) 0;
	int tm = tl + tr >> 1;
	(p > tm ? update(p, right)
			: update(p, left));
	st[id] = max(st[id << 1], st[id << 1 | 1]);
}

void query(int v, int l, int r = n - 1, int id = 1, int tl = 0, int tr = n - 1) {
	if (l > tr || tl > r || resx != -1) return ;
	if (l <= tl && tr <= r) {
		if (st[id] <= v) return ;
		while (tl != tr) {
			int tm = tl + tr >> 1;
			if (st[id << 1] > v) {
				tr = tm, id = id << 1;
			} else {
				tl = tm + 1, id = id << 1 | 1;
			}
		}
		resx = tl, resy = *st_y[tl].upper_bound(v);
	}
	int tm = tl + tr >> 1;
	if (resx == -1) query(v, l, r, left);
	if (resx == -1) query(v, l, r, right);
}

void Hollwo_Pelw() {
	cin >> q;
	for (int x, y, i = 0; i < q; i++) {
		cin >> t >> x >> y;
		if (t[0] == 'f')
			qry[i] = {0, x, y};
		else
			qry[i] = {t[0] == 'a' ? 1 : 2, x, y};
	}

	for (int i = 0; i < q; i++)
		list_num[i] = qry[i].x;

	sort(list_num, list_num + q);
	n = unique(list_num, list_num + q) - list_num;

	for (int i = 0, tp, x, y; i < q; i++) {
		tp = qry[i].tp, y = qry[i].y;
		x = lower_bound(list_num, list_num + n, qry[i].x) - list_num;

		if (tp == 0) {
			resx = resy = -1, query(y, ++ x);
			if (resx == -1)
				cout << "-1\n";
			else
				cout << list_num[resx] << ' ' << resy << '\n';
		} else {
			if (tp == 1) {
				st_y[x].insert(y), update(x);	
			} else {
				st_y[x].erase(y),  update(x);
			}
		}
	}
}