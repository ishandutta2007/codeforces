/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#include<bits/stdc++.h>
using namespace std;


namespace custom_hash {
	const double PI = acos(-1);

	struct chash { 
		const uint64_t C = (int_fast64_t) (2e18 * PI)+71; 
		const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count(); 

		inline int_fast64_t operator()(int x) const { return __builtin_bswap64((x ^ RANDOM) * C); }
	};

	template<class K, class V> 
	using fast_map = gp_hash_table<K, V, chash>;

	template<class K> 
	using fast_set = fast_map<K, null_type>;
}

using namespace custom_hash;

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

const int N = 1e5 + 5;

int n, mod, phi;
long long ans;

inline int mul(int a, int b){ return 1ll * a * b % mod; }
inline int add(int a, int b){ return a + b >= mod ? a + b - mod : a + b; }

inline int binpow(int a, int b){
	int r = 1; 
	while (b) {
		if (b&1) r = mul(r, a);
		b >>= 1; a = mul(a, a);
	}
	return r;
}

inline int inv(int a) { return binpow(a, phi - 1); }

int _pow10[(N << 1) + 10];

inline void __pre_calc() {
	for (int i = 0; i <= N; i++)
		_pow10[i + N] = binpow(10, i);
	for (int i = -N; i < 0; i++)
		_pow10[i + N] = inv(_pow10[N - i]);
}

inline int pow10(int p) { return _pow10[p + N]; }

inline void __calc_phi__(int tmp = mod) {
	phi = mod;
	for (int i = 2; i * i <= tmp; i ++) {
		if (tmp % i == 0) {
			phi = phi / i * (i - 1);
			while (tmp % i == 0)
				tmp /= i;
		}
	}
	if (tmp > 1)
		phi = phi / tmp * (tmp - 1);
	__pre_calc();
}

vector<pair<int, int>> adj[N];
int sz[N], dep[N], upnum[N], dwnum[N];
bool mark[N];

int find_sz(int u, int p){
	sz[u] = 1;
	for (auto vw : adj[u]) {
		int v = vw.first, w = vw.second;
		if (v != p && !mark[v])
			sz[u] += find_sz(v, u);
	}
	return sz[u];
}

int find_cen(int u, int p, int &tot){
	for (auto vw : adj[u]) {
		int v = vw.first, w = vw.second;
		if (v != p && !mark[v] && tot / 2 <= sz[v])
			return find_cen(v, u, tot);
	}
	return u;
}

void __pre_dfs(int u, int p, int d = 0){
	dep[u] = d;
	for (auto vw : adj[u]) {
		int v = vw.first, w = vw.second;
		if (v != p && !mark[v]) {
			upnum[v] = add(upnum[u], mul(pow10(d), w));
			dwnum[v] = add(mul(dwnum[u], 10), w);
			__pre_dfs(v, u, d + 1);
		}
	}
}

vector<int> allp;

void dfs(int u, int p){
	allp.push_back(u);
	for (auto vw : adj[u]) {
		int v = vw.first, w = vw.second;
		if (v != p && !mark[v])
			dfs(v, u);
	}
}

long long solve(int u, int p){
	dfs(u, p);

	fast_map<int, int> allup;

	// numup * 10 ^ depdw + numdw = 0
	// numup = - numdw * 10 ^ (-depdw)

	for (auto v : allp)
	allup[upnum[v]] ++;

	long long res = 0;
	for (auto v : allp) {
		int val = mul(add(mod, - dwnum[v]), pow10(-dep[v]));
		res += allup[val];
	}

	allp.clear();

	return res;
}

void centroid_decomp(int r) {
	int tot = find_sz(r, r);
	r = find_cen(r, r, tot);

	upnum[r] = dwnum[r] = 0;
	__pre_dfs(r, r);

	ans += solve(r, r);
	for (auto vw : adj[r]) {
		int v = vw.first, w = vw.second;
		if (!mark[v])
			ans -= solve(v, r);
	}

	mark[r] = 1;
	for (auto vw : adj[r]) {
		int v = vw.first, w = vw.second;
		if (!mark[v])
			centroid_decomp(v);
	}
}

void Hollwo_Pelw() {
	cin >> n >> mod;
	__calc_phi__();
	for (int i = 1, u, v, w; i < n; i++)
		cin >> u >> v >> w, adj[u].emplace_back(v, w % mod), adj[v].emplace_back(u, w % mod);
	centroid_decomp(0);
	cout << ans - n;
}