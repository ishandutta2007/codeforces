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

const int N = 1e5 + 5;

vector<int64_t> bad;
int n, q;

// segment tree 
// -> dis : distance to next bad number
// -> val : value of all nums in range (if same)
// -> add : lazy value add to range

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

inline int64_t get_dis(int64_t x) {
	return *lower_bound(bad.begin(), bad.end(), x) - x;
}

int64_t dis[N << 2], val[N << 2], add[N << 2];

inline void push(int id) {
	if (~val[id]) {
		val[id << 1] = val[id << 1 | 1] = val[id];
		dis[id << 1] = dis[id << 1 | 1] = dis[id];
		add[id << 1] = add[id << 1 | 1] = 0, val[id] = -1;
	} else if (add[id]) {
		if (~val[id << 1]) 
			val[id << 1] += add[id];
		else
			add[id << 1] += add[id];
		if (~val[id << 1 | 1]) 
			val[id << 1 | 1] += add[id];
		else
			add[id << 1 | 1] += add[id];
		dis[id << 1] -= add[id], dis[id << 1 | 1] -= add[id];
		add[id] = 0;
	}
}

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		cin >> val[id];
		dis[id] = get_dis(val[id]);
	} else {
		build(left), build(right);
		dis[id] = min(dis[id << 1], dis[id << 1 | 1]);
		val[id] = val[id << 1] == val[id << 1 | 1] ? val[id << 1] : -1;
	}
}

void update_set(int l, int r, int x, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) {
		dis[id] = get_dis(x);
		val[id] = x, add[id] = 0;
		return ;
	}
	push(id);
	update_set(l, r, x, left), update_set(l, r, x, right);
	dis[id] = min(dis[id << 1], dis[id << 1 | 1]);
	val[id] = val[id << 1] == val[id << 1 | 1] ? val[id << 1] : -1;
}

void update_add(int l, int r, int x, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r && (~val[id] || dis[id] >= x)) {
		if (~val[id]) {
			val[id] += x;
			dis[id] = get_dis(val[id]);
		}
		else {
			add[id] += x;
			dis[id] -= x;
		}
		assert(dis[id] >= 0);
		return ;
	}
	push(id);
	update_add(l, r, x, left), update_add(l, r, x, right);
	dis[id] = min(dis[id << 1], dis[id << 1 | 1]);
	val[id] = val[id << 1] == val[id << 1 | 1] ? val[id << 1] : -1;
}

int64_t query_dis(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return 1e18;
	if (l <= tl && tr <= r) return dis[id];
	return push(id), min(query_dis(l, r, left), query_dis(l, r, right));
}

void query_print(int p, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		cout << val[id] << '\n';
	} else {
		push(id);
		(p > tm ? query_print(p, right)
				: query_print(p, left));
	}
}

void Hollwo_Pelw() {
	bad.push_back(1ll);
	for (int i = 0; i < 11; i++)
		bad.push_back(42ll * bad.back());
	cin >> n >> q, build();
	for (int t, l, r, x; q --; ) {
		cin >> t;
		if (t == 1) {
			cin >> x, query_print(x);
		} else {
			cin >> l >> r >> x;
			if (t == 2) {
				update_set(l, r, x);
			} else {
				update_add(l, r, x);
				while (query_dis(l, r) == 0)
					update_add(l, r, x);
			}
		}
	}
}