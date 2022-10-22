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
	if (fopen("A.inp", "r"))
		assert(freopen("A.inp", "r", stdin)), assert(freopen("A.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 3e5 + 5, BASE = 431;
const uint64_t mod = 141862177280553647LL;

int n, a[N], b[N], h[N];
int tin[N], tout[N], siz[N], timer;

vector<int> adj[N];

uint64_t hsh[N], power[N];

char s[N];

void pre_dfs(int u, int p) {
	tin[u] = ++ timer;
	siz[u] = 1;

	hsh[u] = (hsh[p] + (uint64_t) (s[u]) * power[h[u]]) % mod;

	for (int v : adj[u]) if (v != p) {
		h[v] = h[u] + 1;
		pre_dfs(v, u);
		siz[u] += siz[v];
	}

	tout[u] = timer;
}

int cnt[N], cnt0;

inline void add(int p, int v) {
	cnt0 -= cnt[p] != 0;
	cnt[p] += v;
	cnt0 += cnt[p] != 0;
}

void dfs_solve(int u, int p, bool keep = 0) {
	int big = -1, big_siz = 0;
	for (int v : adj[u]) if (v != p)
		if (big_siz < siz[v])
			big = v, big_siz = siz[v];
	
	for (int v : adj[u]) if (v != p)
		if (v != big)
			dfs_solve(v, u);

	if (big != -1)
		dfs_solve(big, u, 1);

	add(b[tin[u]], 1);

	for (int v : adj[u]) if (v != p)
		if (v != big) {
			for (int i = tin[v]; i <= tout[v]; i++)
				add(b[i], 1);
		}

	a[u] += cnt0;
	if (!keep) {
		for (int i = tin[u]; i <= tout[u]; i++)
			add(b[i], -1);
	}
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> s[i];

	power[0] = 1;
	for (int i = 1; i <= n; i++)
		power[i] = 1ll * power[i - 1] * BASE % mod;

	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	pre_dfs(1, 0);

	{
		vector<uint64_t> val(hsh + 1, hsh + n + 1);
		sort(val.begin(), val.end());
		val.erase(unique(val.begin(), val.end()), val.end());

		for (int i = 1; i <= n; i++)
			b[tin[i]] = lower_bound(val.begin(), val.end(), hsh[i]) - val.begin();
	}

	dfs_solve(1, 0);

	int res = *max_element(a + 1, a + n + 1);
	cout << res << '\n';
	cout << count(a + 1, a + n + 1, res);
}