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

// (n - r - b) * (r - b)
// = (b - r) * (b + r - n)
// = b ^ 2 - b * n + (r * n - r ^ 2)
// min (b * (b - n)) = - max(b * (n - b)) <=> b ~= n / 2

#define int long long

const int N = 2e5 + 5, inf = 2e9;

vector<int> adj[N];
int n, k, h[N], cnt[N];

int pre[N], val[N];

inline int solve(int r, int limb) {
	return val[r] - pre[limb];
}

void pre_dfs(int u, int p) {
	h[u] = 0;
	for (auto v : adj[u]) if (v != p) {
		pre_dfs(v, u);
		h[u] = max(h[u], h[v]);
	}
	++ h[u];
	cnt[h[u]] ++;
}

inline int f(int r, int b) {
	return (n - r - b) * (r - b);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		val[i] = i * (n - i);
		pre[i] = max(pre[i - 1], val[i]);
	}

	pre_dfs(1, 0);

	int notb = 0, cntr = 0, maxdep = 0;

	while (cnt[maxdep + 1]) ++ maxdep;

	while (maxdep > 0 && cntr < k) {
		++ cntr;
		for (int i = 1; i <= maxdep; i++)
			-- cnt[i];
		notb += maxdep;
		while (!cnt[maxdep]) maxdep --;
	}

	int cntb = n - notb;

	int res = f(cntr, cntb);

	if (cntb) {
		for (int i = 0; i <= cntb; i++)
			res = min(res, f(cntr, i));
	} else {
		for (int i = cntr; i <= k; i++)
			res = max(res, f(i, cntb));
	}

	cout << res << '\n';
}