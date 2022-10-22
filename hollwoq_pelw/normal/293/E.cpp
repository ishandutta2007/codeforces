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
	FAST_IO(".inp", ".out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<
// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<
const int N = 1e5 + 5;
struct edge {
	int v, w;
	edge (int _v = 0, int _w = 0) 
		: v(_v), w(_w) {}
};

vector<edge> adj[N];
int n, L, D, subsz[N];

bool mark[N];

int find_sz(int u, int p) {
	subsz[u] = 1;
	for (auto ed : adj[u]) if (ed.v != p && !mark[ed.v])
		subsz[u] += find_sz(ed.v, u);
	return subsz[u];
}

int find_cen(int u, int p, int &tot) {
	for (auto ed : adj[u]) if (ed.v != p && !mark[ed.v])
		if (subsz[ed.v] > tot / 2) return find_cen(ed.v, u, tot);
	return u;
}
// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<
// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<

struct fenwick {
	int bit[N];
	vector<int> opt;
	
	inline void add(int x, int v) {
		if (v > 0) opt.push_back(x);
		for (; x < N; x += x & -x)
			bit[x] += v;
	}
	
	inline int get(int x) {
		int r = 0;
		for (; x; x -= x & -x)
			r += bit[x];
		return r;
	}

	inline void clear() {
		while (!opt.empty())
			add(opt.back(), -1), opt.pop_back();
	}
} bit;

// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<
// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<

vector<pair<int, int>> cur, nxt; 
long long res = 0;

void dfs(int u, int p, int d, int l) {
	if (d > D || l > L) return ;
	nxt.emplace_back(l, d), ++ res;
	for (auto ed : adj[u]) if (ed.v != p && !mark[ed.v])
		dfs(ed.v, u, d + 1, l + ed.w);
}

void do_merge() {
	sort(nxt.begin(), nxt.end());
	
	for (int i = (int) nxt.size() - 1, j = 0; i >= 0; i--) {
		for (; j < cur.size() && cur[j].first <= L - nxt[i].first; j++)
			bit.add(cur[j].second, 1);
		res += bit.get(D - nxt[i].second);
	}

	vector<pair<int, int>> tmp(nxt.size() + cur.size());
	merge(nxt.begin(), nxt.end(), cur.begin(), cur.end(), tmp.begin());
	cur = tmp, nxt.clear(), bit.clear();
}

void centroid_decomp(int r) {
	int tot = find_sz(r, r);
	r = find_cen(r, r, tot);
	// begin
	for (auto ed : adj[r]) if (!mark[ed.v])
		dfs(ed.v, r, 1, ed.w), do_merge();
	
	cur.clear();
	// end
	mark[r] = 1;
	for (auto ed : adj[r]) if (!mark[ed.v])
		centroid_decomp(ed.v);
}

void Hollwo_Pelw() {
	cin >> n >> D >> L;
	for (int i = 2, p, w; i <= n; i++)
		cin >> p >> w, adj[p].emplace_back(i, w), adj[i].emplace_back(p, w);
	centroid_decomp(1);
	cout << res;
}