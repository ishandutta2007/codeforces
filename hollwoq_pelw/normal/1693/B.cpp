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

const int N = 2e5 + 5;

#define int long long

int n, a[N], l[N], r[N];
vector<int> adj[N];

int solve(int u) {
	int res = 0;
	
	a[u] = 0;
	for (int v : adj[u]) {
		res += solve(v);
		a[u] += a[v];
	}
	if (a[u] < l[u]) {
		res ++, a[u] = r[u];
	}
	a[u] = min(a[u], r[u]);
	return res;
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 2, p; i <= n; i++)
		cin >> p, adj[p].push_back(i);
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	cout << solve(1) << '\n';
}