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

const int N = 2020;

int n, m, sz[N], l[N], r[N], dp[N];
vector<int> adj[N];

vector<pair<int, int>> rg[N];

void dfs(int u){
    sz[u] = u != 1;
    for (int v : adj[u]) {
        dfs(v);
        l[u] = min(l[u], l[v]);
        r[u] = max(r[u], r[v]);
        sz[u] += sz[v];
    }
    rg[r[u]].emplace_back(l[u], sz[u]);
}

void __pre_process__ () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear(), l[i] = n, r[i] = 1;
    for (int i = 2, p; i <= n; i++)
        cin >> p, adj[p].push_back(i);
    for (int i = 1, x; i <= m; i++)
        cin >> x, l[x] = r[x] = i;
    dfs(1);
}

void Hollwo_Pelw() {
    cin >> m;
    __pre_process__();
    __pre_process__();   
    for (int i = 1; i <= m; i++){
        for (auto vw : rg[i]){
            dp[i] = max(dp[i], dp[vw.first - 1] + vw.second);
        }
    }
    cout << dp[m];
}