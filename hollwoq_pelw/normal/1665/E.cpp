#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 1e5 + 5;

int n, q, a[N];
pair<int, int> st[N << 2];

#define tm ((tl + tr) >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void update(int p, int v, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return st[id] = {v, p}, (void) 0;
	(p > tm ? update(p, v, right)
			: update(p, v, left));
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}

pair<int, int> query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return {1 << 30, -1};
	if (l <= tl && tr <= r) return st[id];
	return min(query(l, r, left), query(l, r, right));
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], update(i, a[i]);
	cin >> q;
	for (int l, r; q --; ) {
		cin >> l >> r;
		vector<int> pos(min(r - l, 30) + 1);
		for (int &i : pos)
			i = query(l, r).second, update(i, 1 << 30);
		for (int &i : pos) update(i, a[i]);

		int res = 1 << 30;

		for (int &i : pos) for (int &j : pos)
			if (i != j) res = min(res, a[i] | a[j]);

		cout << res << '\n';
	}
}