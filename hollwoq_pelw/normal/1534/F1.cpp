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

const int N = 4e5 + 5;

// n rows, m cols

int n, m; char a[N];

inline int comp(int x, int y) { return x * m + y; }
inline char val(int x, int y) { return a[comp(x, y)]; }

vector<int> adj[N], radj[N], ord, pos[N];
inline void addedge(int sx, int sy, int ex, int ey) {
	int u = comp(sx, sy), v = comp(ex, ey);
	adj[u].push_back(v), radj[v].push_back(u);
}

bool vis[N], ok[N];

void dfs(int u){ 
	vis[u] = 1;
	for (auto v : adj[u])
		if (!vis[v]) dfs(v);
	ord.push_back(u);
}

int scc[N], cnt;

void rdfs(int u) {
	scc[u] = cnt;
	for (auto v : radj[u])
		if (!scc[v]) rdfs(v);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) 
		cin >> a[i];

	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
			if (val(r, c) == '#')
				pos[c].push_back(r);

	for (int c = 0; c < m; c++) {
		for (int i = 1; i < pos[c].size(); i++) {
			addedge(pos[c][i - 1], c, pos[c][i], c);
			if (pos[c][i - 1] + 1 == pos[c][i])
				addedge(pos[c][i], c, pos[c][i - 1], c);
		}
		for (auto r : pos[c]) {
			for (int nc = c - 1; nc <= c + 1; nc += 2) {
				if (nc >= 0 && nc < m) {
					auto it = lower_bound(pos[nc].begin(), pos[nc].end(), r);
					if (it != pos[nc].end())
						addedge(r, c, *it, nc);
				}
			} 
		}
	}

	for (int i = 0; i < n * m; i++)
		if (!vis[i] && a[i] == '#') dfs(i);

	reverse(ord.begin(), ord.end());

	for (auto v : ord) if (!scc[v]) {
		++ cnt, rdfs(v);
	}

	memset(ok, 1, sizeof ok);

	for (int i = 0; i < n * m; i++) if (a[i] == '#') {
		// cout << i << ' ' << scc[i] << '\n';
		for (auto j : adj[i]) if (scc[i] != scc[j]) ok[scc[j]] = 0;
	}

	int res = 0;
	for (int i = 1; i <= cnt; i++)
		res += ok[i];

	cout << res << '\n';
}