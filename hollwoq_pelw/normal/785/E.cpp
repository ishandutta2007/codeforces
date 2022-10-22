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
	if (fopen("E.inp", "r")){
		freopen("E.inp", "r", stdin);
		freopen("E.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 2e5 + 5, B = 2000, NB = N / B + 5;

struct fenwick_tree {
	int bit[N];
	inline void add(int p, int v) {
		for (; p > 0; p -= p & -p)
			bit[p] += v;
	}
	inline int query(int p) {
		int r = 0;
		for (; p < N; p += p & -p)
			r += bit[p];
		return r;
	}
	inline int query(int l, int r) {
		return query(l) - query(r);
	}
} bit[NB], tot;

int n, q, a[N];

long long res;

inline long long query(int l, int r, int x, int y) {
	long long ans = 0;

	int lb = l / B, rb = r / B;
	for (; l <= r && l / B == lb; l ++)
		ans += x <= a[l] && a[l] <= y;
	for (; l <= r && r / B == rb; r --)
		ans += x <= a[r] && a[r] <= y;
	for (int i = lb + 1; i < rb; i++)
		ans += bit[i].query(x, y);

	return ans;
}

void Hollwo_Pelw(){
	cin >> n >> q;
	iota(a + 1, a + n + 1, 1);
	for (int i = 1; i <= n; i++) {
		res += tot.query(a[i]), tot.add(a[i], 1);
	}
	for (int i = 1; i <= n; i++)
		bit[i / B].add(a[i], +1);

	for (int i = 1, l, r, x, y; i <= q; i++) {
		cin >> l >> r;
		if (l > r) swap(l, r);

		x = a[l], y = a[r];
		if (l != r) {

			bit[l / B].add(x, -1);
			bit[r / B].add(y, -1);
			swap(a[l], a[r]);
			bit[l / B].add(y, +1);
			bit[r / B].add(x, +1);

			if (x < y) {
				res += 1 + 2 * query(l + 1, r - 1, x, y);
			} else {
				res -= 1 + 2 * query(l + 1, r - 1, y, x);
			}

		}

		cout << res << '\n';
	}
}