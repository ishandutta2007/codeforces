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

const int N = 1e6 + 5;

int n, m, eu[N], ev[N], par[N << 1];
vector<pair<int*, int>> opt;

inline int find(int u) { return par[u] < 0 ? u : find(par[u]); }
inline void merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return ;
	if (par[u] > par[v])
		swap(u, v);
	opt.emplace_back(par + u, par[u]);
	opt.emplace_back(par + v, par[v]);
	par[u] += par[v], par[v] = u;
}
inline bool check(int u, int v) { return find(u) == find(v); }

inline void rollback(int k) {
	for (; (int) opt.size() > k; opt.pop_back())
		*opt.back().first = opt.back().second;
}

bool solve(int l, int r) {
	if (l == r) {
		int u = eu[l], v = ev[l];
		if (check(u << 1, v << 1) || check(u << 1, v << 1 | 1)) {
			merge(u << 1, 1);
		} else {
			merge(u << 1, 1);
			merge(v << 1, 1);
		}
		return 1;
	}
	int mid = (l + r) >> 1, k = opt.size();
	{
		bool ok = 1;
		for (int i = mid + 1; i <= r; i++) {
			int u = eu[i], v = ev[i];
			merge(u << 1 | 1, v << 1);
			merge(v << 1 | 1, u << 1);
			ok &= !check(u << 1, u << 1 | 1);
		}
		if (ok && solve(l, mid)) return 1;
		rollback(k);
	}
	{
		bool ok = 1;
		for (int i = l; i <= mid; i++) {
			int u = eu[i], v = ev[i];
			merge(u << 1 | 1, v << 1);
			merge(v << 1 | 1, u << 1);
			ok &= !check(u << 1, u << 1 | 1);
		}
		if (ok && solve(mid + 1, r)) return 1;
		rollback(k);
	}
	return 0;
}

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> eu[i] >> ev[i];
	opt.clear();
	memset(par, -1, sizeof par);
	if (!solve(1, m))
		return cout << "NO\n", (void) 0;
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		if (check(i << 1, 1)) {
			cout << 1;
		} else if (check(i << 1 | 1, 1)) {
			cout << 0;
		} else {
			merge(i << 1, 1);
			cout << 1;
		}
	}
	cout << '\n';
}