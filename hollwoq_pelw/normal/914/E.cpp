/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

const int N = 2e5 + 5;

int n, a[N], sz[N];
vector<int> adj[N];
bitset<N> mark;
char s[N];

int find_sz(int u, int p) {
	sz[u] = 1;
	for (auto v : adj[u]) if (v != p && !mark[v])
		sz[u] += find_sz(v, u);
	return sz[u];
}

int find_cen(int u, int p, int tot) {
	for (auto v : adj[u]) if (v != p && !mark[v])
		if (sz[v] > tot / 2) return find_cen(v, u, tot);
	return u;
}

long long ans[N];
int cnt[1 << 20];

void add_sub(int u, int p, int x, int d) {
	cnt[(d ^= a[u])] += x;
	for (auto v : adj[u]) if (v != p && !mark[v])
		add_sub(v, u, x, d);
}

long long query_sub(int u, int p, int d) {
	long long res = cnt[(d ^= a[u])];
	for (int i = 0; i < 20; i++)
		res += cnt[d ^ 1 << i];
	for (auto v : adj[u]) if (v != p && !mark[v])
		res += query_sub(v, u, d);
	return ans[u] += res, res;
}

void centroid_decomp(int r) {
	int tot = find_sz(r, r);
	r = find_cen(r, r, tot);

	add_sub(r, r, 1, 0);
	
	long long res = cnt[0];
	for (int i = 0; i < 20; i++)
		res += cnt[1 << i];

	for (auto v : adj[r]) if (!mark[v])
		add_sub(v, r, -1, a[r]), res += query_sub(v, r, 0), add_sub(v, r, 1, a[r]);

	add_sub(r, r, -1, 0);
	ans[r] += res / 2 + 1;

	mark[r] = 1;
	for (auto v : adj[r]) if (!mark[v])
		centroid_decomp(v);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	cin >> s + 1;
	for (int i = 1; i <= n; i++)
		a[i] = 1 << s[i] - 'a';
	centroid_decomp(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}