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

const int N = 3e5 + 5;

int par[N][19], tot[N], cost[N], q;

void build(int id) {
	cin >> tot[id] >> cost[id];
	for (int i = 1; i <= 18; i++)
		par[id][i] = par[par[id][i - 1]][i - 1];
}

void Hollwo_Pelw() {
	cin >> q;
	build(1);
	for (int i = 2, type, v, w; i <= q + 1; i++){
		cin >> type;
		if (type == 1) {
			cin >> par[i][0]; ++ par[i][0]; build(i);
		} else {
			cin >> v >> w; ++ v;
			int ans = 0; int64_t res = 0;
			while (w && tot[v]) {
				int u = v;
				for (int i = 18; i >= 0; i--)
				if (tot[par[u][i]]) u = par[u][i];
				int used = min(w, tot[u]);
				w -= used, tot[u] -= used; 
				ans += used, res += 1ll * used * cost[u];
			}
			cout << ans << ' ' << res << endl;
		}
	}
}