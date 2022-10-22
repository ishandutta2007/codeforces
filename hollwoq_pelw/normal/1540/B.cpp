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

const int mod = 1e9 + 7, N = 220;

int binpow(int a, int x) {
    int r = 1;
    while (x) {
        if (x&1) r = r * a % mod;
        x >>= 1; a = a * a % mod;
    }
    return r;
}

int inv(int a) {
    return binpow(a, mod - 2);
}

int n, dep[N], ans, dp[N][N];
vector<int> adj[N];

vector<int> dfs(int u, int p = -1, int d = 0) {
    dep[u] = d;
    vector<int> res(1, u);
    for (int v : adj[u]) if (v != p) {
        vector<int> tmp = dfs(v, u, d + 1);
        for (auto x : res)
            for (auto y : tmp) {
                // cout << dep[x] - d << ' ' << dep[y] - d << endl;
                if (x > y)
                    ans = (ans + dp[dep[x] - d][dep[y] - d]) % mod;
                else 
                    ans = (ans + dp[dep[y] - d][dep[x] - d]) % mod;
            }
        for (auto x : tmp)
            res.push_back(x);
    }
    return res;
}

void Hollwo_Pelw() {
    int inv2 = inv(2);

    for (int i = 1; i < N; i++)
        dp[0][i] = 1, dp[i][0] = 0; // dp[i][j] => dist from max, min

    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * inv2 % mod;
        }
    }

	cin >> n;
    for (int i = 1, u, v; i < n; i++){
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	}

    for (int i = 1; i <= n; i++) dfs(i); 
    cout << ans * inv(n) % mod;
}