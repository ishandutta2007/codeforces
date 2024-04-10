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

const int N = 2e5 + 5, M = N << 1;

struct fenwick_tree {
	int bit[M], ver[M], vercnt = 0;

	inline void clear() { vercnt ++; }

	inline void add(int p, int v) {
		for (p += N; p < M; p += p & -p) {
			if (ver[p] ^ vercnt)
				ver[p] = vercnt, bit[p] = 0;
			bit[p] += v;
		}
	}

	inline int query(int p) {
		int r = 0;
		for (p += N; p > 0; p -= p & -p) {
			if (ver[p] ^ vercnt)
				ver[p] = vercnt, bit[p] = 0;
			r += bit[p];
		}
		return r;
	}

} bit[3];

void Hollwo_Pelw(){	
	int n; string s;
	long long res = 0;
	cin >> n >> s;
	
	for (int i = 0; i < 3; i++)
		bit[i].clear();

	bit[0].add(0, 1);

	for (int i = 0, c = 0; i < n; i++) {
		c += s[i] == '+' ? -1 : 1;
		res += bit[(c % 3 + 3) % 3].query(c);
		bit[(c % 3 + 3) % 3].add(c, 1);
	}

	cout << res << '\n';
}