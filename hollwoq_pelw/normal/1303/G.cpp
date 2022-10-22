/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

#define ll long long

bool Q;
struct line {
	mutable ll k, m, p;
	bool operator < (const line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		Q = 1; auto l = *lower_bound({0, 0, x}); Q = 0;
		return l.k * x + l.m;
	}
};

#undef ll

const int N = 15e4 + 5;

long long ans;
int n, a[N];
vector<int> adj[N];

int sz[N], dep[N];
bool mark[N];

int _dfs_sz(int u, int p) {
	sz[u] = 1;
	for (auto v : adj[u]) if (!mark[v] && v != p)
		sz[u] += _dfs_sz(v, u);
	return sz[u];
}

int find_cen(int u, int p, int tot){
	for (auto v : adj[u]) if (!mark[v] && v != p)
		if (sz[v] > tot / 2) return find_cen(v, u, tot);
	return u;
}

long long pref[N]; // root -> v : a[x1] + a[x2] + .. + a[xn]
long long prefup[N]; // root -> v : a[x1] * n + a[x2] * (n - 1) + .. + a[x1] * 1
long long prefdw[N]; // root -> v : a[x1] * 1 + a[x2] * 2 + ... 

// path u -> v : prefup[u] + dep[u] * (pref[v] - a[r]) + prefdw[v] - a[r];

void calc_pref(int u, int p, int d = 0){
	pref[u] = (u == p ? a[u] : pref[p] + a[u]);
	dep[u] = d;
	for (auto v : adj[u]) if (!mark[v] && v != p)
		calc_pref(v, u, d + 1);
}

void calc_prefup(int u, int p){
	prefup[u] = (u == p ? a[u] : prefup[p] + pref[u]);
	ans = max(prefup[u], ans); // if path have end is root
	for (auto v : adj[u]) if (!mark[v] && v != p)
		calc_prefup(v, u);
}

void calc_prefdw(int u, int p){
	prefdw[u] = (u == p ? a[u] : prefdw[p] + 1ll * a[u] * (dep[u] + 1));
	ans = max(prefdw[u], ans); // if path have end is root
	for (auto v : adj[u]) if (!mark[v] && v != p)
		calc_prefdw(v, u);
}

void query_sub(int u, int p, int r, LineContainer &cht){
	if (cht.empty()) return ;
	ans = max(cht.query(pref[u] - a[r]) + prefdw[u] - a[r], ans);
	for (auto v : adj[u]) if (!mark[v] && v != p)
		query_sub(v, u, r, cht);
}

void add_sub(int u, int p, LineContainer &cht){
	cht.add(dep[u], prefup[u]);
	for (auto v : adj[u]) if (!mark[v] && v != p)
		add_sub(v, u, cht);
}

void centroid_decomp(int r){
	int tot = _dfs_sz(r, r);
	r = find_cen(r, r, tot);

	calc_pref(r, r);
	calc_prefup(r, r);
	calc_prefdw(r, r);

	LineContainer cht;
	for (auto v : adj[r])
		if (!mark[v]) {
			query_sub(v, r, r, cht);
			add_sub(v, r, cht);
		}

	reverse(adj[r].begin(), adj[r].end());

	cht.clear();
	for (auto v : adj[r])
		if (!mark[v]) {
			query_sub(v, r, r, cht);
			add_sub(v, r, cht);
		}

	mark[r] = 1;
	for (auto v : adj[r]) 
		if (!mark[v]) centroid_decomp(v);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	for (int i = 1; i <= n; i++) 
		cin >> a[i], ans = max(ans, (long long) a[i]);
	centroid_decomp(1);
	cout << ans;
}