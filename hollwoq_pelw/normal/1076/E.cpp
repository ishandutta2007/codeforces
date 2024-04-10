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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 3e5 + 5;

int n, q, dep[N], val[N];
long long a[N], b[N << 1];

vector<int> adj[N], qr[N];

void dfs(int u, int p, int d = 0, long long r = 0) {
	for (int id : qr[u])
		r += val[id], b[d + dep[id] + 1] += val[id];
	r -= b[d], a[u] = r;
	for (int v : adj[u])
		if (v != p) dfs(v, u, d + 1, r);
	for (int id : qr[u])
		b[d + dep[id] + 1] -= val[id];
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	cin >> q;
	for (int i = 1, u; i <= q; i++)
		cin >> u >> dep[i] >> val[i], qr[u].push_back(i), dep[i] = dep[i] > n ? n : dep[i];
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}