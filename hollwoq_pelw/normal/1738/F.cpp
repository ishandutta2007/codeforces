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

const int N = 1005;

inline int query(int u) {
	cout << "? " << u << endl;
	int v; cin >> v; return v;
}

int n, d[N], par[N], vis[N];

inline int find(int u) {
	return u == par[u] ? u : par[u] =  find(par[u]);
}

inline void merge(int u, int v) {
	par[find(u)] = find(v);
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	iota(par + 1, par + n + 1, 1);
	fill(vis + 1, vis + n + 1, 0);
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	sort(p.begin(), p.end(), [&](const int &i, const int &j){
		return d[i] > d[j];
	});

	for (int u : p) if (!vis[u]) {
		vis[u] = 1;
		for (int i = 0; i < d[u]; i++) {
			int v = query(u);
			if (vis[v]) {
				merge(u, v);
				break;
			}
			merge(u, v);
			vis[v] = 1;
		}

	}
	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << find(i) << ' ';
	cout << endl;
}