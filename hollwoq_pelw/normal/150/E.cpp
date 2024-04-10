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
const int N = 1e5 + 5, inf = 1e9;
struct edge {
	int v, w;
	edge (int _v = 0, int _w = 0)
		: v(_v), w(_w) {}
} stk[N];

vector<edge> adj[N];
int n, m, L, R, tot, subsz[N], list_num[N];

int res, bi, bj, top;

bool cmp(const edge &a, const edge &b) {
	return subsz[a.v] < subsz[b.v];
}

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

int cur[N], cpos[N], pre[N], ppos[N], cursz, presz;

void dfs(int u, int p, int d, int s, const int &mid) {
	if (cur[d] < s) cur[d] = s, cpos[d] = u;
	cursz = max(cursz, d);
	for (auto ed : adj[u]) if (ed.v != p && !mark[ed.v])
		dfs(ed.v, u, d + 1, s + (ed.w < mid ? -1 : 1), mid);
} 

bool solve(int rt, const int &mid) {
	static int dq[N];
	ppos[presz = 0] = rt;

	for (int _ = 0; _ < top; _++) {
		int v = stk[_].v, w = stk[_].w;
		fill(cur + 1, cur + subsz[v] + 1, -inf);

		cursz = 0;
		dfs(v, rt, 1, w < mid ? -1 : 1, mid);

		for (int i = 1, qh = 1, qt = 0, l = presz, r = presz + 1; i <= cursz; i++) {
			while (r > 0 && r + i > L) {
				-- r;
				while (qh <= qt && pre[dq[qt]] < pre[r]) -- qt;
				dq[++ qt] = r;
			}
			while (l >= 0 && l + i > R) {
				-- l;
				while (qh <= qt && dq[qh] > l) ++ qh;
			}
			if (qh <= qt && pre[dq[qh]] + cur[i] >= 0)
				return bi = ppos[dq[qh]], bj = cpos[i], 1;
		}

		while (presz < cursz) pre[++ presz] = -inf;
		for (int i = 1; i <= cursz; i++)
			if (pre[i] < cur[i]) pre[i] = cur[i], ppos[i] = cpos[i];
	}
	return 0;
}

void centroid_decomp(int r) {
	tot = find_sz(r, r), top = 0;
	r = find_cen(r, r, tot);
	// begin
	for (auto ed : adj[r]) if (!mark[ed.v])
		stk[top ++] = ed, subsz[ed.v] = subsz[ed.v] > subsz[r] ? tot - subsz[r] : subsz[ed.v];
	sort(stk, stk + top, cmp);

	// binary search
	int tl = res + 1, tr = m;
	while (tl <= tr) {
		int tm = tl + tr >> 1;
		(solve(r, list_num[tm]) ? 
			res = tm, tl = tm + 1 : tr = tm - 1);
	}

	// end
	mark[r] = 1;
	for (auto ed : adj[r]) if (!mark[ed.v])
		centroid_decomp(ed.v);
}

void Hollwo_Pelw() {
	// read input
	cin >> n >> L >> R;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w, list_num[i] = w, 
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}
	// get list of all possible ans
	sort(list_num + 1, list_num + n);
	m = unique(list_num + 1, list_num + n) - list_num - 1;
	// centroid decompose
	centroid_decomp(1);
	cout << bi << ' ' << bj << '\n';
}