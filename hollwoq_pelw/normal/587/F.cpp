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
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
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

const int N = 1e5 + 5, B = 80;

int nnode, tr[N][26], endp[N], fail[N], par[N];

inline int add_st(const string &s) {
	int p = 0;
	for (char c : s) {
		if (tr[p][c - 'a'] == 0)
			par[tr[p][c - 'a'] = ++ nnode] = p;
		p = tr[p][c - 'a'];
	}
	return p;
}

inline void __build__() {
	queue<int> q;
	for (int i = 0; i < 26; i++)
		if (tr[0][i]) q.push(tr[0][i]);

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int i = 0; i < 26; i++) {
			if (int &v = tr[u][i]) {
				fail[v] = tr[fail[u]][i];
				q.push(v);
			} else {
				v = tr[fail[u]][i];
			}
		}
	}
}

vector<int> adj[N];
int tin[N], tout[N], timer = -1;

void pre_dfs(int u) {
	tin[u] = ++ timer;
	for (int v : adj[u])
		pre_dfs(v);
	tout[u] = timer;
}

int n, q, big[N], a[N], bit[N];
long long pref[N], res[N];

inline void add(int p, int v) {
	for (; p < N; p += p & -p)
		bit[p] += v;
};

inline int query(int p) {
	int r = 0;
	for (; p > 0; p -= p & -p)
		r += bit[p];
	return r;
};

vector<tuple<int, int, int>> query_big[N], query_sml[N];

void Hollwo_Pelw(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		endp[i] = add_st(s);
		big[i] = (int) s.size() > B;
	}

	__build__();

	for (int i = 1; i <= nnode; i++)
		adj[fail[i]].push_back(i);
	pre_dfs(0);

	for (int i = 1, l, r, k; i <= q; i++) {
		cin >> l >> r >> k, -- l;
		if (big[k]) {
			query_big[k].emplace_back(l, r, i);
		}
		else {
			query_sml[l].emplace_back(k, -1, i);
			query_sml[r].emplace_back(k, +1, i);
		}
	}

	for (int k = 1; k <= n; k++) if (big[k]) {
		fill(a, a + nnode + 1, 0);
		for (int p = endp[k]; p; p = par[p])
			a[tin[p]] ++;
		for (int i = 1; i <= nnode; i++)
			a[i] += a[i - 1];

		for (int i = 1; i <= n; i++)
			pref[i] = pref[i - 1] + a[tout[endp[i]]] - a[tin[endp[i]] - 1];

		for (auto [l, r, i] : query_big[k])
			res[i] = pref[r] - pref[l];
	}

	for (int i = 1; i <= n; i++) {
		add(tin[endp[i]], +1), add(tout[endp[i]] + 1, -1);

		for (auto [u, v, i] : query_sml[i])
			for (int p = endp[u]; p; p = par[p])
				res[i] += v * query(tin[p]);
	}

	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}