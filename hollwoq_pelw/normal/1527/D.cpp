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
	cin >> testcases;
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

const int N = 2e5 + 5;

int n, res[N], sz[N], par[N], mark[N];
vector<int> adj[N];
 
void dfs(int u, int p){
    sz[u] = 1;
    par[u] = p;
    for (auto v : adj[u]) if (v != p){
        dfs(v, u);
        sz[u] += sz[v];
    }
}
 
void Hollwo_Pelw() {
    cin >> n;
    for (int i = 0; i <= n; i++)
        adj[i].clear(), mark[i] = res[i] = 0;
 
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v, ++ u, ++ v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
 
    dfs(1, 1);
    res[0] = res[1] = n * (n - 1) / 2;
    for (auto v : adj[1]){
        res[1] -= sz[v] * (sz[v] - 1) / 2;
    }
 
    mark[1] = 1;
 
    int s = 1, t = 1, tot = n;
    for (int i = 2; i <= n; i++){
        if (!mark[i]) {
            int u = i;
            while (!mark[u]) {
                mark[u] = 1;
                if (par[u] == 1)
                    tot -= sz[u];
                u = par[u];
            }
            if (u != s && u != t)
                break ;
            (s == u ? s = i : t = i);
        }
        res[i] = (s == 1 ? tot : sz[s]) * (t == 1 ? tot : sz[t]);
    }
    for (int i = 1; i <= n; i++)
        res[i - 1] -= res[i];
    for (int i = 0; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
}