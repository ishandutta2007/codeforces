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

const int N = 1e5 + 5;

#define int long long

inline int get(int a, int b) {
	return (a - 1) / b + 1;
}

int n, m, a[N], st[N << 2], lz[N << 2], sum[N];
vector<int> b[N];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

inline void apply(int id, int v) {
	st[id] += v, lz[id] += v;
}

inline void push(int id) {
	if (lz[id]) apply(id << 1, lz[id]), apply(id << 1 | 1, lz[id]), lz[id] = 0;
}

void update(int l, int r, int v, int id = 1, int tl = 0, int tr = N) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) return apply(id, v);
	push(id), update(l, r, v, left), update(l, r, v, right);
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, a[i], 1);
	}

	for (int i = 1, k; i <= m; i++) {
		cin >> k, b[i].resize(k);
		for (auto &v : b[i]) 
			cin >> v, sum[i] += v;

		int p = get(sum[i], b[i].size());
		update(1, p, -1);
	}
	for (int i = 1; i <= m; i++) {
		int p = get(sum[i], b[i].size());
		update(1, p, +1);
		
		for (auto v : b[i]) {
			int pp = get(sum[i] - v, b[i].size() - 1);
			update(1, pp, -1);

			cout << (st[1] < 0 ? '0' : '1');
			
			update(1, pp, +1);
		}
	
		update(1, p, -1);
	}

	for (int i = 1; i <= n; i++)
		update(1, a[i], -1);

	for (int i = 1; i <= m; i++) {
		int p = get(sum[i], b[i].size());
		update(1, p, +1), b[i].clear(), sum[i] = 0;
	}

	cout << '\n';
}