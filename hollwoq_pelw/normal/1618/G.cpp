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

const int N = 4e5 + 5;

#define int long long

multiset<int> st[N], nt[N];

vector<pair<int, int>> a, edges, query;
int n, m, q, tot, par[N], res[N];


inline int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

inline void merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return ;
	if (st[u].size() + nt[u].size() < st[v].size() + nt[v].size())
		swap(u, v);

	par[v] = u;

	for (auto x : st[v]) st[u].insert(x);
	for (auto x : nt[v]) nt[u].insert(x);

	while (nt[u].size() && st[u].size()) {
		int x = * st[u].begin(), y = * nt[u].rbegin();
		if (x >= y) break ;

		tot += y - x;
		nt[u].erase(--nt[u].end());
		st[u].erase(st[u].begin());
		
		nt[u].insert(x);
		st[u].insert(y);
	}
}

void Hollwo_Pelw() {
	cin >> n >> m >> q;
	for (int i = 0, x; i < n; i++) 
		cin >> x, a.emplace_back(x, 0);
	for (int i = 0, x; i < m; i++)
		cin >> x, a.emplace_back(x, 1);
	sort(a.begin(), a.end());
	
	iota(par, par + n + m, 0);
	for (int i = 0; i < n + m; i++) {
		if (a[i].second) {
			nt[i].insert(a[i].first);
		}
		else {
			tot += a[i].first;
			st[i].insert(a[i].first);
		}
	}
	for (int i = 1; i < n + m; i++)
		edges.emplace_back(a[i].first - a[i - 1].first, i);
	sort(edges.begin(), edges.end());

	query.resize(q);
	for (int i = 0; i < q; i++) 
		cin >> query[i].first, query[i].second = i;
	sort(query.begin(), query.end());

	int p = 0;
	for (auto [val, id] : query) {
		while (p < edges.size() && edges[p].first <= val)
			merge(edges[p].second - 1, edges[p].second), p ++;
		res[id] = tot;
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << '\n';
}