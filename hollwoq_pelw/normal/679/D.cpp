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

const int N = 404, inf = 1e9;

int n, m, d[N][N], ok[N];
vector<int> adj[N];

double prob0[N], maxprob[N];
// prob0[i] => probably of Limak in i after first choose
// maxprob[i] => maximum if after second turn, dist to Limak = i

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) d[i][j] = i == j ? 0 : inf;
	for (int u, v; m --; ) {
		cin >> u >> v, d[u][v] = d[v][u] = 1;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= n; j++)
	// 		cout << d[i][j] << " \n"[j == n];

	double res = 0;
	for (int choose0 = 1; choose0 <= n; choose0 ++) {
		double max_cur = 0;
		for (int dist = 0; dist <= n; dist++) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) prob0[i] = 0;
			for (int i = 1; i <= n; i++) if (d[choose0][i] == dist) {
				++ cnt;
				for (auto v : adj[i])
					prob0[v] += 1.0 / adj[i].size();
			}
			if (!cnt) continue ; // cannot be response this
			
			vector<int> pos;

			for (int i = 1; i <= n; i++)
				if (prob0[i] > 0) pos.push_back(i);

			double best = 1; // if lucky ???
			for (int choose1 = 1; choose1 <= n; choose1 ++) {
				double cur = 0;
				for (auto v : pos) 
					maxprob[d[choose1][v]] = 0, ok[d[choose1][v]] = 1;
				for (auto v : pos)
					maxprob[d[choose1][v]] = max(maxprob[d[choose1][v]], prob0[v]);
				for (auto v : pos) if (ok[d[choose1][v]])
					cur += maxprob[d[choose1][v]], ok[d[choose1][v]] = 0;
				best = max(cur, best);
			}
			// cout << dist << ' ' << best << '\n';
			max_cur += best;
		}
		res = max(res, max_cur / n);
	}
	cout << fixed << setprecision(9) << res;
}