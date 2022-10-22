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

const int N = 1e6 + 5;

int n, m, a[N], b[N], p[N];

struct fenwick_tree {
	int bit[N];
	inline void clear() {
		for (int i = 1; i <= n; i++)
			bit[i] = 0;
	}
	inline void add(int x, int v) {
		for (++ x; x <= n; x += x & -x)
			bit[x] += v;
	}
	inline int query(int x) {
		int r = 0;
		for (++ x; x; x -= x & -x)
			r += bit[x];
		return r;
	}
} bit;

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(b, b + m);

	priority_queue<int> pq;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int l = lower_bound(b, b + m, a[i]) - b;
		int r = upper_bound(b, b + m, a[i]) - b;

		pq.push(l);
		if (pq.top() > r) {
			res += pq.top() - r;
			pq.pop(), pq.push(r);
		}
	}

	iota(p, p + n, 0);
	sort(p, p + n, [](const int& x, const int& y) {
		return a[x] > a[y];
	});

	bit.clear();
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[p[i]] == a[p[j]]) j ++;
		for (int k = i; k < j; k++)
			res += bit.query(p[k]);
		for (int k = i; k < j; k++)
			bit.add(p[k], 1);
	}

	cout << res << '\n';
}