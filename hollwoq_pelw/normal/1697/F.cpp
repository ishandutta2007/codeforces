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
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 4e5 + 5;

namespace two_sat {
 
vector<int> g0[N << 1], g1[N << 1], ord;
int n, res[N], vis[N << 1];

void __init__(int _n) {
	n = _n;
	for (int i = 0; i < n << 1; i++)
		g0[i].clear(), g1[i].clear();
	ord.clear();
}

 
inline void add_clause(int i, bool f, int j, bool g) {
	// if (res[i] = f) then (res[j] = g)
	g0[i << 1 | f].push_back(j << 1 | g);
	g1[j << 1 | g].push_back(i << 1 | f);
}
 
void dfs0(int u) {
	vis[u] = 1;
	for (int v : g0[u])
		if (!vis[v]) dfs0(v);
	ord.push_back(u);
}
 
void dfs1(int u, int c) {
	vis[u] = c;
	for (int v : g1[u])
		if (!vis[v]) dfs1(v, c);
}
 
bool is_satisfied() {
	fill(vis, vis + (n << 1), 0);
	for (int i = 0; i < n << 1; i++)
		if (!vis[i]) dfs0(i);
	fill(vis, vis + (n << 1), 0);
	int cnt = 0;
	reverse(ord.begin(), ord.end());
	for (int u : ord)
		if (!vis[u]) dfs1(u, ++ cnt);
	for (int i = 0; i < n; i++) {
		if (vis[i << 1] == vis[i << 1 | 1])
			return 0;
		res[i] = vis[i << 1] < vis[i << 1 | 1];
	}
	return 1;
}
 
} // namespace two_sat

int n, m, k;

void Hollwo_Pelw(){
	cin >> n >> m >> k;
	two_sat::__init__(n * (k + 1));

	auto f = [&](int i, int j) {
		return i * (k + 1) + j;
	};

	for (int t, i, j, x; m --; ) {
		cin >> t;
		if (t == 1) {
			cin >> i >> x, -- i;
			// a[i] <= x -> a[i] <= x - 1
			two_sat::add_clause(f(i, x), 1, f(i, x - 1), 1);
			// a[i] >= x -> a[i] >= x + 1
			two_sat::add_clause(f(i, x - 1), 0, f(i, x), 0);
		} else {
			cin >> i >> j >> x, -- i, -- j;
			if (t == 2) {
				// a[i] >= y -> a[j] <= x - y
				for (int y = 1; y <= k; y++)
					if (0 <= x - y && x - y <= k) {
						two_sat::add_clause(f(i, y - 1), 0, f(j, x - y), 1);
						two_sat::add_clause(f(j, y - 1), 0, f(i, x - y), 1);
					}
				// a[i] >= x (never)
				if (x - 1 <= k) {
					two_sat::add_clause(f(i, x - 1), 0, f(i, x - 1), 1);
					two_sat::add_clause(f(j, x - 1), 0, f(j, x - 1), 1);
				}
			} else {
				// a[i] <= y -> a[j] >= x - y
				for (int y = 0; y <= k; y++)
					if (0 < x - y && x - y - 1 <= k) {
						two_sat::add_clause(f(i, y), 1, f(j, x - y - 1), 0);
						two_sat::add_clause(f(j, y), 1, f(i, x - y - 1), 0);
					}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		// a[i] <= 0 (never)
		two_sat::add_clause(f(i, 0), 1, f(i, 0), 0);
		// a[i] >  k (never)
		two_sat::add_clause(f(i, k), 0, f(i, k), 1);

		for (int j = 0; j <= k; j++) {
			if (j < k) {
				// a[i] <= j -> a[i] <= j + 1
				two_sat::add_clause(f(i, j), 1, f(i, j + 1), 1);
				// a[i] >= j + 1 -> a[i] >= j
				two_sat::add_clause(f(i, j + 1), 0, f(i, j), 0);
			}
			if (i < n) {
				// a[i] >= j -> a[i + 1] >= j
				two_sat::add_clause(f(i, j), 0, f(i + 1, j), 0);
				// a[i + 1] <= j -> a[i] <= j
				two_sat::add_clause(f(i + 1, j), 1, f(i, j), 1);
			}
		}
	}

	if (!two_sat::is_satisfied()) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= k; j++) {
				if (two_sat::res[f(i, j)]) {
					cout << j << " \n"[i == n - 1];
					break;
				}
			}
		}
	}
}