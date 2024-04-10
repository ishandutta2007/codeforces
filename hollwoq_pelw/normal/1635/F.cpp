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

const int N = 3e5 + 5;

int n, q, p[N], w[N], st[N], top;
long long res[N], bit[N];

vector<pair<int, int>> que[N];
vector<int> upd[N];

inline void update(int p, long long v) {
	for (; p > 0; p -= p & -p)
		bit[p] = min(bit[p], v); 
}

inline long long query(int p) {
	long long r = 4e18;
	for (; p < N; p += p & -p)
		r = min(r, bit[p]);
	return r;
}

inline long long cost(int i, int j) {
	return 1ll * abs(p[i] - p[j]) * (w[i] + w[j]);
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> w[i];
	{
		top = 0;
		for (int i = 1; i <= n; i++) {
			while (top && w[st[top]] > w[i]) 
				top --;
			if (top) 
				upd[i].push_back(st[top]);
			st[++ top] = i;
		}
	}
	{
		top = 0;
		for (int i = n; i >= 1; i--) {
			while (top && w[st[top]] > w[i]) 
				top --;
			if (top) 
				upd[st[top]].push_back(i);
			st[++ top] = i;
		}
	}

	for (int i = 1, l, r; i <= q; i++)
		cin >> l >> r, que[r].emplace_back(l, i);

	memset(bit, 0x7f, sizeof bit);

	for (int i = 1; i <= n; i++) {
		for (auto j : upd[i])
			update(j, cost(i, j));
		for (auto [l, id] : que[i])
			res[id] = query(l);
	}

	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}