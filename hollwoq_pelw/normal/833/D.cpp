/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

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
const int N = 1e5 + 5, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return 1ll * a * b % mod; }
inline int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b&1) r = mul(r, a);
		b >>= 1; a = mul(a, a);
	}
	return r;
}
inline int inv(int a) { return binpow(a, mod - 2); }

#define color(x) (x ? pair<int, int>(-2, 1) : pair<int, int>(1, -2))
pair<int, int> operator + (const pair<int, int> &a, const pair<int, int> &b) {
	return pair<int, int> (a.first + b.first, a.second + b.second);
}

// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<
// >>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<
struct edge {
	int v, w, c;
	edge (int _v = 0, int _w = 0, int _c = 0) 
		: v(_v), w(_w), c(_c) {}
};

vector<edge> adj[N];
int n, res = 1, subsz[N];

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
	int bit[N << 2];
	vector<int> opt;
	
	inline void add(int x, int v) {
		if (v > 0) opt.push_back(x);
		for (x += N << 1; x < N << 2; x += x & -x)
			bit[x] += v;
	}
	
	inline int get(int x) {
		int r = 0;
		for (x += N << 1; x; x -= x & -x)
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
pair<int, int> cnt[N];
int prod[N], expo[N];

bool cmp(const int &i, const int &j){ return cnt[i] < cnt[j]; }

vector<int> sub, allp;

void predfs(int u, int p, int d = 1, pair<int, int> ct = {0, 0}) {
	allp.push_back(u);
	cnt[u] = ct, prod[u] = d, expo[u] = 0;
	for (auto ed : adj[u]) if (ed.v != p && !mark[ed.v])
		predfs(ed.v, u, mul(d, ed.w), ct + color(ed.c));
}

void getsub(int u, int p) {
	sub.push_back(u);
	for (auto ed : adj[u]) if (ed.v != p && !mark[ed.v])
		getsub(ed.v, u);
}

void solve(int r, int p, int coef) {
	if (coef > 0) sub = allp; else getsub(r, p);
	sort(sub.begin(), sub.end(), cmp);

	for (int i = (int) sub.size() - 1, j = 0; i >= 0; i--) {
		for (; j < sub.size() && cnt[sub[i]].first + cnt[sub[j]].first <= 0; j++) {
			bit.add(cnt[sub[j]].second, 1);
		}
		expo[sub[i]] += coef * bit.get(-cnt[sub[i]].second);
	}

	sub.clear(), bit.clear();
}

void centroid_decomp(int r) {
	int tot = find_sz(r, r);
	r = find_cen(r, r, tot);
	// begin
	predfs(r, r);

	solve(r, r, 1);
	for (auto ed : adj[r]) if (!mark[ed.v])
		solve(ed.v, r, -1);

	for (auto v : allp)
		res = mul(res, binpow(prod[v], expo[v]));
	allp.clear();
	// end
	mark[r] = 1;
	for (auto ed : adj[r]) if (!mark[ed.v])
		centroid_decomp(ed.v);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v, w, c; i < n; i++)
		cin >> u >> v >> w >> c, adj[u].emplace_back(v, w, c), adj[v].emplace_back(u, w, c);
	centroid_decomp(1);
	cout << res;
}