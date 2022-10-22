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

#define int long long

const int N = 1e5 + 5;

int n, m, h, a[N];

vector<int> adj[N], radj[N], ord;

inline void addedge(int u, int v) {
	if (a[u] == (a[v] + 1) % h)
		radj[u].push_back(v), adj[v].push_back(u);
}

bool vis[N], out[N];

void dfs(int u) {
	vis[u] = 1;
	for (auto v : adj[u])
		if (!vis[v]) dfs(v);
	ord.push_back(u);
}

int comp[N], compsz[N], comp_cnt;

void rdfs(int u, int c) {
	comp[u] = c, compsz[c] ++;
	vis[u] = 1;
	for (auto v : radj[u])
		if (!vis[v]) rdfs(v, c);
}

void Hollwo_Pelw() {
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, addedge(u, v), addedge(v, u);
	for (int i = 1; i <= n; i++) 
		if (!vis[i]) dfs(i);
	reverse(ord.begin(), ord.end());
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	for (auto u : ord) if (!vis[u])
		rdfs(u, ++ comp_cnt);
	for (int i = 1; i <= n; i++)
		for (auto v : adj[i])
			if (comp[i] != comp[v]) out[comp[i]] = 1;
	int res = 1e9, ans = 0;
	for (int i = 1; i <= comp_cnt; i++) if (!out[i])
		if (res > compsz[i]) res = compsz[i], ans = i;
	cout << res << '\n';
	for (int i = 1; i <= n; i++)
		if (comp[i] == ans) cout << i << ' ';
}