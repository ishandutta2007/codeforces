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
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExcution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 5e5 + 5;

struct node_t {
	int l1, r1, l2, r2, len, ans;
	node_t(int _l1 = 0, int _r1 = 0, int _l2 = 0, int _r2 = 0, int _len = 0, int _ans = 0)
		: l1(_l1), r1(_r1), l2(_l2), r2(_r2), len(_len), ans(_ans) {}
	inline friend node_t merge(const node_t &ln, const node_t &rn) {
		return node_t(
			ln.l1 + (ln.l1 == ln.len ? rn.l1 : 0),
			rn.r1 + (rn.r1 == rn.len ? ln.r1 : 0),
			ln.r1 == ln.len ? ln.len + rn.l2 : (ln.ans == ln.len ? ln.ans + rn.l1 : ln.l2),
			rn.l1 == rn.len ? rn.len + ln.r2 : (rn.ans == rn.len ? rn.ans + ln.r1 : rn.r2),
			ln.len + rn.len,
			max({ln.ans, rn.ans, ln.r1 + rn.l2, ln.r2 + rn.l1})
		);
	}
} sta[N << 2], stb[N << 2];

#define tm ((tl + tr) >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, q, lz[N << 2];
char s[N];

inline void apply(int id) {
	swap(sta[id], stb[id]), lz[id] ^= 1;
}

inline void push(int id) {
	if (lz[id]) apply(id << 1), apply(id << 1 | 1), lz[id] = 0;
}

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		sta[id] = node_t(s[tl] == '<', s[tl] == '>', 1, 1, 1, 1);
		stb[id] = node_t(s[tl] == '>', s[tl] == '<', 1, 1, 1, 1);
	} else {
		build(left), build(right);
		sta[id] = merge(sta[id << 1], sta[id << 1 | 1]);
		stb[id] = merge(stb[id << 1], stb[id << 1 | 1]);
	}
}

void update(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) return apply(id);
	push(id), update(l, r, left), update(l, r, right);
	sta[id] = merge(sta[id << 1], sta[id << 1 | 1]);
	stb[id] = merge(stb[id << 1], stb[id << 1 | 1]);
}

node_t query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return node_t();
	if (l <= tl && tr <= r) return sta[id];
	return push(id), merge(query(l, r, left), query(l, r, right));
}

void Hollwo_Pelw(){
	cin >> n >> q >> (s + 1);
	build();

	for (int l, r; q --; ) {
		cin >> l >> r;
		update(l, r);
		cout << query(l, r).ans << '\n';
	}
}