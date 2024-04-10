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

const int N = 14, inf = 2e9;

inline bool smin(int &a, int b){
	return a > b ? a = b, 1 : 0;
}

int n, m, adj[N][N];
int path[N][N][1 << N], dp[1 << N];
int tr[1 << N], ps[1 << N], pe[1 << N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++)
		cin >> u >> v, --u, --v, adj[u][v] = adj[v][u] = 1;

	memset(path, -1, sizeof path);

	for (int mask = 0; mask < 1 << n; mask++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mask >> i & 1) continue ;
				if (mask >> j & 1) continue ;
				if (__builtin_popcount(mask) == 1 && i == j) continue ;

				if ((i == j || adj[i][j]) && !mask) {
					path[i][j][mask] = i;
				} else {
					for (int k = 0; k < n; k++) {
						if ((mask >> k & 1) && path[i][k][mask ^ (1 << k)] >= 0 && adj[k][j]) {
							path[i][j][mask] = k; break ;
						}
					}
				}
				// cout << i << ' ' << j << ' ' << mask << ' ' << path[i][j][mask] << '\n';
			}
		}
	}

	for (int mask = 1; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) == 1) {
			dp[mask] = 0;
		} else {
			dp[mask] = inf;
			for (int sub = mask; sub; sub = (sub - 1) & mask) {
				int nmask = mask ^ sub;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if ((nmask >> i & 1) && (nmask >> j & 1) && path[i][j][sub] >= 0) {
							if (smin(dp[mask], dp[nmask] + __builtin_popcount(sub) + 1))
								tr[mask] = sub, ps[mask] = i, pe[mask] = j;
						}
					}
				}
			}
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	int cur = (1 << n) - 1;
	while (__builtin_popcount(cur) > 1){
		int nxt = tr[cur], i = ps[cur], j = pe[cur];
		cur ^= tr[cur];
		do {
			int k = path[i][j][nxt];
			cout << k + 1 << ' ' << j + 1 << '\n';
			nxt ^= 1 << k, j = k;
		} while (i != j);
	} 
}